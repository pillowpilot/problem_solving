import java.io.*;
import java.math.*;

public class Main{
    static BufferedReader in = new BufferedReader( new InputStreamReader(System.in) );
    static PrintWriter out = new PrintWriter( new BufferedOutputStream( System.out ));
    static BigInteger fac[] = new BigInteger[21];

    public static void main(String[] args) throws IOException{
	init();
	String line = in.readLine();

	int n = Integer.parseInt(line);
	for(int dataset = 1; dataset <= n; dataset++){
	    line = in.readLine();

	    int frec[] = new int['Z' - 'A'];
	    for(int i = 0; i < line.length(); i++){
		char c = line.charAt(i);
		frec[c-'A']++;
	    }

	    BigInteger ans = fac[line.length()]; // line.length() <= 20
	    // however lg(20!) approx 61
	    for(int f: frec){
		ans = ans.divide( fac[f] );
	    }

	    out.println(String.format("Data set %d: " + ans, dataset));
	}
	
	out.close();
    }

    private static void init(){
	fac[0] = BigInteger.ONE;
	for(int i = 1; i < fac.length; i++)
	    fac[i] = fac[i-1].multiply( new BigInteger(""+i) );
    }
}
// AC
