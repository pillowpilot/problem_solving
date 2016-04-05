#include <cstdio>
#include <iostream>
#include <string>
#include <list>

using namespace std;

void tokenizer(string &source, list<string> &tokens, char delimiter = ' '){
  string token;

  string::iterator iter = source.begin();
  while(iter != source.end()){
    token = "";
    while(*iter == delimiter) iter++;
    while(*iter != delimiter && iter != source.end()){
      token += *iter;
      iter++;
    }
    tokens.push_back(token);
  }
}

void reverseWord(string &word){
  char t;
  string::iterator iterA = word.begin();
  string::iterator iterB = word.end() - 1;

  while(iterA < iterB){
    t = *iterA;
    *iterA = *iterB;
    *iterB = t;
    iterA++; iterB--;
  }
}

int main(){
  string line, word;
  list<string> tokens;
  
  while(getline(cin, line)){ //Se prefiere std::string a char* (sin problemas de admin de memoria :D )
    tokens.clear();
    tokenizer(line, tokens);
    
    list<string>::iterator iter = tokens.begin();
    while(iter != tokens.end()){
      reverseWord(*iter);
      printf("%s ", (*iter).data());
      iter++;
    }
    printf("\n");
  }
  return 0;
}
