#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef vector<int> vi;

vi factorize(int n){
  vi ans;
  int i = 2;
  while( n != 1 && i <= n ){
    while( n%i==0 ){
      ans.push_back(i);
      n /= i;
    }
    i++;
  }
  return ans;
}

int main(){
  int n, k;
  cin >> n >> k;

  vi f = factorize(n);

  if( f.size() < k )
    cout << -1 << endl;
  else{
    while( f.size() > k ){
      int x = f.back();
      f.pop_back();
      f.back() = f.back()*x;
    }
    rep(i, 0, k){
      cout << f[i] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
  
// AC
/*
  Factorize.
  If #prime factors >= k, then solvable (reduce somehow).
  Else not solvable.
 */
