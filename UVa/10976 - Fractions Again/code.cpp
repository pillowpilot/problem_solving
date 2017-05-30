#include <iostream>
#include <vector>

#define rep(i, a, b) for(__typeof(a)i=a; i<=b; i++)
#define repi(i, a, b) for(__typeof(a)i=a; i>=b; i--)

using namespace std;

typedef unsigned long long ull;

void print(ull k, ull a, ull b){
  cout << "1/" << k << " = 1/" << b << " + 1/" << a << "\n"; 
}

int main(){
  ull k;
  while( cin >> k ){
    vector<int> ans;
    rep(a, k+1, 2*k){
      if( a*k % (a-k) == 0 )
	ans.push_back(a);
    }
    // ans is already sorted
    cout << ans.size() << "\n";
    rep(i, 0, ans.size()-1){
      ull a = ans[i];
      ull b = a*k/(a-k);
      print(k, a, b);
    }
  }
  return 0;
}

// AC
/*
  
 */
