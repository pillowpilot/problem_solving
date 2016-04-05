import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);
	BigInteger bigInteger;
	String string;

	string = scanner.next();
	bigInteger = new BigInteger(string);

	if( bigInteger.compareTo(new BigInteger("-129")) == 1 && bigInteger.compareTo(new BigInteger("128")) == -1 ){
	    System.out.println("byte");
	}else if( bigInteger.compareTo(new BigInteger("-32769")) == 1 && bigInteger.compareTo(new BigInteger("32768")) == -1 ){
	    System.out.println("short");
	}else if( bigInteger.compareTo(new BigInteger("-2147483649")) == 1 && bigInteger.compareTo(new BigInteger("2147483648")) == -1 ){
	    System.out.println("int");
	}else if( bigInteger.compareTo(new BigInteger("-9223372036854775809")) == 1
		  && bigInteger.compareTo(new BigInteger("9223372036854775808")) == -1 ){
	    System.out.println("long");
	}else{
	    System.out.println("BigInteger");
	}

    }
}

// AC
