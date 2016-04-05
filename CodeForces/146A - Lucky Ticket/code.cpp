#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

bool isLucky(const string &s){
  string::const_iterator c = s.begin();
  while(c!=s.end() && ( *c == '4' || *c == '7' ) ){
    //    printf("%c\n", *c);
    c++;
  }
  return c == s.end();
}

int charToInt(const char c){
  switch(c){
  case '1': return 1;
  case '2': return 2;
  case '3': return 3;
  case '4': return 4;
  case '5': return 5;
  case '6': return 6;
  case '7': return 7;
  case '8': return 8;
  case '9': return 9;
  case '0': return 0;
  }
}

bool equalSum(const string &s){
  int sum = 0; char x, y;
  string::const_iterator a, b;
  a = s.begin();
  b = s.end() - 1;
  
  while(a <= b){
    x = *a; y = *b;
    sum += charToInt(x) - charToInt(y);
    a++;
    b--;
  }

  return sum == 0;
}

int main(){
  int len;
  char n[51];
  string s;
  
  scanf("%d %s", &len, n);
  s = n;
  
  if( isLucky(s) && equalSum(s) ){
    printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
}
