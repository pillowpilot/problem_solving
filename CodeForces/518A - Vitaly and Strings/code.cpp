#include <iostream>
#include <string>

using namespace std;

int main(){
  int i;
  string s, t, u;

  cin >> s >> t;

  // Find next string u lexicographically larger than s
  // O(|s|)
  u = string(s);
  i = u.size() - 1;
  while( i >= 0 && u[i] == 'z' ){
    u[i] = 'a';
    i--;
  }
  if( i >= 0 ) u[i]++;

  // If u < t, then it is a valid solution
  // O(|s|)
  if( u < t ) cout << u << endl;
  else cout << "No such string" << endl;
  
  
  return 0;
}

// AC
