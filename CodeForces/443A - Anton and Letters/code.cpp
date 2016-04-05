#include <cstdio>
#include <vector>

using namespace std;

int main(){
  vector<bool> vb = vector<bool>('z' - 'a' + 1, false);
  char c = '{';
  int n = 0;
  
  while( c != '}' ){
    scanf("%c ", &c);
    if( 'a' <= c && c <= 'z' ){
      vb[c - 'a'] = true;
    }
  }

  for( int i = 0 ; i < vb.size(); i++ ){
    if( vb[i] == true ){
      n++;
    }
  }

  printf("%d", n);
  return 0;
}
