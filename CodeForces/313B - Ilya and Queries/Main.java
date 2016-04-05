import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	int m;
	String string;
	Scanner scanner = new Scanner(System.in);
	int[] dp;

	string = scanner.next();
	m = scanner.nextInt();
	dp = new int[string.length()+1];

	dp[0] = 0;
	for(int i = 0; i + 1 < string.length(); i++){
	    if( string.charAt(i) == string.charAt(i+1) ){
		dp[i+1] = dp[i] + 1;
	    }else{
		dp[i+1] = dp[i];
	    }
	}
	dp[string.length()] = dp[string.length()-1];

	for(int i = 0; i < m; i++){
	    int l, r;
	    l = scanner.nextInt();
	    r = scanner.nextInt();
	    System.out.println(dp[r-1] - dp[l-1]);
	}
    }
}

// AC
