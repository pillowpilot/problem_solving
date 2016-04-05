#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

typedef uint64_t bigInt;

int main(){
  bigInt n, a, maxValue = 0; //1 <= a_i <= 1e5 
  vector<bigInt> cnt(1e5 + 20, 0); //O.o Huge vector XD, O(n), 1 <= n <= 1e5
  vector<bigInt> f; //Posible Overflow

  cin >> n;
  for(bigInt i = 0; i < n; i++){ //O(n)
    cin >> a;
    if(maxValue < a) maxValue = a;
    cnt[a]++;
  }

  f.resize(maxValue + 2); //O(n)
  f[0] = 0;
  f[1] = cnt[1];

  for(bigInt i = 2; i <= maxValue; i++){ //O(n)
    f[i] = max( f[i-1], f[i-2] + cnt[i]*i );
  }

  cout << f[maxValue];
  return 0;
}
