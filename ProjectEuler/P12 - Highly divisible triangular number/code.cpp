#include <iostream>

using namespace std;

typedef unsigned long long ull;

int countDivisors(ull n){
  int d = 1, ans = 0;
  while( d*d <= n ){
    if( n % d == 0 ){
      ans+=2;
    }
    d++;
  }
  return ans;
}

int main(){
  ull acc = 0, limit = (int) 1e5, need = 500;
  for(int i = 1; i <= limit; i++){
    acc += i;
    int c = countDivisors(acc);
    if( c > need ){
      cout << acc << " with " << c << endl;
      break;
    }
  }
  return 0;
}

// AC ans = 76576500 with 576
