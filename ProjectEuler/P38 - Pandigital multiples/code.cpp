#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getInt(const vector<int>& v, int i, int j){
  int n = 0;
  while( i < j ){
    n *= 10;
    n += v[i];
    i++;
  }
  return n;
}

int main(){
  vector<int> v = vector<int>{9, 8, 7, 6, 5, 4, 3, 2, 1};
  
  bool isSolution = false;
  int x, x2, x3, x4;
  do{
    // Type (1, 2)
    x  = getInt(v, 0, 4);
    x2 = getInt(v, 4, 9);
    if( x*2 == x2 )
      isSolution = true;
    
    // Type (1, 2, 3)
    x  = getInt(v, 0, 3);
    x2 = getInt(v, 3, 6);
    x3 = getInt(v, 6, 9);
    if( x*2 == x2 && x*3 == x3 )
      isSolution = true;
    
    // Type (1, 2, 3, 4)
    x  = getInt(v, 0, 2);
    x2 = getInt(v, 2, 4);
    x3 = getInt(v, 4, 6);
    x4 = getInt(v, 6, 9);
    if( x*2 == x2 && x*3 == x3 && x*4 == x4 )
      isSolution = true;
    
  }while( prev_permutation(v.begin(), v.end()) && !isSolution );

  if( isSolution )
    for(int i: v)
      cout << i;
  else
    cout << "918273645";
  
  cout << endl;
  return 0;
}

/*
  Let x(1, 2, ..., n)=y and |x| = #digits of x and n > 1
  If 5 <= |x| < 9, then y does not exist.
  If |x| = 9, then n = 1.
  Therefore, |x| <= 4.

  If |x| = 4 and y does have 9 digits, then y = 4|5.
  If |x| = 3 and y does have 9 digits, then y = 3|3|3.
  If |x| = 2 and y does have 9 digits, then y = 2|2|2|3.
  If |x| = 1 and y is pandigital, then y = 123456789 (x=1, n=9) or y = 918273645 (x=9, n=5).
 */

/*
  If |x| = 2, then 25<=x<=33. Finally, y=2... or y=3... and y < 918273645.
  If |x| = 3, then 100<=x<=111. Finally, y=1... and y < 918273645.
  If |x| = 4, then 5000<=x<=5e4. 
  If 1e4<=x, then y=1... and y < 918273645. 
  If x<=9181, then y=9181... and y < 918273645.
  Then, 9182 <= x <= 9999. (Good enough, 9182 <= x <= 9876)

  If x=9[9..4]??, then y is not pandigital or x has duplicates.
  If x=93[9..7]?, then y is not pandigital or x has duplicates.
  If x=91??, then 2x=18???. Finally, y is not pandigital.
  If x=921?, then y is not pandigital.
  ...
  Then, 9231 <= x <= 9368.
 */

//AC
