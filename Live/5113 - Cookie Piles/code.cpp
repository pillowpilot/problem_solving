#include <cstdio>

using namespace std;

int main(){
  int t, n, a, d;

  scanf("%d ", &t);
  while( t-- > 0 ){
    scanf("%d %d %d ", &n, &a, &d);
    printf("%d\n", a * n + d * (n-1) * n / 2 );
  }
  return 0;
}

// AC
