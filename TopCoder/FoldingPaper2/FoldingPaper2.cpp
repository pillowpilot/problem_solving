#include <iostream>

using namespace std;
typedef unsigned long long ull;

class FoldingPaper2{
 public:
  int solve(ull w, ull h, ull  a){
    if( w*h < a )
      return -1;
    if( w*f(h) <= a && a % w == 0 )
      return 0;
    if( f(w)*w <= a && a % h == 0 )
      return 0;

    int x = solve(w, f(h), a);
    int y = solve(f(w), h, a);
    return min(x, y);
  }

  ull f(ull x){
    if( x%2 == 0 )
      return x/2;
    else
      return x/2+1;
  }
};

int main(){
  FoldingPaper2 fp;

  cout << fp.solve(5, 3, 12) << endl;
  cout << fp.solve(2, 2, 3) << endl;
  cout << fp.solve(4, 4, 1) << endl;
  cout << fp.solve(127, 129, 72) << endl;
  cout << fp.solve(1, 100000, 100000) << endl;
  cout << fp.solve(1, 1, 2) << endl;
  cout << fp.solve(1000000000, 1000000000, 1) << endl;
  cout << fp.solve(1000000000, 1000000000, 12) << endl;
  
  
  return 0;
}
