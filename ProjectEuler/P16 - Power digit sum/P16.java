import java.math.BigInteger;

public class P16{
    public static void main(String[] args){
	int exp = 1000;
	BigInteger power = new BigInteger("1");
	while( exp > 0 ){
	    power = power.add( power );
	    exp--;
	}
	int sum = 0;
	for(int i = 0; i < power.toString().length(); i++){
	    sum += Integer.parseInt("" + power.toString().charAt(i));
	}
	System.out.println(power);
	System.out.println(sum);
    }
}


// AC
