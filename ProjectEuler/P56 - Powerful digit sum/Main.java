import java.math.*;

public class Main{
    public static void main(String[] args){
	int max_sum = 0;
	for(int b = 1; b < 100; b++){
	    for(int e = 1; e < 100; e++){
		BigInteger p = BigInteger.valueOf(b).pow(e);
		String pstr = p.toString();

		int sum = 0;
		for(int i = 0; i < pstr.length(); i++){
		    sum += pstr.charAt(i) - '0';
		}

		if( sum > max_sum )
		    max_sum = sum;
	    }
	}
	System.out.println(max_sum);
    }
}

// AC
