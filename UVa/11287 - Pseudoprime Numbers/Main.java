import java.math.*;
import java.io.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    static BigInteger p, a;

    public static void main(String[] args) throws IOException{
	String line;

	read();
	while( a.compareTo(BigInteger.ZERO) != 0 &&
	       p.compareTo(BigInteger.ZERO) != 0 ){

	    if( !p.isProbablePrime(50) ){
		BigInteger power = a.modPow(p, p);

		if( power.compareTo(a) == 0 )
		    out.println("yes");
		else
		    out.println("no");
	    }else{
		out.println("no");
	    }
	    read();
	}
	      	
	
	out.close();
    }
    public static void read()throws IOException{
	String line = in.readLine();
	String[] tks = line.split(" ");
	p = new BigInteger(tks[0]);
	a = new BigInteger(tks[1]);
    }
}

// AC
