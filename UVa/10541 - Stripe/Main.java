import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    private static BigInteger memo[][] = new BigInteger[222][222];

    public static void main(String[] args) throws IOException{
	init();
	String line;
	line = in.readLine();
	int tests = Integer.parseInt(line);
	while( tests-- > 0 ){
	    line = in.readLine();
	    String[] toks = line.split(" ");
	    int n = Integer.parseInt(toks[0]);
	    int k = Integer.parseInt(toks[1]);

	    int A = 0;
	    for(int i = 0; i < k; i++){
		int x = Integer.parseInt(toks[2+i]);
		A += x + 1;
	    }
	    A--;

	    /*out.println( ">> " );
	    out.println( n-A+k );
	    out.println( k );
	    out.flush();*/
	    BigInteger ans = binomial( n - A + k, k );

	    out.println(ans);
	}
	out.close();
    }

    private static BigInteger binomial(int n, int k){
	if( n < k || n < 0 || k < 0 )
	    return new BigInteger("0");
	
	if( memo[n][k] != null )
	    return memo[n][k];

	BigInteger ans = null;
	if( k == 0 || n == k )
	    ans = new BigInteger("1");
	else
	    ans = binomial(n-1, k).add( binomial(n-1, k-1) );

	memo[n][k] = ans;
	return ans;
    }

    private static void init(){
	for(int i = 0; i < memo.length; i++){
	    for(int j = 0; j <= i; j++){
		memo[i][j] = null;
	    }
	}
    }
}

// AC
