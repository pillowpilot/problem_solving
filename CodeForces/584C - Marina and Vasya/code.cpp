#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int f(const string& a, const string& b){
  int d = 0;
  for(int i = 0; i < a.size(); i++){
    if( a[i] != b[i] ) d++;
  }
  return d;
}

void firstPass(const string& a, const string& b, string& c, int limit){
  bool first = true;
  for( int i = 0; i < limit; i++ ){
    if( a[i] != b[i] ){
      if( first == true )c[i] = a[i];
      else c[i] = b[i];
      first = !first;
    }
  }
}

void secondPass(const string& a, const string& b, string& c, int exception, int t, int d){
  int acc = d/2 + 1;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int n, t, d;
  string a, b, c;

  cin >> n >> t >> a >> b;

  d = f(a, b);
  c = string(n, '_'); // Fill with placeholders...

  if( t < d/2 + 1 ) cout << "-1" << endl;
  else{
    int exception = -1;
    if( d % 2 != 0 ){
      int i = n - 1;
      while( a[i] == b[i] )i--;
      exception = i;
      firstPass(a, b, c, i);
    }else{
      firstPass(a, b, c, n);
    }

    

    cout << c << endl;
  }

  
  return 0;
}
