#include <iostream>

using namespace std;

int main(){
  int n, k;

  cin >> n >> k;

  if( 2*k+1 <= n ){
    cout << k*n << '\n';
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= k; j++){
	if( i + j > n ){
	  cout << i << ' ' << i + j - n << '\n';
	}else{
	  cout << i << ' ' << i + j << '\n';
	}
      }
    }
  }else
    cout << -1 << endl;
  return 0;
}

// AC
