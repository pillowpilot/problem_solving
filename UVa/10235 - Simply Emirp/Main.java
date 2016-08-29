import java.math.*;
import java.io.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] a ) throws IOException{
	String line;
	line = in.readLine();
	while( line != null && line.length() != 0 ){
	    BigInteger n = new BigInteger(line);
	    BigInteger nr = new BigInteger(new StringBuilder(line).reverse().toString());

	    int cert = 50;
	    if( n.isProbablePrime(cert) ){
		if( nr.isProbablePrime(cert) && n.compareTo(nr) != 0){ // n and nr must be diferent primes..!!
		    out.println(n + " is emirp.");
		}else{
		    out.println(n + " is prime.");
		}
	    }else{
		out.println(n + " is not prime.");
	    }
	    
	    line = in.readLine();
	}
	out.close();
    }
}

// AC
