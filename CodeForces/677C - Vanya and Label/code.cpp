#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull m = (ll) 1e9+7;

int mapper(char c){
  int v;
  if( '0' <= c && c <= '9' ) v = c-'0';
  if( 'A' <= c && c <= 'Z' ) v = c-'A'+10;
  if( 'a' <= c && c <= 'z' ) v = c-'a'+36;
  if( '-' == c ) v = 62;
  if( '_' == c ) v = 63;
  return v;
}

int countZeros(int n){
  int c = 0;
  for(int i = 0 ; i < 6; i++){
    if( n % 2 == 1 ) c++;
    n = n/2;
  }
  return 6-c;
}

ull pow(int b, int e){
  if(e==0)return 1;
  ull p = 1;
  if( e % 2 == 1 ){
    p = b % m;
    e--;
  }
  ull t = pow(b, e/2);
  t = (t*t)%m;
  t = (t*p)%m;
  return t;
}

int main(){
  // 333333336 = 1/3 (mod m)
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s ;

  ull ans = 1;
  for(int i = 0 ; i < s.size(); i++){
    int z = countZeros(mapper(s[i]));
    int p = 1;
    for(int j = 0 ; j < z; j++)
      p*=3;

    //cout << ">> " << z << ' ' << p << endl;
    ans = (ans*p)%m;
  }

  ull inv = 333333336;
  //ans = (ans*inv)%m;
  
  cout << ans << endl;
  
  return 0;
}
// AC
