#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
  int n, w, minCups = numeric_limits<int>::max(), maxCups = numeric_limits<int>::min();
  double r, x;

  scanf("%d %d", &n, &w);
  for( int i = 0; i < 2*n; i++ ){
    int a;
    scanf("%d", &a);
    if( minCups > a ) minCups = a;
    if( maxCups < a ) maxCups = a;
  }

  x = min( ((double)maxCups)/2, (double) minCups );
  x = min( ((double)w) / (((double)n)*3), x );

  cout << x * 3 * n << endl;

  return 0;
}
