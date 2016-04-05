#include <cstdio>
#include <vector>

using namespace std;

typedef vector<char> vc;

int main(){
  int n, t;
  vc queue;

  scanf("%d %d ", &n, &t);
  while( n-- > 0 ){
    char c;
    scanf("%c ", &c);
    queue.push_back(c);
  }

  while( t-- > 0 ){
    for( int i = 0; i < queue.size() - 1; i++ ){
      if( queue[i] == 'B' && queue[i+1] == 'G' ){
	queue[i] = 'G';
	queue[i+1] = 'B';
	i++;
      }
    }
  }

  for(char c: queue){
    printf("%c", c);
  }

  return 0;
}
