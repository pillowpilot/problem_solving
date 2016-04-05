#include <cstdio>

using namespace std;

int v1, v2, d;

int min(int a, int b){
  if( a < b ) return a;
  else return b;
}

int cp(int t){
  int i = 1, j = t, c = 0, s = 0;
  while( i < j ){
    s += v1 + c*d;
    s += v2 + c*d;

    printf("%d %d %d\n", v1 + c*d, v2 + c*d, s);
    
    c++; i++; j--;
  }
  if( i == j ){ // t = 2*n+1
    s += min( v1 + c*d, v2 + c*d );
  }
  return s;
}

int main(){
  int t;

  scanf("%d %d %d %d", &v1, &v2, &t, &d);
  printf("%d", cp(t));
  return 0;
}
