#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
  Binary search over the length of A solution.
  If a solution is found, then the length could be 
  our final solution (min length) or could be greater. 
  If no solution is found, then our final solution must be greater.
  
  More formally, suppouse K:=min length of a solution (our final solution)
  then K in [#different pokemons, length of the string] = [min, max]

  If solution of length k is found, then K in [min, k],
  else K in [k+1, max]

  If K in [min, max] and min=max, then K=min=max.
 */

int main(){
  ios_base::sync_with_stdio(false);
  
  int n; string s;
  cin >> n >> s;

  int dif = 0;
  int see[256] = {0};
  for(int i = 0; i < s.size(); i++){
    if( see[ s[i] ] == 0 ){
      see[ s[i] ] = 1;
      dif++;
    }
  }

  int min = dif;
  int max = s.size();

  while( min != max ){
    int k = min + (max-min)/2;
    //cout << "[" << min << ", " << max << "]"<< ">> " << k << endl;
    
    int inner_dif = 0;
    fill_n(see, 256, 0);
    for(int i = 0; i < k; i++){
      see[ s[i] ]++;
      if( see[ s[i] ] == 1 ) // First time to see that char
	inner_dif++;
    }
    int i = k;
    while( i < s.size() && inner_dif != dif ){
      see[ s[i-k] ]--;
      if( see[ s[i-k] ] == 0 )
	inner_dif--;
      see[ s[i] ]++;
      if( see[ s[i] ] == 1 )
	inner_dif++;
      i++;
    }

    if( inner_dif == dif ){
      // Solution found
      max = k;
    }else{
      min = k+1;
    }
    //cout << "[" << min << ", " << max << "]" << endl;
  }

  //  cout << min << "==" << max << endl;
  cout << max << '\n';
  return 0;
}


// AC
