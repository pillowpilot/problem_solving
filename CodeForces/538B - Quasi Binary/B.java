import java.util.*;

public class B{
    public static void main(String[] args){
	Scanner in = new Scanner(System.in);

	int n = in.nextInt();
	Vector<String> qs = new Vector<String>();
	while( n > 0 ){
	    String s = new String("" + n);
	    String q = new String();
	    for(int i = 0; i < s.length(); i++){
		char d = s.charAt(i);
		if( d == '0' )
		    q += "0";
		else
		    q += "1";
	    }
	    qs.add( q );
	    n -= Integer.parseInt( q );
	}
	System.out.println( qs.size() );
	for(String s: qs )
	    System.out.print( s + " ");
    }
}

// AC
