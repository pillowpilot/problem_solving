#include <cstdio>
#include <cmath>

using namespace std;

int main(){
  int css = 1;
  double N;

  while( scanf("%lf", &N) == 1 && N != 0 ){
    double disc = sqrt( 9 + 8 * N ), n;
    n = ( 3 + disc )/2;
    n = ceil( n );

    printf("Case %d: %.0lf\n", css, n);
    css++;
  }
  
  return 0;
}

// AC
