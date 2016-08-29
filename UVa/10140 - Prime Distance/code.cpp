#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int const MAXP = (int) sqrt(2147483647) + 50; // 1e9 could produce MLE
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

vector<bool> segprimes; // segprimes[index] = true iff index + lower is prime
// for(int index = 0; index < upper - lower + 1; index++)

void segmented_eratosthenes(int lower, int upper){
  // needs genprimes over vprimes

  segprimes = vector<bool>(upper-lower+1, true);
  //fill_n( segprimes, upper - lower + 1, true);
  
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  genprimes();

  ull l, u;
  while( cin >> l >> u ){
    segmented_eratosthenes(l, u);

    int cnt = 0;
    for(int x = 0; x < u-l+1; x++)
      if( segprimes[x] )
	cnt++;
    //cout << ">> " << l << ' ' << u << ' ' << cnt << endl;

    ull i = l;
    while( i <= u && segprimes[i-l] == false )
      i++;

    ull j = i + 1;
    while( j <= u && segprimes[j-l] == false )
      j++;

    if( i > u || j > u){
      cout << "There are no adjacent primes.\n";
    }else{
      ull c1, c2, d1, d2, cd, dd;
      c1 = d1 = i;
      c2 = d2 = j;
      cd = dd = j - i;

      ull k = j + 1;
      while( k <= u ){
	if( segprimes[k-l] == true ){
	  i = j;
	  j = k;

	  if( j - i < cd ){
	    cd = j-i;
	    c1 = i;
	    c2 = j;
	  }

	  if( dd < j - i ){
	    dd = j-i;
	    d1 = i;
	    d2 = j;
	  }
	}
	k++;
      }

      cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant.\n";
    }
      
  }
  
  return 0;
}

// AC
