#include <iostream>
#include <vector>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

ll powmod(ll b, ll e, ll m){
  if( e == 0 ) return 1LL;
  else{
    ll x = powmod(b, e/2, m);
    if( e%2 == 0 ) return x*x%m;
    else return (x*x%m)*b%m;
  }
}

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

// Works for all primes p < 2^64.
bool IsPrimeFast64(ll n) {
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

const int limit = 10500;
vb isPrime(limit, true);
vi ans;

void prep(){
  /*isPrime[0] = isPrime[1] = false;
  int p = 2;
  while( p*p < limit ){
    if( isPrime[p] ){
      int j = p*p;
      while( j < limit ){
	isPrime[j] = false;
	j+=p;
      }
    }
    p++;
  }*/

  rep(i, 0, limit-1){
    isPrime[i] = IsPrimeFast64(i);
  }

  // 0 has no divisors
  // 1 has only 1 divisor
  rep(i, 2, limit-1){
    int divcount = 0;
    int j = 1;
    while( j*j < i ){
      if( i%j == 0 ){
	divcount+=2;
      }
      j++;
    }
    if( j*j == i ){ // perfect squares
      divcount++;
    }
    //cerr << i << " : " << divcount << " : ";
    if( isPrime[divcount] ){
      ans.push_back(i);
      //cerr << "X";
    }
    //cerr << endl;
  }
}

int main(){
  prep();

  rep(i, 0, ans.size()-1){
    //cout << ans[i] << " ";
  }
  //cout << endl;
  
  int t;
  cin >> t;
  while( t-- ){
    int l, h;
    cin >> l >> h;
    bool print = false;
    int i = 0;
    while( ans[i] <= h ){
      if( l <= ans[i] ){
	if( print )
	  cout << " ";
	print = true;
	cout << ans[i];
      }
      i++;
    }
    if( !print )
      cout << -1;
    cout << "\n";
  }
  return 0;
}

// AC
/*
  Constructive. Find all primes < 10**5 and count the divisors of n in O(sqrt n) for every n < 10**5.
  Primes with eratosthenes in O(N lg lg N) or with miller rabin in O(N) N = 10**5.
  Notice that there is no space after the last integer and there is an EOL after every line.
 */
