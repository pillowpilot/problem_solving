import java.math.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
	int n, t;
	Scanner scanner = new Scanner(System.in);
	n = scanner.nextInt();
	t = scanner.nextInt();

	BigInteger s = new BigInteger("1");
	for(int i = 1; i < n; i++ ){
	    s = s.multiply( new BigInteger("10") );
	}
	
	//System.out.println( s );

	int a = 0;
	while( !s.add( new BigInteger("" + a) ).remainder( new BigInteger("" + t) ).equals( BigInteger.ZERO ) ){
	    a++;
	}
	if( s.add( new BigInteger(""+a) ).toString().length() != n ) System.out.println( "-1" );
	else System.out.println( s.add( new BigInteger("" + a) ));
    }
}
