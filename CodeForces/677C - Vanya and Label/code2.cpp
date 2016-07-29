#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull m = (ull) 1e9+7;

int a[64];

void precalc(){
  fill_n(a, 64, 0);
  for(int i = 0; i < 64; i++){
    for(int j = 0; j < 64; j++){
      int x = i & j;
      a[x]++;
    }
  }
}

int mapper(char c){
  int v;

  if( '0' <= c && c <= '9' ) v = c-'0';
  if( 'a' <= c && c <= 'z' ) v = c-'a'+36;
  if( 'A' <= c && c <= 'Z' ) v = c-'A'+10;
  if( c == '-' ) v = 62;
  if( c == '_' ) v = 63;

  return v;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  string s;
  cin >> s;

  precalc();

  ull ans = 1;
  for(int i = 0 ; i < s.size(); i++){
    //cout << s[i] << ' ' << mapper(s[i]) << endl;
    ans = (ans*a[mapper(s[i])])%m;
  }

  cout << ans << endl;
  
  return 0;
}

// AC
