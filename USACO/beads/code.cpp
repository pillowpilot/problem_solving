/*
  ID: carlos.16
  PROG: beads
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)
#define debug(x) cout << #x << " = " << x << endl;

using namespace std;

int cut(const string o, int i){
  string s(o);
  rep(k, i, i+o.size()-1){
    s[k-i] = o[k%o.size()];
  }
  //debug(s);

  char c;
  int a = 0;
  while( s[a] == 'w' )
    a++;
  c = s[a];
  while( c == s[a] || s[a] == 'w' )
    a++;

  int n = s.size()-1;
  int b = 0;
  while( s[n-b] == 'w' )
    b++;
  c = s[n-b];
  while( c == s[n-b] || s[n-b] == 'w' )
    b++;

  //debug(a);
  //debug(b);
  return min(a + b, n+1);
}

int main(){
  ifstream input("beads.in");
  ofstream output("beads.out");

  int n;
  string s;
  input >> n >> s;

  int ans=0;
  
  int x, y, z;
  x = y = z = 0;
  rep(i, 0, n-1){
    if( s[i] == 'w' ) x++;
    if( s[i] == 'r' ) y++;
    if( s[i] == 'b' ) z++;
  }
  if( y == 0 || z == 0 ) // if cycle (all beads of the same color)
    ans = n; // usable beads equals to all beads
  
  rep(i, 0, n-1){
    if( ans == n )
      break;	
    ans = max(ans, cut(s, i));
  }

  output << ans << endl;
  //cout << ans << endl;
  return 0;
}

// AC
/*
  spend time analisying corner cases and use the fact that n will be small
  * all of one type (cycle)
  * one type does not exist (cycle)
  * "overlapping" segments (annoying, like rwwwwb)
 */
