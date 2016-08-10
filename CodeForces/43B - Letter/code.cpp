#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string h, m;
  getline(cin, h);
  getline(cin, m);

  bool possible = true;
  int i = 0;
  while( i < m.size() && possible ){

    if( m[i] != ' ' ){
      int j = 0;
      while( j < h.size() && h[j] != m[i] )
	j++;

      if( j == h.size() )
	possible = false;
      else
	h[j] = ' '; // mark it as used...    
    }
    i++;
  }

  if(possible)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

// AC
