#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

string s;
vi sa;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";

  typename vector<T>::const_iterator iter = v.begin();
  if( iter != v.end() ){
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }

  os << "]";
}

bool strcmp(int a, int b){
  while( a < s.size() && b < s.size() && s[a] == s[b] ){
    a++; b++;
  }

  if( a == s.size() ) return true;
  else if( b == s.size() ) return false;
  else if( s[a] < s[b] ) return true;
}

void buildSuffixArray(){
  sa = vi();
  
  for( int i = 0; i < s.size(); i++ ) sa.push_back(i);

  //  cout << "-- " << sa << endl;

  sort(sa.begin(), sa.end(), strcmp);
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;

  cin >> n;
  while( n-- > 0 ){
    cin >> s;

    s += s; // Really important!!
    //    cout << ">> " << s << endl;

    buildSuffixArray();
    //    cout << sa << endl;

    int i = 0;
    while( sa[i] > s.size() / 2 ) i++;

    cout << sa[i] + 1 << "\n";
  }
  cout << endl;
  return 0;
}

// TLE
