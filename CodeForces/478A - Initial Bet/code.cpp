#include <cstdio>

using namespace std;

int main(){
  int a, b, c, d, e, s, q, r;
  
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  s = a+b+c+d+e;

  q = s / 5;
  r = s % 5;

  // b must be non-zero => q != 0
  printf("%d", (r == 0 && q != 0)?q:-1);
  
  return 0;
}
