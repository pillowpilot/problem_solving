#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<bool> > vvb;
typedef vector< vector<int > > vvi;

vvb b;
vvi l, r;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";

  if( v.size() > 0 ){
    typename vector<T>::const_iterator iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  
  os << "]";
}

template <typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& v){
  os << "[";

  if( v.size() > 0 ){
    typename vector< vector<T> >::const_iterator iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", \n" << *iter;
      iter++;
    }
  }
  
  os << "]";
}

int main(){
  ios_base::sync_with_stdio(false);
  bool flag;
  int n, m;

  cin >> n >> m;
  b = vvb( n, vector<bool>(m, false) );
  l = vvi( n, vector<int >(m, 0    ) );
  r = vvi( n, vector<int >(m, 0    ) );
  for(int i = 0; i < n; i++){
    flag = false;
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      flag = flag || c == '1';
      b[i][j] = (c=='1')?true:false;
    }
    if( flag == false ){
      cout << "-1" << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; i++){
    int j = 0, c = 0;
    while( j < m && b[i][j] == false ) j++;
    for(int offset = 0; offset < m; offset++){
      c = (b[i][(j+offset)%m]==true)?0:c+1;
      l[i][(j+offset)%m]=c;
    }
  }
  
  for(int i = 0; i < n; i++){
    int j = m - 1, c = 0;
    while( j >= 0 && b[i][j] == false ) j--;
    for(int offset = 0; offset < m; offset++){
      int x = (j-offset<0)?m+j-offset:j-offset;
      //cout << i << ", " << x << ", " << offset << endl;
      c = (b[i][x]==true)?0:c+1;
      r[i][x]=c;
    }
  }

  int minimum = 1e9;
  for(int j = 0; j < m; j++){
    int sum = 0;
    for(int i = 0; i < n; i++){
      sum += min(l[i][j], r[i][j]);
    }
    minimum = min(minimum, sum);
  }

  cout << minimum << endl;
  
  return 0;
}


// AC
