import java.io.*;
import java.util.*;

public class A{
    public static boolean isV(int i, int j){
	return (0<=i && 0<=j && i< 3 && j<3);
    }
    public static void main(String[] ar) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	int m[][] = new int[3][3];

	for(int i = 0; i < 3; i++){
	    String line[] = in.readLine().split(" ");
	    for(int j=0; j < 3; j++){
		m[i][j] = Integer.parseInt(line[j]);
	    }
	}

	int offr[] = {-1, 0, 0, 0, 1};
	int offc[] = {0, -1, 0, 1, 0};

	for(int i = 0; i < 3; i++){
	    for(int j=0; j < 3; j++){
		int s=0;
		for(int k = 0;k<offr.length; k++){
		    if( isV(i+offr[k], j+offc[k])){
			s+=m[i+offr[k]][j+offc[k]];
		    }
		}
		if( s % 2 == 0 ){
		    out.print(1);
		}else{
		    out.print(0);
		}
	    }
	    out.println();
	}

	out.close();
    }
}

// AC
/*
  Notice that the sum of the SIDE-ADJACENT cells.
  If 2|sum, then the final state must be equal to the initial state. Therefore 1.
  Else 0.
 */
