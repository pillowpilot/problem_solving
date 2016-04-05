#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
  bool openQuote = false;
  string line, newLine;
  while(getline(cin, line)){
    newLine.reserve( line.size() * 2 + 5 ); //Segun la implementación puede que no se reduzca el tamaño.
    string::iterator iter = line.begin(), iterNew = newLine.begin();
    while(iter != line.end()){
      if(*iter == '"'){
	if(openQuote){
	  *iterNew = '\''; iterNew++; *iterNew = '\'';
	  openQuote = false;
	}else{
	  *iterNew = '`'; iterNew++; *iterNew = '`';
	  openQuote = true;
	}
      }else{
	*iterNew = *iter;
      }
      iter++; iterNew++;
    }
    *iterNew = '\0';
    printf("%s\n", newLine.data());
  }
  return 0;
}
