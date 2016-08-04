#include <iostream>

using namespace std;

bool dist(int n){
  int f[10] = {0};

  while( n != 0 ){
    f[ n % 10 ]++;
    n /= 10;
  }

  int i = 0;
  while( i < 10 && f[i] < 2){
    i++;
  }
  
  return i == 10;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, i;
  cin >> n;
  i = n +1;
  while( !dist(i) )
    i++;
  cout << i << endl;
  return 0;
}

// AC
