#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main(){
  int c;
  char s[55];

  scanf("%d ", &c);
  while( c-- > 0 )
    while( scanf("%[^\n]\n", s) == 1 && strlen(s) > 1 )
      printf(">>%d>>%s<<\n", c, s);
  
  return 0;
}
