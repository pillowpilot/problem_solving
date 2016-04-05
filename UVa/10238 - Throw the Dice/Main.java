import java.util.Scanner;
import java.util.NoSuchElementException;
import java.math.BigInteger;

class Main{
    static int maxSum = 4050, maxThr = 55, maxFac = 55;    
    static BigInteger[][][] memo;

    static BigInteger pow(int b, int e){
	if( e == 0 ){
	    BigInteger r = BigInteger.valueOf(1);
	    return r;
	}else{
	    BigInteger r = pow(b, e / 2);
	    r = r.multiply(r);
	    if( e % 2 == 0 ){
		return r;
	    }else{
		r = r.multiply(BigInteger.valueOf(b));
		return r;
	    }
	}
    }

    static BigInteger dp(int s, int k, int n){
	if( s <= 0 || 0 == k ){
	    return BigInteger.valueOf(0);
	}else if( k == 1 && s <= n ){
	    return BigInteger.valueOf(1);
	}else{
	    if( memo[s][k][n].equals(BigInteger.valueOf(-1)) ){
		int lim = n;
		BigInteger sum = BigInteger.valueOf(0);
		for( int i = 1; i <= lim; i++ ){
		    sum = sum.add( dp(s-i, k-1, n) );
		}
		memo[s][k][n] = sum;
	    }
	    return memo[s][k][n];
	}
    }

    static void init(){
	memo = new BigInteger[maxSum][maxThr][maxFac];
	for( int i = 0; i < maxSum; i++ ){
	    for( int j = 0; j < maxThr; j++ ){
		for( int k = 0; k < maxFac; k++ ){
		    memo[i][j][k] = BigInteger.valueOf(-1);
		}
	    }
	}
    }

    public static void main(String[] args){
	int faces, n, sum;
	BigInteger posibles, power;
	Scanner in = new Scanner( System.in );
	
	init();
	try{
	    while( true ){
		faces = in.nextInt();
		n = in.nextInt();
		sum = in.nextInt();
		
		posibles = dp(sum, n, faces);
		power = pow(faces, n);
		
		System.out.println(posibles + "/" + power);
	    }
	}catch( NoSuchElementException e){
	    
	}
    }
}
