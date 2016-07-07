import java.util.*;
import java.io.*;

public class A{
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
	String line[] = br.readLine().split(" ");
	int n, m;

	n = Integer.parseInt(line[0]);
	m = Integer.parseInt(line[1]);

	long a[] = {0, 0, 0, 0, 0};
	long b[] = {0, 0, 0, 0, 0};
	
	for(int i = 1; i <= n; i++){
	    a[ i%5 ]++;
	}

	for(int i = 1; i <= m; i++){
	    b[ i%5 ]++;
	}

	long s = 0;
	s += a[0]*b[0];
	s += a[1]*b[4];
	s += a[2]*b[3];
	s += a[3]*b[2];
	s += a[4]*b[1];

	System.out.println(s);
    }
}

// AC
