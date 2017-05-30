import java.util.*;
import java.io.*;
import java.math.*;

class Main{
    public static void main(String[] args) throws IOException{
	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));

	String line = input.readLine();
	int n = Integer.parseInt(line);

	while( n-- > 0 ){
	    String[] data = input.readLine().split(" ");
	    int dataset = Integer.parseInt(data[0]);
	    int base = Integer.parseInt(data[1]);
	    BigInteger a = new BigInteger(data[2], base);
	    BigInteger r = a.remainder(new BigInteger(""+(base-1)));
	    
	    output.println(dataset+" "+r);
	}

	output.close();
    }
    
}
