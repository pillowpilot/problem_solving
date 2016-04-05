import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;

class Main{
    public static void main(String args[]){
	Scanner scanner = new Scanner( System.in );
	BigInteger acc = new BigInteger("0");
	String s;

	s = scanner.nextLine();
	while( !s.equals("0") ){ // Use .equals for string comparison. != compares references.
	    acc = acc.add( new BigInteger(s) ); // BigInteger is inmutable!
	    s = scanner.nextLine();
	}

	System.out.println( acc );
	
    }
}

// AC
