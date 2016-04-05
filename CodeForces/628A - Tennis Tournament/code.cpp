#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n, b, p;
  int total_b = 0, total_p;
  cin >> n >> b >> p;
  total_p = n*p;
  while(n > 1){
    int k = pow(2, (int)(log(n)/log(2)));
    //cout << ">> " << n << " " << k << endl;
    n = k / 2 + (n - k);
    total_b += (b*2+1)*k/2;
  }
  cout << total_b << " " << total_p << endl;
  return 0;
}

// AC
