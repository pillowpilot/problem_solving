#include <iostream>
#include <algorithm>

using namespace std;

/*
  sieve of eratostenes
  5761455 primes upto 1e8 in 2.9s
  78498 primes upto 1e6 in 0.029s
 */

typedef unsigned long long ull;
int const MAXP = (int) 1e7; // 1e9 could produce MLE
bool primes[MAXP+1]; // +1 to include MAXP

void eratostenes(){
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  eratostenes();

  int n;
  cin >> n;

  int i = 2;
  while( n>0 ){
    if( primes[i] == true ){
      n--;
      cout << i << ' ';
    }
    i++;
  }
  cout << endl;
}
  
// AC
