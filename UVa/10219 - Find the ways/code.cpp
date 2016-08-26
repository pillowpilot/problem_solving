#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ull n, k;
  while( cin >> n >> k ){
    ull a = min(k, n-k);
    ull b = max(k, n-k);
    double x = 0;
    
    for(int i = b + 1; i <= n; i++)
      x += log10(i);

    for(int i = 1; i <= a; i++)
      x -= log10(i);
    
    int ans = (int) floor(x) + 1;
    cout << ans << '\n'; // WA cause the EOL... again... 
  }
  
  return 0;
}

// AC 
