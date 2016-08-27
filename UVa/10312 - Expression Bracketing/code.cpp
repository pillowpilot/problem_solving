#include <cstdio>

using namespace std;

typedef unsigned long long ull;

const int M = 30;
ull catalan[M];
ull schroder[M];

void init(){
  // n starts with 0...
  catalan[0] = 1;
  for(int n = 1; n < M; n++){
    catalan[n] = 0;
    for(int i = 0; i < n; i++){
      catalan[n] += catalan[i]*catalan[n-1-i];
    }
  }


  // n starts with 1...
  schroder[1] = schroder[2] = 1;
  for(int n = 3; n < M; n++)
    schroder[n] = ((6*n-9)*schroder[n-1] - (n-3)*schroder[n-2])/n;
}

int main(){
  init();
  int n;
  while( scanf("%d", &n) == 1 ){
    printf("%ld\n", schroder[n] - catalan[n-1]);
  }
  return 0;
}
