#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Map A->0, B->1, ... ,Z, ,?, ?, ... ,? , a, b, ..., z.
int f(char c){
  return c - 'A';
}

int main(){
  int yay = 0, whoops = 0;
  string message, newspaper;
  vector<int> needed = vector<int>(f('z') + 1), available = vector<int>(f('z') + 1);

  cin >> message >> newspaper;

  for( char c: message ) needed[f(c)]++;
  for( char c: newspaper) available[f(c)]++;

  for( char c = 'A'; c <= 'Z'; c++ ){
    char fc = f(c);
    if( needed[fc] <= available[fc] ){
      yay += needed[fc];
      available[fc] -= needed[fc];
      needed[fc] = 0;
    }else{
      yay += available[fc];
      needed[fc] -= available[fc];
      available[fc] = 0;
    }
    
    fc += 'a' - 'A';
    if( needed[fc] <= available[fc] ){
      yay += needed[fc];
      available[fc] -= needed[fc];
      needed[fc] = 0;
    }else{
      yay += available[fc];
      needed[fc] -= available[fc];
      available[fc] = 0;
    }
  }

  for( char c = 'A'; c <= 'Z'; c++ ){
    char fc = f(c);
    char fco = fc + 'a' - 'A';
    if( needed[fc] <= available[fco] ){
      whoops += needed[fc];
      available[fco] -= needed[fc];
      needed[fc] = 0;
    }else{
      whoops += available[fco];
      needed[fc] -= available[fco];
      available[fco] = 0;
    }
    
    fc += 'a' - 'A'; // A -> a
    fco -= 'a' - 'A'; // a -> A
    if( needed[fc] <= available[fco] ){
      whoops += needed[fc];
      available[fco] -= needed[fc];
      needed[fc] = 0;
    }else{
      whoops += available[fco];
      needed[fc] -= available[fco];
      available[fco] = 0;
    }
  }

  cout << yay << ' ' << whoops << endl;

  return 0;
}

// AC
