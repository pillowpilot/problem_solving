#include <cstdio>

//using namespace std;

int main(){
  int n, a;

  scanf("%d", &n);
  while( n-- > 0 && scanf("%d", &a) == 1 && a != 1 );

  printf("%s1\n", (a == 1)?"-":"");
  return 0;
}

// AC
