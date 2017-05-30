/*
  ID: carlos.16
  PROG: pprime
  LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define debug(x) cout << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int LIMIT = 12000;
vb isPrime(LIMIT, true);
vi primes;

void eratosthenes(){
  isPrime[0] = isPrime[1] = false;
  int p = 2;
  while( p*p < isPrime.size() ){
    if( isPrime[p] ){
      int j = p*p;
      while( j < isPrime.size() ){
	isPrime[j] = false;
	j += p;
      }
    }
    p++;
  }
  rep(i, 0, isPrime.size()-1){
    if( isPrime[i] )
      primes.push_back(i);
  }
}

bool isPrimeTest(int n){
  int i = 0;
  while( primes[i]*primes[i] <= n && n%primes[i] != 0){
    i++;
  }
  if( primes[i]*primes[i] > n )
    return true;
  else
    return false;
}

int genPalindrome(int i, bool odd){
  int p = i;
  if(odd) i /= 10;
  while( i>0 ){
    p = p*10 + i%10;
    i/=10;
  }
  return p;
}

vi genPalindromes(int a, int b){
  vi palindromes;
  int i, pi;
  i = 1; pi = genPalindrome(i, false);
  while( pi <= b ){
    if( a <= pi )
      palindromes.push_back(pi);
    i++;
    pi = genPalindrome(i, false);
  }

  i = 1; pi = genPalindrome(i, true);
  while( pi <= b ){
    if( a <= pi )
      palindromes.push_back(pi);
    i++;
    pi = genPalindrome(i, true);
  }

  sort(all(palindromes));
  return palindromes;
}

int main(){
  ifstream input("pprime.in");
  ofstream output("pprime.out");
  int a, b;
  input >> a >> b;
  //debug(a);
  //debug(b);
  eratosthenes();
  //debug(primes.size());
  vi p = genPalindromes(a, b);
  //debug(p.size());
  
  rep(i, 0, p.size()-1){
    if( isPrimeTest(p[i]) ){
      output << p[i] << "\n";
      //cout << p[i] << "\n";
    }
  }
  return 0;
}

// AC
/*
  Tricky BT. Memory too small to test primality in O(1) up to 100M. 
  Use eratosthenes to calculate primes <= sqrt(100M) and implement a primality test in 
  O(|{primes < sqrt(n)}|) (~1000 primes at most).
  Generate palindromes in O(sqrt(b)) and sort them.

  BT from a to b looking for palindromes may work too ( remember ~100M ops/s ^_^U)
 */
