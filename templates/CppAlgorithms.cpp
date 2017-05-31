#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

/*
  Fast exponentiation mod (recursive)
 */
ull m=(ull)1e9+7;
ull fexpr(ull b, ull e){
  if(e==0)
    return 1;
  ull p=fexpr(b, e/2);
  p*=p;
  p%=m;
  if(e%2==1){
    p*=b;
    p%=m;
  }
  return p;
}

/*
  factorial mod m (recursive)
 */
ull facr(ull n){
  if(n==0) return 1;
  ull f=facr(n-1);
  f=f*(n%m)%m;
  return f;
}

/*
  binomial coef mod m (m is prime)
  based on factorial mod m (recursive) and pow mod m (recursive)
 */
ull bc(ull n, ull k){
  if(n<k)return 0;
  ull nf=facr(n);
  ull kf=facr(k);
  ull nkf=facr(n-k);
  ull kfi=fexpr(kf, m-2);
  ull nkfi=fexpr(nkf, m-2);
  return nf*kfi%m*nkfi%m; // (operator precedence) *=/=% (left-right)
}

/*
  sieve of eratosthenes
  5761455 primes upto 1e8 in 2.9s
  664579 primes upto 1e7 in 0.29s
  78498 primes upto 1e6 in 0.029s

  needs
  typedef unsigned long long ull;
 */

int const MAXP = (int) 1e7; // 1e9 could produce MLE
bool primes[MAXP+1]; // +1 to include MAXP

void eratosthenes(){
  fill(primes, primes+MAXP+1, true);  // needs <algorithm>
  
  primes[0] = primes[1] = false;
  ull index = 2; // ull for next line calculation
  while( index*index <= MAXP ){
    if( primes[index] == true ){
      int n = index * index;
      while( n <= MAXP ){
	primes[n] = false;
	n += index;
      }
    }
    index++;
  }
}

/*
  generator of primes
  generate the vector<unsigned long long> vprimes of primes
  needs eratothenes over primes
 */

typedef vector<ull> vull;

vull vprimes;
void genprimes(){
  eratosthenes();
  vprimes.reserve((int)7e5);
  for(int n = 2; n <= MAXP; n++){
    if(primes[n] == true){
      vprimes.push_back(n);
    }
  }
}

/*
  segmented sieve of eratosthenes
  
  calculate the [lower, upper] segment of the sieve [2, problem_upper_bound].
  needs genprimes (and genprimes needs eratosthenes over sqrt(problem_upper_bound))
 */

vector<bool> segprimes; // segprimes[index] = true iff index + lower is prime
// for(int index = 0; index < upper - lower + 1; index++)

void segmented_eratosthenes(int lower, int upper){
  // needs genprimes over vprimes

  segprimes = vector<bool>(upper - lower + 1, true);
  
  for(int i = 0; i < vprimes.size(); i++){
    ull p = vprimes[i];
    if( p*p > upper )
      break;

    int q = lower/p;
    if( lower % p != 0 )q++; // q = ceil(lower/p)
    if( q == 1 ) q++; // if p in range, then ignore
    
    while( p*q <= upper ){
      segprimes[p*q - lower] = false;   
      q++;
    }
  }

  if( lower == 1 ) // 1 is recognized as prime
    segprimes[0] = false;
}

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

/*
  Fibonacci in O(lg^2(n))
  using identity
  |1 1|n  |f_n+1 f_n  |
  |1 0| = |f_n   f_n-1|
  which implies
  f(2n+1) = f(n+1)^2 + f(n)^2    (odd  n)
  f(2n)   = f(n)*(f(n+1)+f(n-1)) (even n)
  needs ull m=(ull)1e9+7;
 */
typedef map<ull, ull> muu;

muu dp;

ull f(ull n){
  auto iter = dp.find(n);
  if( iter != dp.end() )
    return iter->second;
  
  if( n == 0 )    return 0;
  if( n == 1 )    return 1;
  if( n == 2 )    return 1;

  ull ans;
  if( n % 2 == 0 ){
    ull k = n/2;
    ans = ( f(k+1) + f(k-1) ) % m;
    ans = ans * f(k);
    ans = ans % m;
  }else{
    ull k = n/2;
    ull t1 = f(k+1); t1 = (t1 * t1) % m;
    ull t2 = f(k); t2 = (t2 * t2) % m;
    ans = (t1 + t2) % m;
  }

  dp[n] = ans;
  return ans;
}

