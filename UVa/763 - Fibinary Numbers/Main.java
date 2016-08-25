import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
    static BufferedReader in;
    static PrintWriter out;
    static BigInteger f[];
    
    public static void main(String[] args)throws IOException{
	in = new BufferedReader(new InputStreamReader(System.in));
	out = new PrintWriter(new BufferedOutputStream(System.out));
	buildFibo();

	boolean first = true;
	String s1 = in.readLine();
	while( s1.length() == 0 )
	    s1 = in.readLine(); // Ignore whitelines at the beginning
	String s2 = null;
	while( s1 != null){ 
	    if( !first )
		out.println();
	    first = false;
	    
	    s2 = in.readLine();

	    BigInteger a = parse(s1);
	    BigInteger b = parse(s2);

	    BigInteger c = a.add(b);
	    String s3 = toFibinary(c);

	    out.println(s3);

	    s1 = in.readLine();
	    while( s1 != null && s1.length() == 0 )
		s1 = in.readLine(); // Ignore whitelines at the end
	}
	out.println();

	out.close();
    }

    public static String toFibinary(BigInteger n){
	StringBuilder str = new StringBuilder();
	for(int i = 0; i < f.length; i++){
	    str.append("0");
	}

	while( n.compareTo(new BigInteger("0")) != 0 ){
	    int index = f.length - 1;
	    while( f[index].compareTo(n) > 0 )
		index--;
	    
	    str.setCharAt(index, '1');
	    n = n.add(f[index].negate());
	}

	int index = str.length()-1;
	while( str.charAt(index) == '0' )
	    index--;

	str.delete(index+1, str.length());

	str.reverse();
	
	return str.toString();
    }

    public static BigInteger parse(String str){
	BigInteger n = new BigInteger("0");

	for(int i = 0; i < str.length(); i++){
	    if( str.charAt(str.length() - i - 1 ) == '1' ){
		n = n.add( f[i] );
	    }
	}

	return n;
    }
	
    public static void buildFibo(){
	f = new BigInteger[222];

	f[0] = BigInteger.ONE;
	f[1] = new BigInteger("2");
	int index = 2;
	while( index < f.length ){
	    f[index] = f[index-1].add(f[index-2]);
	    index++;
	}
    }
}
