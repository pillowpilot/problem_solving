#include <iostream>

using namespace std;

const int M = 1000003;

int f(int c, int e){
  if( e == 0 )
    return 1;
  int p = 1;
  if( e % 2 == 1 ){
    p = (p*c) % M;
    e--;
  }

  int t = f(c, e/2);
  t = (t*t) % M;
  p = (p*t) % M;
  return p;
}

int sum(int c, int n){
  if( n == 1 )
    return c;
  int s = 0;
  if( n % 2 == 1 ){
    s = (s+f(c, n)) % M;
    n--;
  }

  int t = sum(c, n/2);
  int u = (f(c, n/2) + 1) % M;
  s = s + ( t*u )%M;
  return s;
}

int main(){
  int n, c;

  for(int i = 0 ; i < 5; i++){
    
  }
  
  cin >> n >> c;
  cout << sum(c, n) << endl;
  return 0;
}
