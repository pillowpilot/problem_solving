#include <iostream>

using namespace std;

int gcd(int a, int b){
  if( a < b ) swap(a, b);
  if( b == 0 ) return a;
  else return gcd(b, a % b);
}

long long lcm(int a, int b){
  return a/gcd(a, b)*b; // Caution: a*b -> overflow
}

int main(){
  const int limit = 20;
  long long s = 1;

  for(int i = 2; i <= limit; i++)
    s = lcm(s, i);

  cout << s << endl;
  
  return 0;
}

// AC
