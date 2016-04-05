#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull ring(ull n){
  ull l = 0, h = 100;
  ull x;
  for(int i = 0; i < 20; i++){
    x = l + (h - l)/2;
    ull fx = x*x*3 + x*3 + 1;
    //cout << ">> f(" << x  << ")= " << fx << endl;
    if(fx > n)
      h = x;
    else if(fx < n)
      l = x;
    //cout << ">> " << x << endl;
  }
  
  return x;
}

int main(){
  ll n;
  //  cin >> n;
  for(int i = 0; i < 10; i++)
    cout << i << " - " << ring(i) << endl;
  for(int i = 10; i < 2000; i+=50){
    cout << i << " - " << ring(i) << endl;
  }
  return 0;
}
