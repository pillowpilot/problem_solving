#include <iostream>

using namespace std;

int main(){
  int n, a;
  cin >> n >> a;
  a--;
  
  int t[n];
  for(int i = 0; i < n;i++)
    cin >> t[i];

  int ans=0;
  if( t[a] == 1 ) ans++; // Criminal in distance 0
  for(int d = 1; d <= 100; d++){
    if( 0<= a-d && a+d < n  && t[a-d] + t[a+d] == 2 )ans+=2;
    if( 0<= a-d && a+d >= n && t[a-d] == 1 ) ans++;
    if( a-d< 0  && a+d < n  && t[a+d] == 1 ) ans++;
  }
  cout << ans << endl;
  
  return 0;
}

// AC
