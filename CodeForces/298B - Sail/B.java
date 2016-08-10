import java.io.*;
import java.util.*;

public class B{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	String[] line = in.readLine().split(" ");
	int sx = Integer.parseInt(line[1]);
	int sy = Integer.parseInt(line[2]);
	int ex = Integer.parseInt(line[3]);
	int ey = Integer.parseInt(line[4]);
	ex -= sx;
	ey -= sy;

	String wind = in.readLine();
	int i = 0;
	int d = abs(ex) + abs(ey);
	while( i < wind.length() && d != 0 ){
	    if( wind.charAt(i) == 'N' && abs(ex) + abs(ey-1) < d )
		ey -= 1;
	    if( wind.charAt(i) == 'S' && abs(ex) + abs(ey+1) < d )
		ey += 1;
	    if( wind.charAt(i) == 'W' && abs(ex+1) + abs(ey) < d )
		ex += 1;
	    if( wind.charAt(i) == 'E' && abs(ex-1) + abs(ey) < d )
		ex -= 1;

	    d = abs(ey) + abs(ex);
	    i++;
	}

	if( d == 0 ){
	    out.println(i);
	}else{
	    out.println(-1);
	}
	
	out.close();
    }

    public static int abs(int n){
	return (n<0)?-n:n;
    }
}

// AC
