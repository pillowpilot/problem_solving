#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;

ll pow(int b, int e){
  int ans = 1;
  while( e != 0 ){
    ans *= b;
    e--;
  }
  return ans;
}
vll solve(int n){
  vll ans;
  ll ulimit = pow(10, n/2)-1;
  //debug(ulimit);
  rep(a, (ll)0, ulimit){
    rep(b, (ll)0, ulimit){
      int x = (a+b)*(a+b);
      int y = a*(ulimit+1)+b;
      if( x == y ){
	//cout << a << " " << b << " " << y << endl;
	ans.push_back(y);
      }
    }
  }
  return ans;
}

vll solve2(int n){
  vll ans;
  ll ulimit = pow(10, n)-1;
  ll mod = pow(10, n/2);
  int x = 0;
  while( x*x <= ulimit ){
    int y = x*x;
    int a = (y/mod);
    int b = y % mod;
    //cout << a << " " << b << " " << y << endl;
    if( (a+b)*(a+b) == y )
      ans.push_back(y);
    x++;
  }
  return ans;
}

vvl ans(4);
void prep(){
  ans[0] = solve2(2); // 3
  ans[1] = solve2(4); // 5
  ans[2] = solve2(6); // 5
  ans[3] = solve2(8); // 9
}

void print(const vll& v, int d){
  rep(i, 0, v.size()-1){
    cout << setw(d) << setfill('0') << v[i] << "\n";
  }
}

int main(){
  prep();
  int n;
  while( cin >> n ){
    //debug(n);
    print(ans[n/2-1], n);
  }
  return 0;
}

// AC
/*
  BT with preprocessing.
  Use multiplication and addition to simulate fast concatenation. (Don't know if it's necesary). This solution takes ~.07s.
  There are really few of those numbers. O and 1 are always part of the solution.
  A generate algorithm should be really interesting.

  Lets x = (a+b)*(a+b) and y = a concat b
  Notice that y is always a square. So another approach would be, to check in O(sqrt(10^n)) every square if its digits (w/ leading zeros)
  added and squared equals that number. AC w/ Run Time ~0.000s
 */
