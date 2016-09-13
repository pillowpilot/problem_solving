#include <iostream>

typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  while( n != 0 ){
    int a[n];
    
    for(int i = 0; i < n; i++)
      cin >> a[i];

    ll maxv = a[0];
    for(int i = 0; i < n; i++){
      ll v = 0;
      for(int j = i; j < n; j++){
	v += a[j];
	maxv = max(maxv, v);
      }
    }

    if( maxv <= 0 )
      cout << "Losing streak.\n";
    else
      cout << "The maximum winning streak is " << maxv << "." << endl;
    cin >> n;
  }
  return 0;
}

// AC
