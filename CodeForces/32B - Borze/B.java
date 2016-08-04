import java.io.*;
import java.util.*;

public class B{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	String s = in.readLine();

	int i = 0;
	while( i < s.length() ){
	    if( s.charAt(i) == '.' ){
		out.print(0);
	    }else{
		i++;
		if( s.charAt(i) == '.' ){
		    out.print(1);
		}else{
		    out.print(2);
		}
	    }
	    
	    i++;
	}


	out.println();
	out.close();
    }
}

// AC
