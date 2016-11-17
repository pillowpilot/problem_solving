#include <iostream>

using namespace std;

int main(){
  int d;
  while( cin >> d ){
    if( d % 6 == 0 )
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}

// AC
