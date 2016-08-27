import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    private static BigInteger dp[][] = new BigInteger[55][55];

    public static void main(String[] a) throws IOException{
	init();
	String line;
	line = in.readLine();
	int tests = Integer.parseInt(line);

	
	for(int test = 1; test <= tests; test++){
	    line = in.readLine();
	    String[] toks = line.split("\\(|\\+|\\)|\\^");

	    int k = Integer.parseInt(toks[4]);
	    String x = toks[1];
	    String y = toks[2];

	    out.print("Case " + test + ": ");
	    for(int i = 0; i <= k; i++){
		BigInteger coef = binomial(k, i);
		int xp = k-i;
		int yp = i;
		
		String cformat;
		if( coef.compareTo(BigInteger.ONE) == 0 )
		    cformat = "";
		else
		    cformat = coef.toString() + "*";

		String xformat;
		if( xp == 0 )
		    xformat = "";
		else if( xp == 1 )
		    xformat = x;
		else
		    xformat = x + "^" + xp;

		if( yp != 0 && xp != 0)
		    xformat = xformat + "*";

		String yformat;
		if( yp == 0 )
		    yformat = "";
		else if( yp == 1 )
		    yformat = y;
		else
		    yformat = y + "^" + yp;

		out.print(cformat + xformat + yformat);
		if( i != k )
		    out.print("+");
	    }
	    out.println();
	}
	
	out.close();
    }

    private static void init(){
	for(int i = 0;i < dp.length; i++)
	    for(int j = 0; j < dp[i].length; j++)
		dp[i][j] = null;
    }

    private static BigInteger binomial(int n, int k){
	if( dp[n][k] != null )
	    return dp[n][k];

	BigInteger ans;
	if( k == 0 || n == k )
	    ans = new BigInteger("1");
	else
	    ans = binomial(n-1, k-1).add( binomial(n-1, k) );

	dp[n][k] = ans;
	return ans;
    }
      
}
// AC
