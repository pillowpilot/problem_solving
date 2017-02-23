#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;
vs evols{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool fits(const string& p, const string& c){
  if( p.size() != c.size() )
    return false;

  int i = 0;
  while( i < p.size() && ( p[i] == '.' ||  p[i] == c[i] ) )
    i++;

  return i == p.size();
}

int main(){
  int n;
  string p;
  cin >> n >> p;
  for(string c: evols){
    if( fits(p, c) )
      cout << c << endl;
  }
  return 0;
}

// AC
