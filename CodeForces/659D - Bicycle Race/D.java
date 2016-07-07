import java.util.*;
import java.io.*;

public class D{
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int n, a, b, c, d, e, f, cnt=0;
	
	String line[] = br.readLine().split(" ");
	n = Integer.parseInt(line[0]);
	
	line = br.readLine().split(" ");
	a = Integer.parseInt(line[0]);
	b = Integer.parseInt(line[1]);

	line = br.readLine().split(" ");
	c = Integer.parseInt(line[0]);
	d = Integer.parseInt(line[1]);

	n-=2;
	while(n-->0){
	    line = br.readLine().split(" ");
	    e = Integer.parseInt(line[0]);
	    f = Integer.parseInt(line[1]);

	    int cpz = (c-a)*(f-d)-(d-b)*(e-c);

	    if( cpz > 0 )
		cnt++;

	    a=c; b=d;
	    c=e; d=f;
	}

	out.println(cnt);
	
	out.close();
    }
}

// AC
