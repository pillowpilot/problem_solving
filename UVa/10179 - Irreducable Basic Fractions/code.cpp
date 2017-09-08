#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxv=1e5+555;
vb isPrime(maxv, true);
vi primes;
void sieve(){
  isPrime[0]=isPrime[1]=false;
  int i=2;
  while( i*i < isPrime.size() ){
    if(isPrime[i]){
      int j = i*i;
      while( j<isPrime.size()){
	isPrime[j]=false;
	j+=i;
      }
    }
    i++;
  }
  rep(i, 0, isPrime.size())
    if(isPrime[i])
      primes.push_back(i);  
}

// n=1 returns empty vector
vii factorize(int n){
  vii ans;
  int i = 0;
  while( i < primes.size() && n!=1 ){
    if( n % primes[i] == 0 ){
      int e = 0;
      while( n % primes[i] == 0 ){
	e++;
	n /= primes[i];
      }
      ans.push_back(make_pair(primes[i], e));
    }
    i++;
  }
  if( n != 1 ){
    ans.push_back(make_pair(n, 1));
  }
  return ans;
}

ll phi(int n){
  ll ans = n;
  ll x = 1;
  vii f = factorize(n);
  rep(i, 0, f.size()){
    ll p = f[i].first;
    ans /= p;
    x *= p-1;
  }
  return ans*x;
}

int main(){
  ios_base::sync_with_stdio(false);;
  cin.tie(0); cout.tie(0);

  sieve();

  int n;
  while( cin >> n && n != 0 ){
    ll ans = phi(n);
    cout << ans << "\n";
  }

  return 0;
}

// AC
/*
  Calculate Euler's Phi Function.
  phi(n) = n prod_{p|n} (1-1/p)
  Therefore, factorize n and apply formula. Long long should not be necesary
 */
