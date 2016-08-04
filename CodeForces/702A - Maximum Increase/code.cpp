#include <iostream>

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  ll a[n];
  for(int i =0 ; i < n; i++){
    cin >> a[i];
  }

  int b[n];
  b[0] = 1;
  for(int i = 1; i < n; i++){
    if( a[i-1] < a[i] ){
      b[i] = b[i-1] + 1;
    }else{
      b[i] = 1;
    }
  }

  int ans = 1;
  for(int i = 0; i < n; i++){
    ans = max(ans, b[i]);
  }

  cout << ans << endl;
  
  return 0;
}

// AC
