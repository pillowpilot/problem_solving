#include <iostream>
#include <string>

using namespace std;

int main(){
  string msg;
  string codes[10];

  cin >> msg;
  for(int i = 0; i < 10; i++) cin >> codes[i];

  for(int i = 0; i < 8; i++){
    int j = 0;
    while( msg.substr(10*i, 10) != codes[j] ) j++;
    cout << j;
  }
  cout << endl;
  return 0;
}

// AC
