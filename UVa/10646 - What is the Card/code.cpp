#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

vi values;
vc cards;
vc suits;

int main(){
  int n;

  scanf("%d ", &n);
  for( int cs = 0; cs < n; cs++ ){
    values = vi();
    cards = vc();
    suits = vc();
    
    for( int i = 0; i < 52; i++ ){
      char a, b;
      scanf(" %c%c ", &a, &b);
      cards.push_back(a);
      suits.push_back(b);
      
      if( '2' <= a && a <= '9' ){
	values.push_back( a - '0' );
      }else{
	values.push_back( 10 );
      }
    }

    int y = 0, index = values.size() - 1;
    for( int i = 0; i < 3; i++ ){
      printf("%c%c\n", cards[index], suits[index]);
      y += values[index];
      index -= 10 - values[index] + 1;
    }
    printf("Case %d: %c%c\n", cs + 1, cards[y], suits[y] );
      
  }
  return 0;
}
