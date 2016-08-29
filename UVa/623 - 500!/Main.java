import java.io.*;
import java.math.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static BigInteger fac[] = new BigInteger[1001];

    public static void main(String[] args) throws IOException{
	init();
	String line = in.readLine();

	while( line != null && line.length() != 0 ){
	    int f = Integer.parseInt( line );

	    out.println(f+"!");
	    out.println(fac[f]);
	    
	    line = in.readLine();
	}
	
	out.close();
    }

    private static void init(){
	fac[0] = BigInteger.ONE;

	for(int i = 1; i < fac.length; i++)
	    fac[i] = fac[i-1].multiply( BigInteger.valueOf(i) );
	
    }
}
// AC
