#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  bool openable[1001];
  int count[1001];

  fill_n(openable, 1001, false);
  fill_n(count, 1001, 0);

  while( n-- > 0 ){
    int a, b;
    cin >> a >> b;
    count[a]++;
    // openable[i] == true iff exits a DIFERENT bottle that opens brand i
    if( a != b )
      openable[b] = true;
    else
      if( count[a] > 1 )
	openable[b] = true;
  }

  int ans = 0;
  for(int i = 1; i < 1001; i++){
    if( !openable[i] ){
      ans += count[i];
    }
  }

  cout << ans << endl;
  
  return 0;
}

// WA
