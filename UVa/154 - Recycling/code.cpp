#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

typedef map<char, char> mcc;
typedef vector<mcc> vmcc;

vmcc cities;

void processLine(const string& line){
  mcc city;

  int offset = 0;
  for( int i = 0; i < 5; i++){
    char color = line[offset];
    char type = line[offset + 2];
    city[color] = type;
    offset += 4;
  }

  cities.push_back( city );
}

int getDiferences(const mcc& a, const mcc& b){
  int diferences = 0;
  char colors[] = "roygb";
  for( int i = 0; i < 5; i++ ){
    char color = colors[i];
    if( a.at(color) != b.at(color) ) diferences++;
  }
  return diferences;
}

void solve(){
  int changes, minCity, minChanges = numeric_limits<int>::max();
  vmcc::const_iterator refCity = cities.begin();
  while( refCity != cities.end() ){
    changes = 0;
    vmcc::const_iterator otherCity = cities.begin();
    while( otherCity != cities.end() ){
      changes += getDiferences( *refCity, *otherCity );
      // printf("[%ld vs. %ld]: %d\n", refCity - cities.begin(), otherCity - cities.begin(), getDiferences( *refCity, *otherCity ));
      otherCity++;
    }
    // printf("\t[%ld]: %d\n", refCity - cities.begin(), changes);
    if( changes < minChanges ){
      minChanges = changes;
      minCity = refCity - cities.begin();
    }
    refCity++;
  }
  cout << minCity + 1;
}

void init(){
  cities.clear();
}

int main(){
  string line;
  cities.reserve(110);
  getline( cin, line );
  while( line.data()[0] != '#' ){
    init();
    while( line.data()[0] != 'e' ){
      processLine(line);
      getline( cin, line );
    }
    solve();
    cout << endl;
    getline( cin, line );
  }
  return 0;
}
