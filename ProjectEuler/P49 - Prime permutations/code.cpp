#include <iostream>
#include <vector>

using namespace std;

int limit = 1e5;
vector<bool> isPrime(limit+1, true);
vector<int> primes;

void erathostenes(){
  isPrime[0] = isPrime[1] = false;
  for(int p = 2; p < isPrime.size(); p++){
    if( isPrime[p] ){
      primes.push_back(p);
      int j = p*p;
      while( j < isPrime.size() ){
	isPrime[j] = false;
	j+=p;
      }
    }
  }
}

bool arePerm(int a, int b){
  vector<int> l(10);
  while( a != 0 ){
    l[a%10]++;
    a /= 10;
  }
  while( b != 0 ){
    l[b%10]--;
    b /= 10;
  }

  int i = 0;
  while( i < l.size() && l[i] == 0 )
    i++;
  return i == l.size();
}

int main(){
  erathostenes();

  int i = 0;
  while( i < primes.size() ){
    int pi = primes[i];
    if( 999 < pi && pi < 9999){
      int j = i + 1;
      while( j < primes.size() ){
	int pj = primes[j];
	int pk;
	if( arePerm(pi, pj) && (pk=pj+(pj-pi)) && pk < limit && isPrime[pk] && arePerm(pi, pk) ){
	  cout << pi << pj << pk << endl;
	  cout << pi << " " << pj << " " << pk << endl;
	}
	j++;
      }
    }
    i++;
  }
  return 0;
}

// AC ans = 296962999629

/*
  pretty straightfoward...
  list all 4-digit primes, test pairs pi and pj such that are permutations of each other
  if they are, then pk is testeable.(prime and permutation)
 */
