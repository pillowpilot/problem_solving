#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  ex -= sx;
  ey -= sy;
    
  string s;
  cin >> s;

  int d = abs(ex) + abs(ey);
  int i = 0;
  while( i < s.size() && d != 0 ){
    char c = s[i];
    if( c == 'N' && abs(ex) + abs(ey-1) < d )
      ey -= 1;
    
    if( c == 'S' && abs(ex) + abs(ey+1) < d )
      ey += 1;
    
    if( c == 'W' && abs(ex+1) + abs(ey) < d )
      ex += 1;
    
    if( c == 'E' && abs(ex-1) + abs(ey) < d )
      ex -= 1;
      
    d = abs(ex) + abs(ey);
    i++;
  }
  
  if( d == 0 ){
    cout << i << endl; 
  }else{
    cout << -1 << endl;
  }
  
  
  return 0;
}

// AC
