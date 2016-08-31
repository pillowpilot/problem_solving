#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int MPRIME = (int) 1e6;
bool isPrime[MPRIME+1];
vi primes;
void eratosthenes(){
  fill(isPrime, isPrime + MPRIME+1, true);
  
  isPrime[0] = isPrime[1] = false;
  ll p = 2;
  while( p * p <= MPRIME ){
    if( isPrime[p] == true ){
      int i = p*p;
      while( i <= MPRIME ){
	isPrime[i] = false;
	i += p;
      }
    }
    p++;
  }
  for(int i = 0 ;i < MPRIME; i++)
    if( isPrime[i] )
      primes.push_back(i);
}

vll sums;
void buildSums(){
  sums.push_back( primes[0] );
  for(int i = 1; i < primes.size(); i++)
    sums.push_back( sums[i-1] + primes[i] );
}

bool solveForLength(int length){
  //cout << "\nFor length: " << length << endl;
  
  ll i = 0;
  while( i + length < sums.size() ){
    ll sum = sums[i+length] - ((i>0)?sums[i-1]:0);
    /*
    for(int k = i; k <= i + length; k++)
      cout << primes[k] << ' ';
    cout << ": " << sum;
    cout << endl;
    */
    if( sum <= MPRIME && isPrime[sum] ){
      cout << ">>> (prime)  " << sum << endl;
      cout << ">>> (length) " << length - 1 << endl;
      return true;
    }
    i++;
  }

  return false;
}

int main(){
  eratosthenes();
  buildSums();
  /*
  for(int i = 0; i < primes.size(); i++)
    cout << primes[i] << ' ';
  cout << endl;

  for(int i = 0; i < sums.size(); i++)
    cout << sums[i] << ' ';
  cout << endl;
  */
  int length = primes.size() - 1;
  while( length > 0 && !solveForLength(length) )
    length--;
  
  return 0;
}

// AC ans=997651
// Use -O2 for faster run ~2s vs ~30s

/*
  O(n^2)
  Possible optimizations:
  1. if sum[i] > limit, then i is max_length
  That PROBABLY reduce n from 1e6 to ~550
 */
