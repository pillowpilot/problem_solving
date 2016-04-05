#include <iostream>

using namespace std;

int main(){
  cout << "100000" << endl;
  for(int i = 0; i < 99999; i++) cout << "1 ";
  cout << '0' << endl;
  return 0;
}
