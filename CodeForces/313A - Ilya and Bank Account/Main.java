import java.util.Scanner;

public class Main{
    public static void main(String[] args){
	int n, a, b;
	Scanner scanner = new Scanner(System.in);

	n = scanner.nextInt();

	a = n / 10;
	b = (n / 100) * 10 + (n % 10);

	if( n > a && n > b ) System.out.println(n);
	else if( a > b )     System.out.println(a);
	else                 System.out.println(b);
    }
}

// AC
