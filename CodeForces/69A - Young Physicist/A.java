import java.io.*;
import java.util.*;

public class A{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int n = Integer.parseInt(in.readLine());
	int a, b, c;
	a = b = c = 0;
	while( n-- > 0 ){
	    String[] data = in.readLine().split(" ");
	    int x = Integer.parseInt(data[0]);
	    int y = Integer.parseInt(data[1]);
	    int z = Integer.parseInt(data[2]);
	    a += x;
	    b += y;
	    c += z;
	}

	if( a == 0 && b == 0 && c == 0 ){
	    out.println("YES");
	}else{
	    out.println("NO");
	}

	out.close();
    }
}

// AC
