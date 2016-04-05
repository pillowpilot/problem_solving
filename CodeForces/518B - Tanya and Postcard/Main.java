import java.util.Scanner;

/*
  Solution based on editorial. Original solution in c++.
 */

public class Main{
    public static void main(String[] args){
	int yay = 0, whoops = 0;
	int[] counter = new int[518];
	String message, newspaper;
	

	Scanner scanner = new Scanner( System.in );
	message = scanner.next();
	newspaper = scanner.next();

	for(int index = 0; index < 518; index++) counter[index] = 0;

	// Let counter[c] = #c's in newspaper
	for(int index = 0; index < newspaper.length(); index++){
	    counter[ newspaper.charAt(index) ]++;
	}

	for(int index = 0; index < message.length(); index++){
	    char c = message.charAt(index);
	    if( counter[c] > 0 ){
		yay++;
		counter[c]--;
	    }
	}
	for(int index = 0; index < message.length(); index++){
	    char c = f( message.charAt(index) );
	    if( counter[c] > 0 ){
		whoops++;
		counter[c]--;
	    }
	}
	System.out.println("" + yay + " " + whoops);
	
    }
    static char f(char c){
	int offset = 'z' - 'Z';
	
	if( c <= 'Z' ) c += offset;
	else c -= offset;

	return c;
    }
}

// WA
