import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	BigInteger two = new BigInteger("2");
	BigInteger three = new BigInteger("3");
	BigInteger x, y, ans, cur, limit = power(2, 32);

	String line = in.readLine();
	BigInteger n = new BigInteger(line);
	while( n.compareTo(BigInteger.ZERO) != 0 ){

	    ans = power(10, 15); // INF
	    x = BigInteger.ONE;
	    for(int a = 0; a <= 31; a++){
		y = BigInteger.ONE;
		for(int b = 0; b <= 21; b++){

		    cur = x.multiply(y);
		    if( cur.compareTo(limit) > 0 )
			break;
		    
		    if( n.compareTo(cur) <= 0 && cur.compareTo(ans) < 0 ){
			ans = cur;
		    }
		    y = y.multiply( three );
		}
		x = x.multiply( two );
	    }
	    out.println(ans);

	    line = in.readLine();
	    n = new BigInteger(line);
	}
	
	out.close();
    }
    public static BigInteger power(int base, int exp){
	if( exp == 0 ) return BigInteger.ONE;

	BigInteger p = BigInteger.ONE;
	if( exp % 2 != 0 ){
	    p = new BigInteger("" + base);
	    exp--;
	}

	BigInteger t = power(base, exp/2);
	p = p.multiply( t.multiply(t) );
	return p;
    }
}

// AC
/*
  Both inner loops can be extracted to improve speed
 */
