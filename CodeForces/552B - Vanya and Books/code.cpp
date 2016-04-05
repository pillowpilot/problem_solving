#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int digits(int n){
  return int( log10(n) ) + 1;
}

// e = 1 indica 1, 2, 3, ..., 8, 9.
// e = 2 indica 10, 11, 12, ..., 98, 99.
double f(int e){
  return (pow(10, e) - pow(10, e - 1))*e;
}

double g(int n){
  int d = digits(n);

  return (n - pow(10, d - 1) + 1) * d;
}

double solve(int n){
  int d = digits(n);
  double sum = 0;

  for(int e = 1; e < d; e++){
    sum += f(e);
  }

  sum += g(n);
  return sum;
}

// 10^9 < 2^31
int main(){
  int n;
  scanf("%d", &n);
  printf("%.0lf", solve(n));
  return 0;
}
