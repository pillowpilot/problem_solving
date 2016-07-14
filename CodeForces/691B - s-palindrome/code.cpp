#include <iostream>

using namespace std;

char cc[] = {'A', 'H',  'I', 'O', 'o', 'p', 'q', 'M', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'b', 'd'};
char dd[] = {'A', 'H',  'I', 'O', 'o', 'q', 'p', 'M', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'd', 'b'};
int l = 19;

bool isValid(char x){
  int i = 0;
  while( i < l && cc[i] != x)
    i++;

  return !(i==l);
}

bool validPairs(char a, char b){
  int i = 0;
  while( i < l && cc[i] != a )
    i++;

  if( i < l ){
    return dd[i] == b;
  }else
    return false;
}

int main(){
  string s;
  cin >> s;
  
  int i = 0;
  bool isP = true;
  while( 2*i < s.size() && isP){
    char a = s[i];
    char b = s[s.size()-i-1];

    if( !( isValid(a) && validPairs(a, b) ) )
      isP = false;
    i++;
  }

  if(isP){
    cout << "TAK" << endl;
  }else{
    cout << "NIE" << endl;
  }
  
  return 0;
}
// AC