/*
  Suffix Array and LCP Array
  O(n lg2 n + n)
  Needs global vector<Data> v;
 */
struct Data{
  int msd, lsd, sa, lcp;
  Data(){ msd = lsd = sa = lcp = 0; }
  Data(int msd, int lsd, int sa): msd(msd), lsd(lsd), sa(sa), lcp(0) {}
};

vector<Data> v;

inline bool comparator(const Data& a, const Data& b){
  return (a.msd < b.msd) || (a.msd == b.msd && a.lsd < b.lsd);
}

void salcp(const string& s){
  // Suffix Array Construction
  const int n = s.size();
  int gap = 1;
  vector<int> sainv(n);

  v.clear();
  for(int i = 0; i < n-1; i++){
    v.push_back( Data(s[i] - 'a', s[i+1] - 'a', i) );
  }
  v.push_back( Data(s[n-1] - 'a', -1, n-1) );

  sort( v.begin(), v.end(), comparator);

  while( gap <= n ){
    gap *= 2;

    // SA Inverse
    for(int i = 0; i < n; i++)
      sainv[ v[i].sa ] = i;

    // MSD
    int value = 0;
    for(int i = 0; i < n-1; i++){
      if( comparator(v[i], v[i+1]) == false ){
	v[i].msd = value;
      }else{
	v[i].msd = value;
	value++;
      }
    }
    v[ n-1 ].msd = value;

    // LSD
    for(int i = 0; i < n; i++){
      int index = v[i].sa + gap;
      if( sainv.size() <= index )
	v[i].lsd = -1;
      else
	v[i].lsd = v[ sainv[index] ].msd;
    }

    sort( v.begin(), v.end(), comparator );
  }

  // LCP Array construction
  for(int i = 0; i < sainv.size(); i++)
    sainv[ v[i].sa ] = i;

  int k = 0;
  for(int i = 0; i < sainv.size(); i++){
    if( sainv[i] != v.size() - 1 ){
      int a = i;
      int b = v[ sainv[i]+1 ].sa;

      while( a + k < s.size() && b + k < s.size() && s[a+k] == s[b+k] )
	k++;

      v[sainv[i]].lcp = k;

      k--;
      if(k < 0)
	k = 0;
    }else{
      k = 0;
    }
  }

}

/*
  Fenwick Tree.
  RSQ in O(lg n). 
  Single element modification in O(lg n).

  needs
  long long ll
  vector<ll> vll

  use add method to init

  Tested in UVa 12086, 12532

  //* indicates operation-related lines (add)
 */
struct BIT{
  vll ft; // 1-based
  // Use add to init
  BIT(int n): ft(n+1, 0) {} //*
  inline int lob(int k){ return k&-k; }
  void add(int k, ll v){
    assert(1<=k);
    while( k < ft.size() ){
      ft[k] += v; //*
      k += lob(k);
    }
  }
  ll sum(int k){
    ll s = 0;
    while( k ){
      s += ft[k]; //*
      k -= lob(k);
    }
    return s;
  }
  ll sum(int a, int b){ // [a, b]
    assert(1<=a && a<=b);
    return sum(b)-sum(a-1); //*
  }
};

/*
  UnionFind 
  O(lg n) w/o Path Compression

  needs
  vector<int> vi
  rep(i, a, b)

  Tested in UVa 793, 
 */
struct unionfind{
  vi parent, size;
  unionfind(int n){
    rep(i, 0, n-1){
      parent.push_back(i);
      size.push_back(1);
    }
  }
  int find(int v){
    while( parent[v] != v ) v = parent[v];
    return v;
  }
  void unite(int v, int u){
    v = find(v);
    u = find(u);
    if( v == u ) return ;
    if(size[v]>size[u]) swap(v, u);
    size[u]+=size[v];
    parent[v] = u;
  }
  bool test(int v, int u){
    return find(v)==find(u);
  }
};

int main(){
  /*
    BEWARE!!
    untested algorithms... ^_^U

    except eratostenes, genprimes, suffix+LCP Array and segmented_eratosthenes
   */

  /*
    if a < 0, then a % M must be implemented as M - (a%M)
   */
  return 0;
}
