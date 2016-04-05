#include <cstdio>

using namespace std;

int f(int n){
  switch(n){
  case 1:
  case 2:
    return 1;
  case 3:
    return 2;
  default:
    return n;
  }
}

void example(int n){
  switch(n){
  case 1:
  case 2:
    printf("1");
    break;
  case 3:
    printf("1 3");
    break;
  case 4:
    printf("2 4 1 3");
    break;
  default:
    for( int i = 1; i <= n; i += 2 ) printf("%d ", i);
    for( int i = 2; i <= n; i += 2 ) printf("%d ", i);
    break;
  }
}

int main(){
  int n;

  scanf("%d", &n);

  printf("%d\n", f(n));
  example(n);
  return 0;
}
