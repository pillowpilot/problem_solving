#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPentagonal(int p){
  double disc = sqrt( 1+24*p );
  if( (disc - (int)disc) > 1e-10 )
    return false;
  else{
    return (1+(int)disc)%6 == 0;
  }
}

int main(){

  int limit = 1e8;

  vector<int> pp;

  int n = 1;
  int p;
  while( (p=n*(3*n-1)/2) < limit ){
    pp.push_back(p);
    n++;
  }

  cout << "pp.size()=" << pp.size() <<endl;

  bool exit = false;
  for(int i = 0; i < pp.size(); i++){
    const int dif = pp[i];
    int j = 0;
    while( j < pp.size() ){
      const int pj = pp[j];
      if( isPentagonal( dif + pj ) && isPentagonal( dif + pj + pj ) ){
	cout << dif << endl;
	exit = true;
	break;
      }
      j++;
    }
    if( exit ) break;
  }
  
  return 0;
}

// AC ans=5482660
/*
  solve for n to deduce isPentagonal
  generate all pentagonal up to a limit (high enough)
  and brute for then (notice that D is also a pentagonal so assume D and go on)
 */
