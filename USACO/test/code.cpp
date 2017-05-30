/*
  ID: carlos.16
  PROG: test
  LANG: C++
 */
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream input("test.in");
  ofstream output("test.out");

  int a, b;
  input >> a >> b;
  output << a+b << endl;
  return 0;
}

// AC
