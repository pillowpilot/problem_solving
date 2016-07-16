#include <iostream>

using namespace std;

int main(){
  int n = 17*2;


  for(int i = 0; i < 20;i++){
    int d;
    cin >> d;

    if( n % d == 0 )
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  cout << "WA" << endl;
  return 0;
}
