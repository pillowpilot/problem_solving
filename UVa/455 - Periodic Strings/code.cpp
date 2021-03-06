#include <iostream>
#include <string>

using namespace std;

bool strcmp(const string& s, int a, int b, int n){
  if( n == 0 ) return true;
  else return s[a] == s[b] && strcmp(s, a+1, b+1, n-1);
}

int solve(const string& s){
  int k = 1; // Possible period
  while( k < s.size() ){
    
    int i = 0; // Substring begin
    while( i < s.size() ){

      if( strcmp(s, 0, i, k) == false ) break;
      
      i += k;
    }
    if( i >= s.size() ){
      return k;
    }
    
    k++;
  }
  // No periodicity found
  return s.size();
}

int main(){
  std::ios_base::sync_with_stdio(false);
  
  int n;
  string s;

  cin >> n;
  for( int i = 0; i < n; i++ ){
    cin >> s;
    int r = solve(s);
    cout << r;
    if( i != n-1 ) cout << endl << endl;
    else cout << endl;
  }
  
  return 0;
}

// AC
