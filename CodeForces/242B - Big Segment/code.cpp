#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int l[n], r[n];
  int minv = (int) 1e9+1;
  int maxv = 0;
  for(int i = 0 ; i < n; i++){
    cin >> l[i];
    cin >> r[i];
    minv = min(minv, l[i]);
    maxv = max(maxv, r[i]);
  }

  int i = 0;
  while( i < n  && (l[i] != minv || r[i] != maxv) ){
    i++;
  }

  if( i == n )
    cout << -1 << endl;
  else
    cout << i + 1<< endl;
  
  return 0;
}

// AC
