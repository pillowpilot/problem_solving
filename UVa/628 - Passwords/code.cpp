#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

vs words;
vs rules;

string generate(string w, int d, string p){
  string s = "";
  string::const_iterator c = p.begin();
  while( c != p.end() ){
    if( *c == '#' ){
      s += w;
    }else{
      s += to_string(d);
    }
    c++;
  }
}

void init(){
  words.clear();
  rules.clear();
}

int main(){
  int w, r;
  
  while( scanf("%d ", &w) == 1 ){
    init();
    while( w-- > 0 ){
      char s[260];
      string str;

      scanf("%259[^\n] ", s);
      str = s;
      words.push_back(str);
    }

    for( vs::const_iterator iter = words.begin(); iter != words.end(); iter++ ){
      printf("%s\n", iter->data());
    }

    scanf("%d ", &r);
    while( r-- > 0 ){
      
    }

  }
  return 0;
}
