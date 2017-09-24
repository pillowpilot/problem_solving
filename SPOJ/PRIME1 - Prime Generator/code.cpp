#include <bits/stdc++.h>
#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(long long i=a;i<b;i++)
using namespace std;

typedef long long ll;


/*
  Fast exponentiation mod (recursive)
 */
ll powmod(ll b, ll e, ll m){
  if( e == 0 ) return 1LL;
  else{
    ll x = powmod(b, e/2, m);
    if( e%2 == 0 ) return x*x%m;
    else return (x*x%m)*b%m;
  }
}

/*
  Multiply two 64-bits w/o overflow O(n lg m)
 */
ll mulmod(ll a, ll b, ll c){
  ll x = 0,y=a%c;
  while(b > 0){
    if(b%2 == 1){
      x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
  }
  return x%c;
}

/*
  Miller Rabin Strong Pseudoprime Test 
  O(ln^4 n) [not sure]
  664579 primes upto 1e7 in 7.5s
  78498 primes upto 1e6 in 0.58s

  needs
  mulmod multiply 2 ll mod m w/o overflow
  powmod power ll mod m fast
  typedef long long ll;
 */

// Works for all primes p < 2^64.
bool millerrabin(ll n) {
  if (n <= 3) return (n >= 2);
  static const ll small[] =
      {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
       71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
       149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
  for (int i = 0; i < sizeof(small)/sizeof(ll); i++) {
    if (n%small[i] == 0) return n == small[i];
  }

  // Makes use of the known bounds for Miller-Rabin pseudoprimes.
  static const ll millerrabin[] =
      {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  static const ll A014233[] =  // From OEIS.
      {2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,
       3474749660383LL, 341550071728321LL, 341550071728321LL,
       3825123056546413051LL, 3825123056546413051LL, 3825123056546413051LL, 0};
  ll s = n-1, r = 0;
  while (s%2 == 0) {s /= 2; r++;}
  for (int i = 0, j; i < sizeof(millerrabin)/sizeof(ll); i++) {
    ll md = powmod(millerrabin[i], s, n);
    if (md != 1) {
      for (j = 1; j < r; j++) {
        if (md == n-1) break;
        md = mulmod(md, md, n);
      }
      if (md != n-1) return false;
    }
    if (n < A014233[i]) return true;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tests;
  cin >> tests;
  while( tests-- > 0 ){
    int n, m;
    cin >> m >> n;

    rep(i, m, n+1){
      if( millerrabin(i) )
	cout << i << "\n";
    }
    cout << "\n";
  }
  
  return 0;
}

// AC
/*
  Test primality over a range.
  Segment Eratosthenes or Miller-Rabin should be enough
 */
