import java.util.*;
import java.io.*;

public class P42{
    public static void main(String[] args) throws FileNotFoundException, IOException{
	String path = "p042_words.txt";
	BufferedReader file = new BufferedReader(new FileReader(path));

	int triangulars = 0;
	String[] words = file.readLine().split(",");
	for(String word: words){
	    String w = word.substring(1, word.length() - 1);

	    int value = 0;
	    for(int index = 0; index < w.length(); index++){
		char c = w.charAt(index);

		value += c - 'A' + 1;
	    }

	    System.out.print(w + "\t" + value + "\t");

	    if( check(value) ){
		triangulars++;
		System.out.print("*");
	    }

	    System.out.println();

	}

	System.out.println(triangulars);

    }

    private static boolean check(int n){
	double x = ( -1 + Math.sqrt(1+8*n) )/2;
	return (x == (int) x) && (n != 0);
    }
}

// AC ans = 162
