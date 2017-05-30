/*
  ID: carlos.16
  PROG: sprime
  LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b;i++)

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int limit = 12000;
vb isPrime(limit, true);
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

bool testPrime(int n){
  if( n <= 1 ) return false;
  int i = 0;
  while( primes[i]*primes[i] <= n && n%primes[i] != 0 )
    i++;
  return primes[i]*primes[i] > n;
}

int countDigits(int n){
  int a = 1;
  while( n >= 10 ){
    a++;
    n/=10;
  }
  return a;
}

vi solve(int d){
  vi ans;
  
  queue<int> q;
  q.push(2); q.push(3); q.push(5); q.push(7);
  while( !q.empty() ){
    int v = q.front();
    q.pop();
    if( countDigits(v) == d )
      ans.push_back(v);
    else{
      rep(i, 1, 9){
	int n = v*10 + i;
	if( testPrime(n) )
	  q.push(n);
      }
    }
  }
  
  sort(all(ans));
  return ans;
}


int main(){
  ifstream input("sprime.in");
  ofstream output("sprime.out");
  eratosthenes();

  int n;
  input >> n;

  vi ans = solve(n);
  rep(i, 0, ans.size()-1){
    output << ans[i] << "\n";
    cout << ans[i] << "\n";
  }
  return 0;
}

// AC
/*
  Constructive algorithm.
  Basics solutions are 2, 3, 5 and 7. Append a digit (0, 2, 4, 5, 6, 8 will always fail) and
  if it is a prime then is a building block. 
  Where the number of digits is correct add it to ans and do not use it as a block.
  
  See those primes as a graph where every block (answer or not) is a vertex. 
  BFS or DFS will suffice. Notice that is a forest (set of trees).

  Test if n is prime in O(|{primes < sqrt(n)}|) (at most 1000 checks)
  Probabilistic test may be faster.
 */
