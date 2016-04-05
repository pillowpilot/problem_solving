#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int n, m;
vvc pic;

void init(int n, int m){
  pic = vvc( n, vc(m, ' ') );
}

bool isFace(char a, char b, char c, char d){
  bitset<4> fs;
  fs.reset();

  if( a == 'f' || b == 'f' || c == 'f' || d == 'f' ) fs.set(0);
  if( a == 'a' || b == 'a' || c == 'a' || d == 'a' ) fs.set(1);
  if( a == 'c' || b == 'c' || c == 'c' || d == 'c' ) fs.set(2);
  if( a == 'e' || b == 'e' || c == 'e' || d == 'e' ) fs.set(3);

  return ( fs.test(0) && fs.test(1) && fs.test(2) && fs.test(3) );
}

int solve(){
  int facec = 0;

  if( n < 2 || m < 2 ) return facec;

  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      char a, b, c, d;
      a = pic[i][j];
      b = pic[i][j+1];
      c = pic[i+1][j];
      d = pic[i+1][j+1];
      if( isFace(a, b, c, d) ) facec++;
    }
  }
  return facec;
}

int main(){
  scanf("%d %d ", &n, &m);
  init(n, m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      scanf("%c ", &c);
      pic[i][j] = c;
    }
  }
  
  int r = solve();
  printf("%d", r);

  return 0;
}
