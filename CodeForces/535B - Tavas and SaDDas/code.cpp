#include <cstdio>
#include <cmath>

using namespace std;

// O(log_10(n))
int f(int n){
  int p = 0, offset = 0;
  while( n > 0 ){
    int d = n % 10;
    if( d == 7 ) offset += pow(2, p);
    p++;
    n /= 10;
  }
  return offset + pow(2, p) - 1;
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d", f(n));
  return 0;
}
