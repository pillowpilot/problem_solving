#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

vvc m;
char cchar; // Contour CHAR

void print(){
  vvc::const_iterator iter = m.begin();
  while( iter != m.end() ){
    vc::const_iterator iiter = iter->begin();
    while( iiter != iter->end() ){
      printf("%c", *iiter);
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

bool isValid(int i, int j){
  return ( i >= 0 && j >= 0 && i < m.size() && j < m[i].size() );
}

void floodfill(int i, int j){
  if( isValid( i - 1, j ) && m[i-1][j] == ' ' ){ m[i-1][j] = m[i][j]; floodfill( i - 1, j ); }
  if( isValid( i + 1, j ) && m[i+1][j] == ' ' ){ m[i+1][j] = m[i][j]; floodfill( i + 1, j ); }
  if( isValid( i , j - 1 ) && m[i][j - 1] == ' ' ){ m[i][j - 1] = m[i][j]; floodfill( i , j - 1); }
  if( isValid( i , j + 1 ) && m[i][j + 1] == ' ' ){ m[i][j + 1] = m[i][j]; floodfill( i , j + 1); }
}

char getContourChar(){
  bool founded = false;
  char c;
  vvc::const_iterator iter = m.begin();
  while( iter != m.end() && !founded ){
    vc::const_iterator iiter = iter->begin();
    while( iiter != iter->end() && !founded ){
      if( *iiter != ' ' && *iiter != '_' ){
	c = *iiter;
	founded = true;
      }
      iiter++;
    }
    iter++;
  }

  return c;
}

bool endOfCase(const string& s){
  string::const_iterator iter = s.begin();
  while( s.end() != iter && *iter == '_' ){
    iter++;
  }
  return ( iter == s.end() );
}

void loadLine(const string& s){
  m.resize( m.size() + 1 );

  string::const_iterator iter = s.begin();
  while( iter != s.end() ){
    m[m.size() - 1].push_back( *iter );
    iter++;
  }
} 

void init(){
  m.clear();
}

void solve(){
  cchar = getContourChar();
  
  vvc::const_iterator iter = m.begin();
  while( iter != m.end() ){
    vc::const_iterator iiter = iter->begin();
    while( iiter != iter->end() ){
      if( *iiter != ' ' && *iiter != '_' && *iiter != cchar ){
	floodfill( iter - m.begin(), iiter - iter->begin() );
      }
      iiter++;
    }
    iter++;
  }

  print();
}

int main(){
  string line;
  
  while( getline( cin, line ) ){
    init();
    while( !endOfCase(line) ){
      loadLine( line );
      getline( cin, line );
    }
    // print();
    solve();
    printf("%s\n", line.data());
  }

  return 0;
}
