#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 9999999;
vi dens;
vvi isc;
vvi cc;

int isCons(int n, int i){
  int& memo = isc[n][i];
  if( memo != -1 ) return memo;
    
  if( dens[i] == n )
    memo = 1;
  else{
    int include, exclude;
    if( i == 0 ){
      include = exclude = 0;
    }else{
      include = (dens[i] < n)?isCons(n-dens[i], i-1):0;
      exclude = isCons(n, i-1);
    }
    if( include == 1 || exclude == 1 ) memo = 1;
    else memo = 0;
  }
  return memo;
}
inline bool knapsack(int n){
  return isCons(n, dens.size()-1) == 1;
}

int mina(int n, int i){
  int& memo = cc[n][i];
  if( memo != -1 ) return memo;

  int include, exclude;
  if( i == 0 ){
    include = (dens[i] == n)?1:INF;
    exclude = (n==0)?0:INF;
  }else{
    include = (dens[i] <= n )?mina(n-dens[i], i-1)+1:INF;
    exclude = mina(n, i-1);
  }

  memo = min(include, exclude);
  return memo;
}

int main(){
  int tests;
  cin >> tests;
  while( tests-- ){
    int price; cin >> price;

    int sum = 0;
    int n; cin >> n;
    dens.clear();
    while( n-- ){
      int x; cin >> x;
      sum += x;
      dens.push_back(x);
    }

    isc.resize(sum+1);
    fill( begin(isc), end(isc), vi( dens.size(), -1));

    //for(int i = 0; i < isc.size(); i++) if( knapsack(i) ) cout << i << endl;

    while( !knapsack(price) )
      price++;
    
    cc.resize(sum+1);
    fill(begin(cc), end(cc), vi( dens.size(), -1));

    cout << price << ' ' << mina(price, dens.size()-1) << endl;
    
  }
  return 0;
}

// AC

/*
  actually, is a double coin change. XD not a knapsack + coin change.
  because knapsack maximize a function of value with 0/1 restictions
  and coin change count with denominations restrictions.
 */
