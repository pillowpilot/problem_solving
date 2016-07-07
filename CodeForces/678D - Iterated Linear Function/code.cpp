#include <iostream>

using namespace std;

typedef unsigned long long ull;
const ull M=1e9+7;
ull power(ull a, ull e){
  if( e == 0 ) return 1;
  
  ull ans = 1;
  if( e % 2 == 1 ){
    ans = a;
    e--;
  }

  ull b = power(a, e/2);
  ans *= ((b*b)%M);
  ans %= M;

  return ans;
}

ull powersum(ull a, ull n){
  if( n == 0 ) return 1;
  
  ull ans = 0;
  if( n % 2 == 0 ){
    ans = power(a, n);
    n--;
  }

  ull temp = power(a, (n-1)/2 + 1) + 1;
  temp %= M;

  ull temp2 = powersum(a, (n-1)/2);

  ans += (temp*temp2)%M;

  return ans;
}

/*
 Notice that
 g(x, n) = A^n*x + B*\sum_0^(n-1) A^i
 and \sum_0^n A^i = (A^((n-1)/2 + 1) +1)*\sum_0^((n-1)/2) A^i where not 2|n
 (just reduce even to odd cases and apply common factor over the upper half of the summation)
 Apply mod to each side.
 O(lg n + (lg n)(lg n)) First power + powersum
 O(lg^2 n)

 Could apply memoization over some powers of A. Randomly? sqrt(n) places? (sqrt decomposition)
 */

int main(){
  ull a, b, n, x;
  cin >> a >> b >> n >> x;

  a%=M;
  b%=M;
  x%=M;

  ull ans = power(a, n)*x;
  ans%=M;
  ans+=(b*powersum(a, n-1))%M;
  ans%=M;
  
  cout << ans << endl;
  
  
  return 0;
}

// AC
