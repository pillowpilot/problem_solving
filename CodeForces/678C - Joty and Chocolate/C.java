import java.util.*;
import java.io.*;
import java.math.*;

public class C{
    public static long gcd(long a, long b){
	if(a<b){
	    long t = a;
	    a = b;
	    b = t;
	}
	if(b==0)return a;
	return gcd(b, a%b);
	
    }
    public static long lcm(long a, long b){
	return a/gcd(a, b)*b;
    }
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String line[] = br.readLine().split(" ");

	long n = Long.parseLong(line[0]);
	long a = Long.parseLong(line[1]);
	long b = Long.parseLong(line[2]);
	long p = Long.parseLong(line[3]);
	long q = Long.parseLong(line[4]);

	long C = n/lcm(a, b);
	long A = n/a - C;
	long B = n/b - C;

	long ans = A*p + B*q + C*Math.max(p, q);

	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	out.println(ans);
	out.close();
    }
}

// AC
