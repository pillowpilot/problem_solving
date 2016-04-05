#include <iostream>

using namespace std;

long long f(int a, int b){
  if( a % b == 0 ) return a/b;
  else return a/b + 1;
}

int main(){
  int n, m, a;
  cin >> n >> m >> a;
  cout << f(n, a) * f(m, a) << endl;
  return 0;
}

// AC
