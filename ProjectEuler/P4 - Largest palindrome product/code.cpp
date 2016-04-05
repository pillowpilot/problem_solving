#include <iostream>

using namespace std;

bool isPalindrome(int n){
  int a = n, b = 0;
  while( n != 0 ){
    int d = n % 10;
    b = b*10 + d;
    n = n / 10;
  }
  return a == b;
}

int main(){
  int maxp = 0;
  for(int i = 0; i < 1000; i++)
    for(int j = 0; j < 1000; j++)
      if( i*j > maxp && isPalindrome(i*j) )
	maxp = i*j;

  cout << maxp << endl;
  
  return 0;
}

// AC
