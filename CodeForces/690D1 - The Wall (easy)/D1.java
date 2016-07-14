import java.util.*;
import java.io.*;

public class D1{
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	String[] line = br.readLine().split(" ");
	int r = Integer.parseInt(line[0]);
	int c = Integer.parseInt(line[1]);

	while( r-- > 1 ){
	    br.readLine();
	}

	String l = br.readLine();

	int cnt = 0;
	int i = 0;
	while( i < l.length() ){
	    if( l.charAt(i) == 'B' ){
		cnt++;
		while( i < l.length() && l.charAt(i) == 'B' )
		    i++;
	    }else{
		while( i < l.length() && l.charAt(i) == '.' )
		    i++;
	    }
	}

	out.println(cnt);

	out.close();
    }
}
    
// AC
