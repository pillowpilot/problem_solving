#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  if( n==1 ){
    if( a[0] == 1 )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }else{
    int c = 0;
    for(int i = 0; i < n; i++){
      if( a[i] == 0 )
	c++;
    }

    if( c == 1 ){
      int i = 0;
      while( i < n && a[i] == 1 ){
	i++;
      }

      if( i == n-1 ){
	cout << "YES" << endl;
      }else{
	cout << "YES" << endl;
      }
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
// AC
