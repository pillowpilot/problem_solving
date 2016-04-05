import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	int index;
	String s, t;
	StringBuilder u;

	Scanner scanner = new Scanner( System.in );
	s = scanner.next();
	t = scanner.next();

	// Find next string u lexicographically larger than s
	u = new StringBuilder( s );
	index = u.length() - 1;
	while( index >= 0 && u.charAt(index) == 'z' ){
	    u.setCharAt(index, 'a');
	    index--;
	}
	if( index >= 0 ) u.setCharAt(index, (char)(u.charAt(index) + 1));

	// If u < t, then it is a valid solution
	if( u.toString().compareTo(t) < 0 ) System.out.println( u );
	else System.out.println( "No such string" );
    }
}

// AC
