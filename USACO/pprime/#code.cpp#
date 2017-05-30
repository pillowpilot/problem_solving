/*
  ID: carlos.16
  PROG: pprime
  LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vb isPrime;
vi primes;
void eratosthenes(int b){
  isPrime = vb(b, true);
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
}

bool isPalim(int n){
  int t=n;
  int nr=0;
  while( n!= 0){
    nr = nr*10 + n%10;
    n/=10;
  }
  n = t;
  return n==nr;
}

int main(){
  ifstream input("pprime.in");
  ofstream output("pprime.out");

  int a, b;
  input >> a >> b;

  eratosthenes(b+1);
  rep(i, a, b){
    if( isPrime[i] && isPalim(i) ){
      //cout << i << endl;
      output << i << endl;
    }
  }
  
  return 0;
}
