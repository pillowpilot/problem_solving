#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxv=1e5+555;
vb isPrime(maxv, true);
vi sprime(maxv);
void sieve(){
  isPrime[0]=isPrime[1]=false;
  sprime[1]=1;
  int i=2;
  while( i < isPrime.size() ){
    if(isPrime[i]){
      sprime[i]=i;
      int j = i*i;
      while( j<isPrime.size()){
	isPrime[j]=false;
	sprime[j]=i;
	j+=i;
      }
    }
    i++;
  }
}

// n=1 returns empty vector
vi factorize(int n){
  vi ans;
  while( n!=1 ){
    ans.push_back(sprime[n]);
    n/=sprime[n];
  }
  return ans;
}

vi pfactors(int n){
  set<int> f;
  while( n!=1 ){
    f.insert(sprime[n]);
    n/=sprime[n];
  }
  vi ans;
  for(int x:f){
    ans.push_back(x);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);;
  cin.tie(0); cout.tie(0);

  sieve();

  int n;
  cin >> n;
  
  vi groupsid(1e5+555);
  rep(i, 0, n){
    int s;
    cin >> s;
    //debug(s);
    vi f = pfactors(s);
    rep(i, 0, f.size()){
      groupsid[f[i]]++;
    }
  }

  int ans = 1;
  rep(i, 0, groupsid.size()){
    ans = max(ans, groupsid[i]);
  }

  cout << ans << endl;
  return 0;
}

// AC
/*
  Notice that 1<= gcd(s1, ...) <= 1e5.
  We map every group to a position in a vector
  If gcd(s1..) is prime, there will not be colissions
  If it is not, we map it to its smallest prime factor.
  Notice that 2 groups can not be mapped to the same possition unless they are the same group.
  
  For every integer s, factorize and mark every group that it could belong.

  Use extended sieve trick to speed up factorization upto O(lg n)
  O(n lg n)
 */
