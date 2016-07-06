import java.util.*;
import java.io.*;

public class JavaInputOutput{
    public static void main(String[] args){
	// For fast (enough) input

	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	String input = bf.readLine();
	String[] inputs = bf.readLines().split(" ");

	int n = Integer.parseInt(inputs[0]);

	// For fast (enough) output

	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	out.print("Some line");
	out.println("Some line ended in a EOL");

	out.close();
    }
}
