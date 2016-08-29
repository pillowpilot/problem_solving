#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int const MAXP = (int) 1e5; // 1e9 could produce MLE
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

typedef vector<int> vi;

vi pv;
int ways[MAXP + 1];

void init(){
  eratostenes();
  for(int i = 2; i < MAXP; i++)
    if( primes[i] )
      pv.push_back(i);
  
  fill(ways, ways+MAXP+1, 0);
  
  for(int i = 0; i < pv.size(); i++){
    int sum = pv[i];
    ways[sum]++;
    for(int j = i+1; j < pv.size(); j++){
      sum += pv[j];
      if( sum > MAXP )
	break;
      ways[sum]++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  init();
  int n;
  while( cin >> n && n != 0 ){
    cout << ways[n] << '\n';
  }
  
  return 0;
}
// AC
