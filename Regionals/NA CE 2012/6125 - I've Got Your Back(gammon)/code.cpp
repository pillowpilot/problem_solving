#include <iostream>
#include <vector>
#include <algorithm>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

ostream& operator<<(ostream& os, const vi& v){
  os << "[";
  if( v.size() != 0 ){
    auto iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  os << "]";
  return os;
}

vvi m(2e4, vi(6, 0));
void init(){
  int x = 0;
  rep(a, 0, 15){
    rep(b, 0, 15){
      rep(c, 0, 15){
	rep(d, 0, 15){
	  rep(e, 0, 15){
	    int f = 15 - (a+b+c+d+e);
	    if( 0 <= f ){
	      //cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
	      m[x][0] = a;
	      m[x][1] = b;
	      m[x][2] = c;
	      m[x][3] = d;
	      m[x][4] = e;
	      m[x][5] = f;	      
	      x++;
	    }
	  }
	}
      }
    }
  }
  //cout << x << endl;
  m.resize(x);
}


int main(){
  init();
  char q;
  cin >> q;

  int cs = 1;
  while( q != 'e' ){
    if( q == 'm' ){
      vi v(6);
      rep(i, 0, 5){
	int x;
	cin >> x;
	v[i] = x;
      }

      int index = lower_bound(all(m), v) - m.begin();
      cout << "Case " << cs << ": " << index << endl;
    }else{
      int index;
      cin >> index;

      cout << "Case " << cs << ": ";
      vi v = m[index];
      rep(i, 0, 4){
	cout << m[index][i] << " ";
      }
      cout << m[index][5] << endl;
    }
    cin >> q;
    cs++;
  }
  
  return 0;
}

// AC
