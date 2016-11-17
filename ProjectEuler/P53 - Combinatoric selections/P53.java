import java.io.*;
import java.math.*;

public class P53{
    public static void main(String[] args){

	int ans = 0;
	BigInteger limit = new BigInteger("" + 1000000);
	for(int n = 0; n <= 100; n++){
	    for(int r = 0; r <= n; r++){
		BigInteger bc = binomial(n, r);
		if( bc.compareTo(limit) >= 0 )
		    ans++;
	    }	   
	}

	System.out.println(ans);

	System.out.println("DEBUG: 100C51=" + binomial(100, 51));
    }

    public static BigInteger factorial(int n){
	BigInteger ans = BigInteger.ONE;

	while( n > 0 ){
	    ans = ans.multiply( new BigInteger(""+n) );
	    n--;
	}

	return ans;
    }

    public static BigInteger binomial(int n, int r){
	return factorial(n).divide( factorial(r).multiply(factorial(n-r)) );
    }
}
    

// AC ans = 4075
