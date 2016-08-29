import java.io.*;
import java.math.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static BigInteger fac[] = new BigInteger[400];

    public static void main(String[] args) throws IOException{
	init();

	String line = in.readLine();
	int n = Integer.parseInt(line);
	while( line != null && n != 0 ){

	    String decrep = "" + fac[n];

	    int frec[] = new int[10];
	    
	    for(int i = 0; i < decrep.length(); i++){
		char c = decrep.charAt(i);
		frec[c-'0']++;
	    }

	    out.println(n +"! --");
	    out.print(String.format("   (%1$d)%2$ 5d", 0, frec[0]));
	    for(int i = 1; i < 5; i++)
		out.print(String.format("    (%1$d)%2$ 5d", i, frec[i]));
	    out.println();

	    out.print(String.format("   (%1$d)%2$ 5d", 5, frec[5]));
	    for(int i = 6; i < 10; i++)
		out.print(String.format("    (%1$d)%2$ 5d", i, frec[i]));
	    out.println();
	    
	    line = in.readLine();
	    n = Integer.parseInt(line);
	}
	
	out.close();
    }

    private static void init(){
	fac[0] = BigInteger.ONE;
	for(int i = 1; i  < fac.length; i++)
	    fac[i] = fac[i-1].multiply( BigInteger.valueOf(i) );
    }
}

// AC
