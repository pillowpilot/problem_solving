#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
  string line;

  while( cin >> line ){
    for( char c: line ){
      printf("%c", c - 7 );
    }
    printf("\n");
  }
  return 0;
}
