#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;
typedef set<vi> svi;

ostream& operator<<(ostream& os, const vi& v){
  os << "[";
  if( v.size() != 0 ){
    vi::const_iterator iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  return os << "]";
}

int c;
svi s;
void heaps(vi& v, int n){
  if( n==1 ){
    cout << v << endl, c++;
    s.insert(v);
  }else{
    rep(i, 0, n-1){
      heaps(v, n-1);
      if( n%2 == 1 )
	swap(v[0], v[n-1]);
      else
	swap(v[i], v[n-1]);
    }
    //heaps(v, n-1);
  }
}
int main(){
  vi v = {0, 1, 2, 3};
  heaps(v, v.size());
  cout << c << endl;
  cout << s.size() << endl;
}
