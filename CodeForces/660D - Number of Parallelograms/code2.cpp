#include <iostream>
#include <map>

using namespace std;

int  main(){
  ios_base::sycn_with_stdio(false);
  int n;
  map< pair<int, int>, int> cnt;

  cin >> n;

  int x[n], y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      int cx = (x[i] + x[j]);
      int cy = (y[i] + y[j]);

      cnt[ make_pair(cx, cy) ] ++;
    }
  }

  
  return 0;
}
