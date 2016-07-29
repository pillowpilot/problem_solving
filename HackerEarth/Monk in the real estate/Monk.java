import java.io.*;
import java.util.*; 
 
public class Monk{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));

      int t = sc.nextInt();
      while( t-- > 0 ){
	  int m = sc.nextInt();

	  HashSet<Integer> set = new HashSet<Integer>(10000);

	  while( m-->0){
	      int x = sc.nextInt();
	      int y = sc.nextInt();

	      set.add(x);
	      set.add(y);
	  }

	  out.println(set.size());
      }
      
      out.close();
   }

     

   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   //--------------------------------------------------------
}

// AC
