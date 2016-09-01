#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi generatePandigital(int n){
  vi v;
  for(int i = 1; i <= n; i++){
    v.push_back(i);
  }
  return v;
}

int toInt(const vi v){
  int n = 0;
  for(int i: v)
    n = n*10 + i;
  return n;
}

bool isPrime(int n){
  if( n < 2 )
    return false;
  if( n == 2 || n == 3 )
    return true;
  if( n % 2 == 0 )
    return false;
  
  int d = 3;
  while( d*d < n && n % d != 0 )
    d+=2;

  return n % d != 0;
  
}

int main(){

  for(int i = 1; i <= 9; i++){
    vi pandigital = generatePandigital(i);
    do{
      if( isPrime( toInt( pandigital ) ) ){
	cout << toInt(pandigital ) << endl;
      }
    }while( next_permutation(pandigital.begin(), pandigital.end()));
  }

  return 0;
}

// AC ans=7652413
// last line of the output
