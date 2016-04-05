#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull dif(ull a, ull b){
  if( a > b ) return a - b;
  else return b - a;
}

int main(){
  ull a, b;
  while( cin >> a >> b ){
    cout << dif(a, b) << endl;
  }
}
