#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

inline int build(const vector<int>& perm, int i, int j){
  int n = 0;
  do{
    n *= 10;
    n += perm[i];
    i++;
  }while( i <= j );
  return n;
}

int main(){

  vector<int> perm{1, 2, 3, 4, 5, 6, 7, 8, 9};
  set< int > set;
  
  do{

    for(int i = 0; i <= 6; i++){
      for(int j = i+1; j < perm.size()-1; j++){
	int a = build(perm, 0, i);
	int b = build(perm, i+1, j);
	int c = build(perm, j+1, perm.size()-1);
	
	if( (unsigned long long) (a) * b == c ){
	  cout << a << "x" << b << "=" << c << " ";
	  if( set.find( c ) == set.end() ){
	    set.insert( c );
	    cout << "*";
	  }
	  cout << endl;
	}
      }
    }
    
  }while( next_permutation(perm.begin(), perm.end()) );

  int sum = 0;
  for(int c: set)
    sum += c;

  cout << sum << endl;
  
  return 0;
}

// AC
