import java.util.*;
import java.io.*;

public class C{
    public static void main(String[] args) throws IOException{
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	String lines[] = new String[2];
	lines[0] = in.readLine();
	lines[1] = in.readLine();
	
	int n = Integer.parseInt( lines[0] );
	String s = lines[1];

	int alphabetSize = 256;
	HashSet<Character> set = new HashSet<Character>(alphabetSize);
	for(int index=0; index<s.length(); index++){
	    char c = s.charAt(index);
	    set.add(c);
	}
	int differents = set.size();

	int min = differents;
	int max = s.length();

	while( min != max ){
	    int k = min + (max-min)/2;

	    HashMap<Character, Integer> counters = new HashMap<Character, Integer>(alphabetSize);
	    int index = 0;
	    while( index < k ){
		char c = s.charAt(index);
		if( counters.containsKey( c ) )
		    counters.put(c, counters.get(c) + 1);
		else
		    counters.put(c, 1);
		
		index++;
	    }

	    while( index < s.length() && counters.size() != differents ){
		char c;

		// Remove first character
		c = s.charAt(index-k);
		if( counters.get(c) == 1 )
		    counters.remove(c);
		else
		    counters.put(c, counters.get(c) - 1);

		// Add last character
		c = s.charAt(index);
		if( counters.containsKey(c) )
		    counters.put(c, counters.get(c) + 1);
		else
		    counters.put(c, 1);

		index++;
	    }

	    if( counters.size() != differents )
		min = k + 1; // No solution at k
	    else
		max = k;
	}
	

	out.println(min);
	
	out.close();
    }
}
// AC
