#include <cstdio>
#include <cmath>

int f(int d, int i){
  if( d == 1 ) return 0;
  else if( i % 2 == 0 ) return pow(2, d - 2) + f(d - 1, i / 2);
  else return f(d - 1, (i+1) / 2);
}

int g(int d, int i){
  return pow(2, d-1) + f(d, i);
}

int main(){
  int cases;
  scanf( "%d", &cases );
  while( cases-- > 0 ){
    int d, i;
    scanf("%d%d", &d, &i);
    printf("%d\n", g(d, i));
    //    if( cases != 0 ) printf("\n");
  }
  return 0;
}
