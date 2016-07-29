#include <cstdio>

using namespace std;

int main(){
  int n, h;
  scanf("%d %d", &n, &h);

  int sum = 0;
  while( n-->0){
    int a;
    scanf("%d", &a);
    if( a > h )
      sum += 2;
    else
      sum += 1;
  }

  printf("%d\n", sum);
  return 0;
}


// AC
