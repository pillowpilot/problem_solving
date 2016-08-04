import java.io.*;
import java.util.*;

public class A{
    public static void main(String[] a) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int n = Integer.parseInt( in.readLine() );
	int i = n + 1;
	while( !f(i))
	    i++;

	out.println(i);
	
	out.close();
    }
    public static boolean f(int n){
	int d[] = new int[10];
	Arrays.fill(d, 0);

	while( n != 0 ){
	    d[n%10]++;
	    n = n / 10;
	}

	int i = 0;
	while( i < 10 && d[i] < 2)
	    i++;
	return i == 10;
    }
}
// AC
