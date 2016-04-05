#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n, zeros = 0, ones = 0;

  scanf("%d ", &n);
  for( int i = 0; i < n; i++ ){
    char c;
    scanf("%c", &c);
    if( c == '0' ) zeros++;
    else ones++;
  }

  printf("%d", n - min(zeros, ones) * 2);
  
  return 0;
}
