#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class RockPaperScissorsMagicEasy{
public:
  int count(vector<int> cards, int score){
    const int M = 1e9+7;
    
    int n = cards.size();

    if(n < score) return 0;

    int fn = f(n);
    int fscore = f(score);
    int fnscore = f(n-score);
    int garg = (int)( (ull)(fscore)*fnscore % M );
    int gm2 = g(garg, M-2);
    int x = (int)( (ull)(fn)*gm2 % M );

    int power2 = g(2, n-score);

    return (int)( (ull)(x)*power2 );
  }

  int f(int n){ // Factorial mod M
    const int M = 1e9+7;

    if( n == 0 )
      return 1;
    else{
      int a = f(n-1);
      a *= n;
      a %= M;
      return a;
    }
  }

  int g(int a, int e){ // Fast exponenciation mod M
    const int M = 1e9+7;
    
    if( e == 0 )
      return 1;
    int p = 1;
    if( e % 2 == 1 ){
      p *= a;
      p %= M;
      e--;
    }
    int t = g(a, e / 2);
    t *= t;
    t %= M;
    
    p *= t;
    p %= M;

    return p;
  }
};

int main(){
  RockPaperScissorsMagicEasy o;

  cout << o.count(vector<int>{0,1,2}, 2) << endl;
  cout << o.count(vector<int>{1,2}, 0) << endl;
  cout << o.count(vector<int>{2,2,1,0,0}, 10) << endl;
  cout << o.count(vector<int>{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}, 7) << endl;
  cout << o.count(vector<int>{0,1,2,0,1,2,2,1,0}, 8) << endl;
  
  return 0;
}
