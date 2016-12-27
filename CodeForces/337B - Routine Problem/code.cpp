#include <iostream>

using namespace std;

int gcd(int a, int b){
  if( a < b ) swap(a, b);
  if( a == 0 ) return a;
  if( b == 0 ) return a;
  else return gcd(b, a%b);
}

int main(){
  int x, y, a, b; cin >> x >> y >> a >> b;

  int m, n, g;
  if( a*y < b*x ){
    m = b*x - a*y;
    n = b*x;
  }else if( a*y > b*x ){
    m = a*y - b*x;
    n = a*y;
  }else{
    m = 0;
  }

  if( m != 0 ){
    g = gcd(m, n);
    cout << m/g << "/" << n/g << endl; 
  }else{
    cout << 0 << "/" << 1 << endl;
  }
  
  return 0;
}


// AC
