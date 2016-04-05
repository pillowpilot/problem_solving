#include <iostream>

using namespace std;

int main(){
  const int limit = 100;

  long long sumOfSquares = 0, squareOfSum = 0;
  for(int i = 1; i <= limit; i++){
    sumOfSquares += i*i;
    squareOfSum  += i;
  }
  squareOfSum *= squareOfSum;

  cout << squareOfSum - sumOfSquares << endl;
  
  return 0;
}

// AC
// O(1) using closed formulas (overflow?)
// n*(n+1)*(3*n*n-n-2)/12;
