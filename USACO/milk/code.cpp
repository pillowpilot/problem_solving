/*
  ID: carlos.16
  PROG: milk
  LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

struct farmer{
  int available, price;
  farmer(int a, int p): available(a), price(p)
  {}
  bool operator<(const farmer& o){
    return price < o.price;
  }
};


int main(){
  ifstream input("milk.in");
  ofstream output("milk.out");

  int n, m;
  input >> n >> m;

  vector<farmer> ff;
  rep(i, 1, m){
    int p, a;
    input >> p >> a;
    farmer f(a, p);
    ff.pb(f);
  }
  sort(all(ff));

  int i = 0;
  int ans = 0;
  while( n > 0 ){
    int toBuy;
    if( ff[i].available >= n ){
      toBuy = n;
    }else{
      toBuy = ff[i].available;
    }
    ans += toBuy*ff[i].price;
    n -= toBuy;
    i++;
  }

  //cout << ans << endl;
  output << ans << endl;
  
  return 0;
}

// AC

/*
  Greedy approach (by sorting). Buy all (w/o surplus) from the cheapest farmer available.
 */
