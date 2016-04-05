#include <iostream>
#include <string>

using namespace std;

int process( const string& s ){
  int power = 1;
  int value = 0;
  for( int i = s.size() - 2; i >= 0; i-- ){
    if( s[i] == 'o' ){
      value += power;
    }
    if( s[i] == '.' ){
      power /= 2;
    }
    power *= 2;
  }
  return value;
}

int main(){
  ios_base::sync_with_stdio(false);
  string s, m;

  getline( cin, m );

  while( getline( cin, s ) && s != m ){
    int c = process(s);
    cout << (char) c;
  }
  
  return 0;
}

// AC. Better: 'o' means 1 and ' ' means 0. Do not compare a complete string at each iteration.
