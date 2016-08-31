import java.math.*;

public class P25{
    public static void main(String[] args){
	int digits = 1000;

	int index = 2;
	BigInteger a, b;
	a = b = BigInteger.ONE;
	while( b.toString().length() != digits ){
	    BigInteger t = a.add(b);
	    a = b;
	    b = t;
	    index++;
	}
	System.out.println(b);
	System.out.println(index);
    }
}

// AC ans=4782
