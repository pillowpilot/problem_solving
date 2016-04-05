#include <cstdio>

using namespace std;

int main(){
  int cases;

  scanf("%d ", &cases);
  while( cases-- > 0 ){
    char c;
    int sum = 0, acc = 0;
    while( scanf("%c", &c) == 1 && c != '\n' ){
      if( c == 'O' ){
	acc++;
      }else{
	acc = 0;
      }
      sum += acc;
    }
    
    printf("%d\n", sum);
  }
}
