#include <bits/stdc++.h>
#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;

vll frec;
vll sumf;
vvl memo;

ll rsum(int i, int j){
  if( j < i )
    return 0;
  else if( i == 0 )
    return sumf[j];
  else
    return sumf[j] - sumf[i-1];
}

ll dp(int i, int j){
  //debug(i);
  //debug(j);
  //debug("");

  if( j < i || i < 0 || j < 0)
    return 0;
  
  if( memo[i][j] != -1 )
    return memo[i][j];
  
  if( i == j ){
    memo[i][j] = 0;
  }else{
    ll ans = 1LL << 60;
    for(int k = i; k <= j; k++){
      ll x = dp(i, k-1) + rsum(i, k-1) + dp(k+1, j) + rsum(k+1, j);
      ans = min(ans, x);
    }
    memo[i][j] = ans;
  }

  return memo[i][j];
}

vvl root;
ll dpknuth(int i, int j){
  //debug(i);
  //debug(j);
  //debug("");

  if( j < i || i < 0 || j < 0)
    return 0;
  
  if( memo[i][j] != -1 )
    return memo[i][j];
  
  if( i == j ){
    memo[i][j] = 0;
    root[i][j] = i;
  }else{
    dpknuth(i, j-1); // to solve root[i][j-1]
    dpknuth(i+1, j); // to solve root[i+1][j]
    //cout << i << " " << j << ":" << root[i][j-1] << " " << root[i+1][j] << endl;
    ll ans = 1LL << 60;
    for(int k = root[i][j-1]; k <= root[i+1][j]; k++){
      ll x = dpknuth(i, k-1) + rsum(i, k-1) + dpknuth(k+1, j) + rsum(k+1, j);
      if( x < ans ){
	ans = x;
	root[i][j] = k;
      }
    }
    memo[i][j] = ans;
  }

  return memo[i][j];
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  while( cin >> n ){
    memo.resize(300);
    fill(all(memo), vll(300, -1));
    root.resize(300);
    fill(all(root), vll(300, -1));
    frec.clear();
    sumf.clear();
    
    rep(i, 0, n){
      ll f;
      cin >> f;
      frec.push_back(f);
    }
    
    sumf.push_back(frec.front());
    rep(i, 1, n){
      sumf.push_back(sumf.back()+frec[i]);
    }

    rep(i, 0, frec.size()){
      //cout << frec[i] << " ";
    }
    //cout << endl;
    
    rep(i, 0, sumf.size()){
      //cout << sumf[i] << " ";
    }
    //cout << endl;

    //ll ans = dp(0, frec.size()-1);
    ll ans = dpknuth(0, frec.size()-1);
    //cout << "final ans: " << ans << endl;
    cout << ans << endl;

    /*rep(i, 0, n+3){
      rep(j, 0, n+3){
	cout << fixed << setw(3) << memo[i][j] << " "; 
      }
      cout << endl;
    }
    cout << endl;

    rep(i, 0, n+3){
      rep(j, 0, n+3){
	cout << fixed << setw(3) << root[i][j] << " "; 
      }
      cout << endl;
      }*/
    
  }

  return 0;
}

// AC
/*
  Range DP. O(n^3)
  Direct Application of OBSP of CLRS in DP chapter.
  
  dp(i, j) = 0 if i == j // single node tree
  dp(i, j) = 0 if j < i  // empty tree => null element
  dp(i, j) = min i <= k <= j { 
                             dp(i, k-1) + sum i <= p <= k-1 frec[p] +
			     dp(k+1, j) + sum k+1 <= p <= j frec[p]
  }

  k-th element is the tree root.
  
  Notice that :
  cost(i)*f(i) become ( cost(i)+1 )*f(i) when optimal tree is used as subtree
  then f(i) must be added in this new tree.

  Range DP with Knuth Optimization. O(n^2)
  Notice that the root of every non trivial tree is between 
  the root of the tree/subproblem without the first element
  and
  the root of the tree/subproblem without the last element
 */
