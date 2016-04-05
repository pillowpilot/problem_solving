#include <cstdio>

using namespace std;

int main(){
  int css;

  scanf("%d", &css);
  for(int c = 1; c <= css; c++ ){
    int n, max = 0;
    scanf("%d", &n);
    while( n-- > 0 ){
      int v;
      scanf("%d", &v);
      if( max < v ) max = v;
    }
    printf("Case %d: %d\n", c, max);
  }
  return 0;
}

// AC
