#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int c[8] = {0};
  int n;
  cin >> n;
  while(n-->0){
    int x;
    cin >> x;
    c[x]++;
  }

  int type1 = 0;
  if( c[1] >= c[4] && c[2] >= c[4] ){
    type1 = c[4];
    c[1] -= c[4];
    c[2] -= c[4];
    c[4] = 0;
  }

  int type2 = 0;
  if( c[1] >= c[3] && c[6] >= c[3] ){
    type2 = c[3];
    c[1] -= c[3];
    c[6] -= c[3];
    c[3] = 0;
  }

  int type3 = 0;
  if( c[1] == c[2] && c[2] == c[6] ){
    type3 = c[1];
    c[1] = c[2] = c[6] = 0;
  }

  bool allUsed = true;
  for(int i = 1; i < 8; i++){
    if( c[i] > 0 )
      allUsed = false;
  }
  
  if( allUsed ){
    while(type1--)
      cout << "1 2 4" << '\n';
    while(type2--)
      cout << "1 3 6" << '\n';
    while(type3--)
      cout << "1 2 6" << '\n';
  }else{
    cout << -1 << endl;
  }
  
  return 0;
}

// AC
