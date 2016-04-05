#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;

int main(){
  int n, moves = 0;
  vi original = vi();

  scanf("%d ", &n);
  while( n-- > 0 ){
    char c;
    scanf("%c ", &c); // "%c " (with space) to clean out the EOL
    original.push_back( (int)(c - '0') );
  }

  for( int i = 0; i < original.size(); i++ ){
    int a, b;
    char c;
    scanf("%c", &c);
    a = (int)(c - '0');
    b = original[i];

    moves += min( abs(a - b), 10 - abs(a - b) );
  }

  printf("%d\n", moves);
  return 0;
}
