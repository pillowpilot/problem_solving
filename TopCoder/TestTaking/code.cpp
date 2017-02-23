#include <iostream>
#include <cmath>

using namespace std;

class TestTaking{
public:
  int findMax(int q, int g, int a){
    if( g <= a )
      return g + (q-a);
    else
      return a + (q-g);
  }
};
// AC
