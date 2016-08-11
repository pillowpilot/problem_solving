#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int f[1001];
  fill_n(f, 1001, 0);
  for(int i =0; i < n; i++){
    int x;
    cin >> x;
    f[x]++;
  }

  int maxv = f[0];
  for(int i=0;i<1001; i++)
    maxv = max(maxv, f[i]);

  int l = (n%2==0)?n/2:n/2+1;
  if( maxv > l ){
    cout << "NO"<< endl;
  }else{
    cout << "YES" << endl;
  }
  
  return 0;
}

// AC
