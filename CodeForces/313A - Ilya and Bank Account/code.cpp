#include <cstdio>

using namespace std;

int main(){
  int n, a, b;

  scanf("%d", &n);

  a = n / 10;
  b = (n / 100)*10 + (n % 10);

  if( n > a && n > b ) printf("%d\n", n);
  else if( a > b ) printf("%d\n", a);
  else printf("%d\n", b);
  
  return 0;
}

// AC
