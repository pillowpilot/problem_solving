import java.util.*;
import java.math.*;
import java.io.*;

public class P29{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int alimit, blimit;
	alimit = blimit = 100;

	HashSet<BigInteger> set = new HashSet<BigInteger>();
	for(int a = 2; a <= alimit; a++){
	    BigInteger p = new BigInteger(""+a);
	    for(int b = 2; b <= blimit; b++){
		p = p.multiply(new BigInteger(""+a));

		set.add(p);
	    }
	}

	out.println(set.size());

	out.close();
    }
}

// AC ans = 9183
