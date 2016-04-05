#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<ull> vull;

vull primes;

void sieve(){
  vb nmbrs = vb(1e11, false);
  primes = vull();

  ull i = 2;
  while( i < nmbrs.size() ){
    if( nmbrs[i] == false ){
      primes.push_back( i );
      ull k = i * i;
      while( k < nmbrs.size() ){
	nmbrs[k] = true;
	k += i;
      }
    }
    i++;
  }
}

vull ffs;
void factorize(long long n){
  ffs = vull();
  int i = 0;
  while( n != 1 ){
    while( n % primes[i] == 0 ){
      ffs.push_back(primes[i]);
      n /= primes[i];
    }
    i++;
  }
}

int main(){
  sieve();

  /*ull n;
  cin >> n;

  for(int i  =0 ;i < 10; i++) cout << primes[i] << endl;

  //  factorize(n);
  for(int i = 0; i < ffs.size(); i++ ){
    cout << ffs[i] << endl;
    }*/
  
  return 0;
}
