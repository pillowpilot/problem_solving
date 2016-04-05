#include <cstdio>
#include <bitset>

#define N 1000001

using namespace std;

bitset<N> bs;

int d(int n){
  int sum = n;
  while( n != 0 ){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(){
  bs.reset(); //All bits to false
  for( int i = 0; i < N; i++ ){
    int pos = d(i);
    if( pos < N ) bs.set(pos);
  }
  for( int i = 0; i < 10000; i++ ){
    if( !bs.test(i) ) printf("%d\n", i);
  }
  return 0;
}
