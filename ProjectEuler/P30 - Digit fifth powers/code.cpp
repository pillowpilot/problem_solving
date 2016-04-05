#include <iostream>

using namespace std;

inline bool isSolution(unsigned long long n, int power){
  unsigned long long sum = 0, t = n;
  while( n != 0 ){
    int d = n % 10;
    for(int i = 2; i < power; i++)
      d *= d;
    sum += d;
    n /= 10;
  }

  return sum == t;
}

int main(){
  const unsigned long long upperlimit = 9e9;
  const unsigned long long lowerlimit = 24e6;
  const int power = 5;

  unsigned long long sum = 0;
  for(unsigned long long i = lowerlimit; i <= upperlimit; i++){
    if( isSolution( i, power ) ){
      sum += i;
      cout << i << "\n";
    }
  }
  cout << "Sum: " << sum << endl;
  
  return 0;
}
