#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n, min1, min2, min3, max1, max2, max3;
  int a, b, c;

  scanf("%d", &n);
  scanf("%d %d", &min1, &max1);
  scanf("%d %d", &min2, &max2);
  scanf("%d %d", &min3, &max3);

  a = min1;
  b = min2;
  c = min3;

  a = min(a + n - (a+b+c), max1);
  b = min(b + n - (a+b+c), max2);
  c = min(c + n - (a+b+c), max3);

  printf("%d %d %d", a, b, c);
  return 0;
}
