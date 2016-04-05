#include <cstdio>

using namespace std;

int main(){
  int input;
  scanf("%d", &input);
  while( input != 0 ){
    printf("f91(%d) = %d\n", input, (input <= 100)?91:input-10);
    scanf("%d", &input);
  }
  return 0;
}
