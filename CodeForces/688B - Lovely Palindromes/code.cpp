#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  string input;

  cin >> input;

  cout << input;
  reverse(input.begin(), input.end());
  cout << input;
  
  return 0;
}


// AC
