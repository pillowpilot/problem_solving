import java.util.*;
import java.io.*;

public class A{
    public static void main(String[] args) throws IOException{
	BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
	String line[] = br.readLine().split(" ");

	int n, m;

	n = Integer.parseInt(line[0]);
	m = Integer.parseInt(line[1]);

	int d1=0, d2=0;
	for(int i=7; i<n; i*=7)
	    d1++;
	for(int i=7; i<m; i*=7)
	    d2++;

	if(d1+d2>7)
	    System.out.println(0);
	else{
	    int cnt=0;
	    for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
		    int used[] = {0, 0, 0, 0, 0, 0, 0};

		    int a=i, b=j;
		    for(int k=0; k<=d1; k++){
			used[a%7]++;
			a /= 7;
		    }

		    for(int k=0; k<=d2; k++){
			used[b%7]++;
			b /= 7;
		    }

		    int max=used[0];
		    for(int k=0; k<7; k++)
			if(max<used[k])
			    max=used[k];

		    if(max==1)
			cnt++;	
		}
	    System.out.println(cnt);
	}
	    
    }
}

// AC
