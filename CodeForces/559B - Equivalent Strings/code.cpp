#include <iostream>
#include <string>

using namespace std;

string getSmallest(const string& s){
  int ss = s.size();
  if( ss % 2 != 0 )
    return s;

  string a = getSmallest(s.substr(0, ss/2));
  string b = getSmallest(s.substr(ss/2, ss/2));
  if( a < b )
    return a + b;
  else
    return b + a;
}

int main(){
  string a, b;
  cin >> a >> b;
  string ap = getSmallest(a);
  string bp = getSmallest(b);
  if( ap == bp )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

// AC
