import java.util.*;
import java.io.*;

public class A{
    public static void main(String[] args) throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String[] line;
	
	int n, d;

	line = br.readLine().split(" ");
	n = Integer.parseInt(line[0]);
	d = Integer.parseInt(line[1]);

	String[] sch = new String[d];

	for(int i = 0 ; i < d; i++){
	    sch[i] = br.readLine();
	}

	StringBuilder sb = new StringBuilder();
	while( n-- > 0 ){
	    sb.append('1');
	}
	n = Integer.parseInt(line[0]);

	String loseDay = sb.toString();

	int[] wins = new int[d];
	wins[0] = ( sch[0].equals(loseDay) != true )?1:0;
	for(int i = 1; i < d; i++){
	    if( !sch[i].equals(loseDay) ){
		wins[i] = wins[i-1] + 1;
	    }else{
		wins[i] = 0;
	    }
	}

	int max = 0;
	for(int i = 0; i < d; i++){
	    if( max < wins[i] )
		max = wins[i];
	}

	System.out.println(max);
    }
}

// AC
