/*
  ID: carlos.16
  PROG: crypt1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;

set<int> ds;
vi digits;

inline bool valid(int n, int maxl){
  int l=0;
  do{
    int d = n%10;
    if( ds.find(d) == ds.end() )
      return false;
    n/=10;
    l++;
  }while( n != 0 );
  
  return l <= maxl;
}

int ans;

int top; // top factor
int bottom; // bottom factor
int partial_a;
int partial_b;
void bt(int p){
  if( p == 5 ){
    int sol = partial_a + partial_b*10;
    if( valid(sol, 4) ){
      ans++;
      /*debug(top);
      debug(bottom);
      debug(partial_a);
      debug(partial_b);
      debug(sol);
      debug("");*/
    }
  }else{
    rep(i, 0, digits.size()-1){
      if(p == 0 || p == 1 || p == 2){
	top = top*10 + digits[i];
	bt(p+1);
	top = top/10;
      }else if(p == 3){
	bottom = bottom*10 + digits[i];
	partial_b = digits[i]*top;
	if( valid(partial_b, 3) ) bt(p+1);
	bottom = bottom/10;
      }else if(p == 4){
	bottom = bottom*10 + digits[i];
	partial_a = digits[i]*top;
	if( valid(partial_a, 3) ) bt(p+1);
	bottom = bottom/10;
      }
    }
  }
}

int main(){
  ifstream input("crypt1.in");
  ofstream output("crypt1.out");

  int n;
  input >> n;

  rep(i, 1, n){
    int x;
    input >> x;
    ds.insert(x);
  }
  {
    set<int>::iterator iter = ds.begin();
    while( iter != ds.end() ){
      digits.push_back(*iter);
      iter++;
    }
  }

  /*rep(i, 0, digits.size()-1){
    cout << digits[i] << " ";
  }
  cout << endl;	*/	      

  ans = 0;
  bt(0); // 10^5 at most (constrains should reduce this drastically)

  //cout << ans << endl;
  output << ans << endl;
  
  return 0;
}

// AC
/*
  BT. Check eagerly to increase speed (should not be necessary).
  
  Checking all 3 digits times 2 digits numbers should be enough.
 */
