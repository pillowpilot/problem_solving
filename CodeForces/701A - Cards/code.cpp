#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int s = 0;
  int a[n];
  for(int i =0; i < n; i++){
    cin >> a[i];
    s+=a[i];
  }

  s = s*2 / n;

  int b[n] = {0};
  for(int i = 0 ; i < n; i++){
    if(b[i]==0){
      b[i]=1;
      for(int j = i+1; j < n; j++){
	if( b[j] ==0 && a[i] + a[j] == s ){
	  cout << i+1 << ' ' << j+1 << '\n';
	  b[j] = 1;
	  break;
	}
      }
    }
  }
  return 0;
}

// AC
