import java.util.Scanner;
import java.lang.Math.*;

public class A{
    public static int f(int i, int j){
	return ( (i>3)?i-3:3-i ) + ( (j>3)?j-3:3-j );
    }
    
    public static void main(String[] args){
	Scanner in = new Scanner(System.in);

	int d, c = 0, x;
	do{
	    x = in.nextInt();
	    d = f(c/5+1, (c%5)+1);
	    c++;
	}while( x == 0 );

	System.out.println( d );
    }
}

// AC
