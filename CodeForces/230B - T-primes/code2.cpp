#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef vector<bool> vb;

const int maxv=1e6+555;
vb isPrime(maxv, true);

void eratosthenes(){
  isPrime[0]=isPrime[1]=false;
  int n=2;
  while(n*n<isPrime.size()){
    if(isPrime[n]){
      int m = n*n;
      while( m<isPrime.size()){
	isPrime[m]=false;
	m+=n;
      }
    }
    n++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  eratosthenes();

  int n;
  cin >> n;

  rep(i, 0, n){
    ll a;
    cin >> a;
    ll sqrta = sqrt(a);
    if( sqrta*sqrta == a ){
      if( isPrime[sqrta] )
	cout << "YES\n";
      else
	cout << "NO\n";
    }else{
      cout << "NO\n";
    }
  }

  return 0;
}

// AC
/*
  Count # of divisors of a to figure out that a=p*p, p is prime.
  Then, for every a, check if it is a perfect square and if its sqrt is prime
  a<=1e12 implies that the primarity test should be upto 1e6.
 */
