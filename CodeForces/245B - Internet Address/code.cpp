#include <iostream>
#include <string>

#define RU   "ru"

using namespace std;

int main(){
  string s;

  cin >> s;

  int a = s.size() - 2;                     // Inicialmente se uso s.find(RU), pero...
  while( s[a] != 'r' || s[a+1] != 'u' )a--; // Buscar desde el final, en caso de que el addr comienze con "ru"

  if( s[0] == 'h' ){
    cout << "http://" << s.substr(4, a - 4) << ".ru";
  }else{
    cout << "ftp://"  << s.substr(3, a - 3) << ".ru";
  }

  if( a + 2 < s.size() ){
    cout << "/" << s.substr(a+2, s.size());
  }
  cout << endl;
  
  return 0;
}


// AC
