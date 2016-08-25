import java.io.*;
import java.util.*;
import java.math.*;

/*
  Turns out that the sequence is the fibo sequence... 
 */

public class Main{
    static BigDecimal memoc[];
    static BigDecimal memob[];

    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	build();

	String line = in.readLine();
	while( line != null ){
	    int n = Integer.parseInt(line);

	    BigDecimal ans = memoc[n];

	    out.println(ans);
	    
	    line = in.readLine();
	}

	out.close();
    }

    private static void build(){
	memoc = new BigDecimal[1010];
	memob = new BigDecimal[1010];

	for(int i = 0; i < 1010; i++){
	    memoc[i] = null;
	    memob[i] = null;
	}

	c(1000);
	c(999);
    }

    private static BigDecimal c(int n){
	if( memoc[n] != null )
	    return memoc[n];

	BigDecimal ans;
	if( n == 0 )
	    ans = new BigDecimal("1");
	else if( n == 1 )
	    ans = new BigDecimal("2");
	else
	    ans = c(n-2).add( b(n-1) );

	memoc[n] = ans;
	return ans;
    }

    private static BigDecimal b(int n){
	if( memob[n] != null )
	    return memob[n];

	BigDecimal ans;
	if( n == 0 )
	    ans = new BigDecimal("1");
	else if( n == 1 )
	    ans = new BigDecimal("2");
	else
	    ans = c(n-1).add( b(n-2) );

	memob[n] = ans;
	return ans;
    }
}

// AC
