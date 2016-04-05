#include <cstdio>
#include <iostream>

using namespace std;

inline bool divisible(char a, char b){
  int x = (a - '0')*10 + (b - '0');
  return x % 4 == 0;
}

int main(){
  char s[300099];
  unsigned long long c = 0;
  
  scanf("%s", s);
  
  int i = 0;
  while( s[i] != '\0' ){
    int d = s[i] - '0';
    if( d % 4 == 0 ) c++;
    i++;
  }

  //printf("%ld\n", c);
  
  i = 1;
  while( s[i] != '\0' ){
    if( divisible(s[i-1], s[i]) == true ) c += i;
    i++;
  }

  cout << c << endl;
  
  return 0;
}

// AC
