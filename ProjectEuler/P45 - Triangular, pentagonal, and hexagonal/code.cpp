#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

inline bool isTriangular(ull n){
  double a = (-1+sqrt(1+8*n))/2;
  return a == (ull) a;
}

inline bool isPentagonal(ull n){
  double a = (1+sqrt(1+24*n))/6;
  return a == (ull) a;
}

int main(){
  int n = 144;
  int h = n*(2*n-1);
  while( !isTriangular(h) || !isPentagonal(h) ){
    n++;
    h = n*(2*n-1);
  }

  cout << h << endl;
  cout << n << endl;
  return 0;
}

// AC ans=1533776805
