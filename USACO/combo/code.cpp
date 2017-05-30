/*
  ID: carlos.16
  PROG: combo
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

set<int> ans;

int n;
int f(int a, int b, int c, int i, int j, int k){
  /*a+=i; b+=j; c+=k;
  if( a > n ) a -= n;
  if( b > n ) b -= n;
  if( c > n ) c -= n;
  if( a < 1 ) a = n + a;
  if( b < 1 ) b = n + b;
  if( c < 1 ) c = n + c;*/

  a--; b--; c--;
  a = (a+i+n)%n + 1;
  b = (b+j+n)%n + 1;
  c = (c+k+n)%n + 1;

  int x = a*1000*1000 + b*1000 + c;
  return x;
}

int main(){
  ifstream input("combo.in");
  ofstream output("combo.out");

  input >> n;
  int a, b, c;
  int x, y, z;
  input >> a >> b >> c >> x >> y >> z;

  rep(i, -2, 2){
    rep(j, -2, 2){
      rep(k, -2, 2){
	int p = f(a, b, c, i, j, k);
	int q = f(x, y, z, i, j, k);
	ans.insert(p);
	ans.insert(q);
      }
    }
  }

  //cout << ans.size() << endl;
  output << ans.size() << endl;
  
  return 0;
}

// AC
/*
  Brute force by generating. At most 2*4^3=2^7=256 insertions into a set.

  BT by filtering is also fast enough.

  Use of set<int> and  x = a*1000*1000 + b*1000 + c; is faster than set<string>.
  To increase up to 19 digits (10^19) use unsigned long long.
 */
