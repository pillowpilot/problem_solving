import java.util.*;
import java.io.*;

public class B{
    public static void main(String[] args) throws IOException{
	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	
	String input = bf.readLine();
	out.print(input);
	input = new StringBuilder(input).reverse().toString();
	out.print(input);

	out.close();
    }
}

// AC
