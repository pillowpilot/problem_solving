import java.util.*;
import java.io.*;

public class C{
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int n, k;
	String line[] = br.readLine().split(" ");
	n = Integer.parseInt(line[0]);
	k = Integer.parseInt(line[1]);

	if( 2*k + 1 <= n ){
	    out.print("" + (k*n) + '\n');
	    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
		    if( i + j > n ){
			out.print("" + i + " " + (i + j - n) + '\n');
		    }else{
			out.print("" + i + " " + (i + j) + '\n');
		    }
		}
	    }
	}else{
	    System.out.println(-1);
	}

	out.close();
    }
}

// AC
