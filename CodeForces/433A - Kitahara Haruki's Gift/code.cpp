#include <iostream>
#include <algorithm>

using namespace std;

/*
  build a matriz of #100 vs #200
  proof the pattern
 */


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int a, b;
  a = b = 0;
  for(int i = 0 ; i < n; i++){
    int x;
    cin >> x;
    if(x == 100) a++;
    else b++;
  }

  if( 1 <= a ){
    if( a % 2 == 0 )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }else{
    if( b % 2 == 0 )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}

// AC
