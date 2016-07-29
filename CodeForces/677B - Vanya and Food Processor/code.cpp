#include <iostream>

using namespace std;

typedef long long ull;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  ull n, h, k;
  cin >> n >> h >> k;

  ull a[n];
  for(int i = 0 ; i < n; i++){
    cin >> a[i];
  }

  ull secs = 0;
  ull sum = 0;
  int i = 0;
  while( i < n || sum > 0){
    while( i < n && h - sum >= a[i] ){
      sum+= a[i];
      i++;
    }
    //cout << i << endl;
    if( i < n ){
      ull x = (a[i] - (h-sum));
      ull y = (x%k==0)?x/k:x/k+1;
      secs += y;
      sum = (sum < k*y)? 0: sum-k*y;
    }else{
      secs += (sum%k ==0)?sum/k:sum/k+1;
      sum = 0;
    }
  }

  cout << secs << endl;
  return 0;
}

// AC
