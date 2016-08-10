#include <iostream>
#include <map>

using namespace std;
typedef map<int, int> mii;

mii c;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, minv = (int) 1e9 + 10, maxv = 0;
  cin >> n;

  int x;
  while( n-- > 0 ){
    cin >> x;
    c[x]++;
    minv = min(minv, x);
    maxv = max(maxv, x);
  }

  int dif = maxv - minv;
  long long ways = 0;
  if( dif > 0 ){
    for(auto iter: c){
      int x = iter.first - dif;
      auto iter2 = c.find(x);
      if( iter2 != c.end() ){
	int a = iter.second;
	int b = iter2->second;
	ways += (long long)a*b;
      }
    }
  }else{
    // if dif=0, then there are all equals... and c has only one element
    int a = c[x]; // x contains the last element read
    ways = ((long long) a * (a-1)) / 2; // a or a-1 must be even... ^_^
  }

  cout << dif << ' ' << ways << endl;
  
  
  return 0;
}

// WA Beware the Overflow!!
// AC
