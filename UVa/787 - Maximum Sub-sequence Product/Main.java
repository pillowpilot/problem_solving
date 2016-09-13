import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static Vector<Integer> tks;
    static int index;
    
    public static void main(String[] args) throws IOException{
	init();
	Vector<Integer> nn = new Vector<Integer>();
	
	index = 0;
	while( index < tks.size() ){
	    nn.clear();
	    while( tks.get(index) != -999999 ){
		nn.add( tks.get(index) );
		index++;
	    }
	    index++;
	    
	    BigInteger maxp = BigInteger.valueOf( nn.get(0) ); // atleast one element
	    for(int i = 0; i < nn.size(); i++){
		BigInteger p = BigInteger.ONE;
		for(int j = i; j < nn.size(); j++){
		    p = p.multiply( BigInteger.valueOf( nn.get(j) ) );
		    if( p.compareTo(maxp) > 0 )
			maxp = p;
		}
	    }

	    out.println(maxp);
	}
	out.close();
    }
    private static void init() throws IOException{
	StringBuilder sb = new StringBuilder();
	String line = in.readLine();
	while( line != null ){
	    sb.append(" ");
	    sb.append(line);
	    line = in.readLine();
	}
	line = sb.toString();

	tks = new Vector<Integer>();
	String[] ss = line.split(" ");

	Scanner scanner = new Scanner(line);
	while( scanner.hasNextInt() )
	    tks.add( scanner.nextInt() );
	
    }
}

// AC
