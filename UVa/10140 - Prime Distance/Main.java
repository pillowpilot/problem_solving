import java.io.*;
import java.math.*;

public class Main{
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) throws IOException{
	String line;
	int cert = 11;

	line = in.readLine();
	while( line != null ){
	    String[] tks = line.split(" ");
	    BigInteger l = new BigInteger(tks[0]);
	    BigInteger u = new BigInteger(tks[1]);

	    BigInteger i = l;
	    while( !i.isProbablePrime(cert) && i.compareTo(u) <= 0 )
		i = i.add(BigInteger.ONE);

	    BigInteger j = i;
	    j = j.add(BigInteger.ONE);
	    while( !j.isProbablePrime(cert) && j.compareTo(u) <= 0 )
		j = j.add(BigInteger.ONE);

	    if( i.compareTo(u) <= 0 && j.compareTo(u) <= 0 ){
		BigInteger c1, c2; int cd = j.add( i.negate() ).intValue();
		BigInteger d1, d2; int dd = j.add( i.negate() ).intValue();

		c1 = i;
		c2 = j;
		d1 = i;
		d2 = j;

		BigInteger k = j.add(BigInteger.ONE);
		while( k.compareTo(u) <= 0 ){
		    if( k.isProbablePrime(cert) ){
			i = j;
			j = k;

			if( cd > j.add( i.negate() ).intValue() ){
			    c1 = i;
			    c2 = j;
			    cd = j.add( i.negate() ).intValue();
			}
			
			if( dd < j.add( i.negate() ).intValue() ){
			    d1 = i;
			    d2 = j;
			    dd = j.add( i.negate() ).intValue();
			}
		    }
		    k = k.add( BigInteger.ONE );
		}

		out.print("" + c1 + "," + c2 + " are closest, ");
		out.println("" + d1 + "," + d2 + " are most distant.");
		//out.flush();
	    }else{
		out.println("There are no adjacent primes.");
	    }
	    
	    line = in.readLine();
	}
	
	out.close();
    }
}

// TLE (not submitted but too slow for u-l = 1e6 )
