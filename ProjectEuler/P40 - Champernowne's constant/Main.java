import java.io.*;

public class Main{
    public static void main(String[] args){
	StringBuilder s = new StringBuilder((int)1.1e6);

	int n = 0;
	while( s.length() <= (int) 1e6 ){
	    s.append(n);
	    n++;
	}

	int ans = 1;
	ans *= Integer.parseInt("" + s.charAt(1));
	ans *= Integer.parseInt("" + s.charAt(10));
	ans *= Integer.parseInt("" + s.charAt(100));
	ans *= Integer.parseInt("" + s.charAt(1000));
	ans *= Integer.parseInt("" + s.charAt(10000));
	ans *= Integer.parseInt("" + s.charAt(100000));
	ans *= Integer.parseInt("" + s.charAt(1000000));
	
	System.out.println(ans);
    }
}
// AC ans=210
