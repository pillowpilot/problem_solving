#include <iostream>

using namespace std;

const long long m = 1e9+7;

long power(long a, long e){
  if(e==0)return 1;
  long p=1;
  if(e%2==1){
    p*=a;
    p%=m;
    e--;
  }
  long t=power(a, e/2);
  t *= t;
  t %= m;
  p *= t;
  p %= m;
  return p;
}

long inverse(long a){
  return power(a, m-2); // m=1e9+7 (prime)
}

int main(){
  long long n;
  cin >> n;
  
  long long s=1;
  for(int i=0; i<6; i++){
    s *= (n-i)%m;
    s %= m;
  }

  s *= inverse(720); // 6!
  s %= m;

  cout << s << endl;

  return 0;
}

// AC
