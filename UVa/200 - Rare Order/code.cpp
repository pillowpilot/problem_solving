#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef struct{
  char next, prev;
} vertex;

void initGraph(map<char, vertex> &vs){
  vs.clear();
}

void addVertex(map<char, vertex> &vs, char c){
  if( vs.find(c) == vs.end()) vs[c] = {'#', '#'};
}

void addEdge(map<char, vertex> &vs, char a, char b){
  vs[a].next = b;
  vs[b].prev = a;
}

map<char, vertex>::const_iterator findByValue(const map<char, vertex> &vs, char next){
  map<char, vertex>::const_iterator iter = vs.begin();
  while(iter != vs.end() && iter->second.next != next) iter++;
  return iter;
}

void printGraph(const map<char, vertex> &vs){
  map<char, vertex>::const_iterator iter = vs.begin();
  while(iter != vs.end()){
    printf("%c <-[%c]-> %c\n", iter->second.prev, iter->first, iter->second.next);
    iter++;
  }
}

void printReport(const map<char, vertex> &vs){
  map<char, vertex>::const_iterator f = vs.begin();
  while(f->second.prev != '#')f++;

  do{
    printf("%c", f->first);
    f = vs.find(f->second.next);
  }while(f != vs.end());
  printf("\n");
}

void compare(const string a, const string b, char &c, char &d){
  string::const_iterator ai = a.begin();
  string::const_iterator bi = b.begin();

  while(ai != a.end() && bi != b.end() && *ai == *bi){
    ai++; bi++;
  }
  
  if(ai != a.end() && bi != b.end()){
    c = *ai;
    d = *bi;
    //printf("Comparado <%s> y <%s>: %c < %c\n", a.data(), b.data(), c, d);
  }else{
    c = '#';
    d = '#';
  }
}

int main(){
  string a, b;
  char c, d;
  map<char, vertex> vs;

  initGraph(vs);
  
  getline(cin, a);
  if(a != "#"){
    getline(cin, b);
    do{
      compare(a, b, c, d);
      if( c != '#' ){
	addVertex(vs, c);
	addVertex(vs, d);
	addEdge(vs, c, d);
      }
      
      a = b;
      getline(cin, b);
    }while( b != "#" );
  }
  printGraph(vs);
  printReport(vs);
}
