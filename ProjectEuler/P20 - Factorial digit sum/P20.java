import java.math.BigInteger;

public class P20{
    public static void main(String[] args){
	final int limit = 100;
	
	BigInteger f = new BigInteger("1");
	for(int i = 2; i <= limit; i++)
	    f = f.multiply( new BigInteger( "" + i ) );

	String fs = f.toString();
	int sum = 0;
	for(int i = 0; i < fs.length(); i++)
	    sum += Integer.parseInt( "" + fs.charAt(i) );

	System.out.println(fs);
	System.out.println(sum);
    }
}

// AC
