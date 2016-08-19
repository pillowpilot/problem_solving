#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n], b[n];

  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }


  int ans = 0;
  for(int i = 0; i < n; i++){
    bool openable = false;
    for(int j = 0; j < n; j++){
      if( i != j && a[i] == b[j]){
	openable = true;
      }
    }
    if(!openable)
      ans++;
  }

  cout << ans << endl;
  return 0;
}

// AC
