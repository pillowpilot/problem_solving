#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi ffi;
vi ff;
vi bb;
vi aa;

int main(){
  bool amb = false, imp = false;
  int n, m;

  ffi = vi( 101010, 0);
  ff  = vi();
  bb  = vi();
  aa  = vi();
  
  cin >> n >> m;
  while( n-- > 0 ){
    int a;
    cin >> a;
    ff.push_back( a );
    if( ffi[a] == 0 ) ffi[a] = ff.size();
    else amb = true;
  }
  n = ff.size();
  while( m-- > 0 ){
    int a;
    cin >> a;
    bb.push_back( a );
    if( ffi[a] == 0 ) imp = true;
  }
  m = bb.size();
  if( imp ) cout << "Impossible" << endl;
  else if( amb ) cout << "Ambiguity" << endl;
  else{
    cout << "Possible" << endl;
    for(int b: bb){
      aa.push_back( ffi[b] );
      cout << ffi[b] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}
