#include <iostream>
#include <vector>

using namespace std;

int d(int n){
  int i = 2, sum = 1;
  while( i*i <= n ){
    if( n % i == 0 ){
      sum += i;
      if( n != i*i ) // Check if n is perfect square
	sum += n/i;
    }
    i++;
  }
  return sum;
}

int main(){
  const int limit = 28123;
  vector<int> abundants = vector<int>();

  // Get all abundants less than limit
  for( int i = 1; i < limit; i++ ){
    if( d(i) > i ){
      abundants.push_back(i);
    }
  }
  cout << "Abundant numbers below " << limit << ": " << abundants.size() << endl;

  // Check all numbers that can be written as the sum of 2 abundants
  vector<bool> check = vector<bool>(limit, false);
  for(int a: abundants)
    for(int b: abundants)
      if( a + b < check.size() ){
	check[ a + b ] = true;
      }

  // Check over all numbers below the limit
  int sum = 0;
  for(int i = 1; i < check.size(); i++)
    if( check[i] == false ){
      cout << i << endl;
      sum += i;
    }

  cout << sum << endl;
  
  return 0;
}

// AC
