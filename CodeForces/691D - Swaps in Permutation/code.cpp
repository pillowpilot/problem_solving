#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;

  cin >> n >> m;

  int p[n], a[m], b[m];

  for(int i =0; i < n; i++){
    cin >> p[i];
  }

  for(int i =0; i < m; i++){
    cin >> a[i] >> b[i];
    if( a[i] > b[i] )
      swap(a[i], b[i]);
    a[i]--;
    b[i]--;
  }

  bool cont = true;
  while( cont ){
    cont = false;
    /*
    for(int i = 0; i < n; i++){
      cout << p[i] << ' ';
    }
    cout << endl;
    */

    for(int i =0; i < m; i++){
      if( p[ a[i] ] < p[ b[i] ] ){
	swap( p[ a[i] ], p[ b[i] ] );
	cont = true;
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << p[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
