import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    private static final int M = 333;
    private static BigInteger fac[] = new BigInteger[2*M];
    private static BigInteger catalan[] = new BigInteger[M];
    private static BigInteger f[] = new BigInteger[M];
    
    public static void main(String[] a) throws IOException{
	init();

	String line;
	line = in.readLine();
	int x = Integer.parseInt(line);
	while( x != 0 ){
	    out.println(f[x]);
	    
	    line = in.readLine();
	    x = Integer.parseInt(line);
	}
	
	out.close();
    }

    private static void init(){
	fac[0] = BigInteger.ONE;
	for(int i = 1; i < fac.length; i++)
	    fac[i] = fac[i-1].multiply( new BigInteger("" + i) );

	for(int i = 0; i < catalan.length; i++)
	    catalan[i] = fac[2*i].divide( fac[i].multiply(fac[i+1]) );

	for(int i = 0; i < f.length; i++)
	    f[i] = catalan[i].multiply( fac[i] );
    }
    
}
// AC
