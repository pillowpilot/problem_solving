#include <cstdio>
#include <limits>

using namespace std;

int main(){
  int n, b, h, w, min;

  while( scanf("%d %d %d %d ", &n, &b, &h, &w) == 4 ){
    min = numeric_limits<int>::max();
    while( h-- > 0 ){
      int cost;
      scanf("%d", &cost);
      cost *= n;
      for(int i = 0; i < w; i++ ){
	int beds;
	scanf("%d", &beds);
	if( n <= beds && cost <= b && cost < min ) min = cost;
      }
    }
    if( min == numeric_limits<int>::max() ) printf("stay home\n");
    else printf("%d\n", min);
  }
  return 0;
}

// AC
