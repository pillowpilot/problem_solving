#include <iostream>

using namespace std;

int main(){
  int n;

  while( scanf("%d ", &n) == 1 && n != 0 ){
    if( n % 2 != 0 || n == 2 ){
      printf("Impossible\n");
    }else{
      printf("%d\n", 3*n/2);
      for(int i = 1; i <= n; i++){
	printf("%d %d\n", i, (i == n)?1:i+1);
      }
      for(int i = 1; i <= n/2; i++){
	printf("%d %d\n", i, i + n/2);
      }
    }
  }
  return 0;
}
