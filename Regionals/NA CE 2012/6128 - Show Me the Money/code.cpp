#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

#define debug(x) cerr << #x << " = " << (x) << endl;
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vpi> vvp;

ostream& operator<<(ostream& os, const pii p){
  return os << "(" << p.first << ", " << p.second << ")";
}

void printm(const vvp& mat){
  rep(i, 0, 7){
    rep(j, 0, 7){
      cout << mat[i][j] << "   ";
    }
    cout << endl;
  }
}

int gcd(int a, int b){
  if( a < b )
    swap(a, b);
  while( b != 0 ){
    int t = a;
    a = b;
    b = t % b;
  }

  return a;
}

bool operator==(const pii& a, const pii& b){
  return a.first == b.first && a.second == b.second;
}

pii operator+(const pii& a, const pii& b){
  if( a == make_pair(0, 0) )
    return b;
  if( b == make_pair(0, 0) )
    return a;

  if( a.second == 0 || b.second == 0)
    cout << "XXXXXXXXXXXXXXXXXXXXX" << endl;
  
  int n = a.first*b.second + a.second*b.first;
  int d = a.second*b.second;
  int g = 1;
  g = gcd(n,d);
  n /= g;
  d /= g;
  return {n, d};
}

pii operator*(const pii& a, const pii& b){
  return {a.first*b.first, a.second*b.second};
}

bool operator<(const pii& a, const pii& b){
  return a.first*b.second < a.second*b.first;
}

void close(vvp& m){
  rep(k, 0, 7){
    rep(i, 0, 7){
      rep(j, 0, 7){
	if( m[i][j] == mp(0, 0) ){
	  m[i][j] = m[i][k]*m[k][j];
	}else if( m[i][k]*m[k][j] < m[i][j] ){
	  m[i][j] = m[i][k]*m[k][j];
	}
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  while( n != 0 ){
    vvp mat(8, vpi(8, {0, 0}));
    map<string, int> msi;
    
    rep(i, 1, n){
      int a, b;
      string ca, cb, equals;
      cin >> a >> ca >> equals >> b >> cb;

      if( msi.find(ca) == msi.end() )	msi[ca] = msi.size()-1;
      if( msi.find(cb) == msi.end() )	msi[cb] = msi.size()-1;

      int ida = msi[ca];
      int idb = msi[cb];
      
      mat[ida][idb] = {b, a};
      mat[idb][ida] = {a, b};
    }

    rep(i, 0, 7){
      mat[i][i] = {1, 1};
    }

    /*rep(i, 0, 7){
      rep(j, 0, 7){
	cout << mat[i][j] << "   ";
      }
      cout << endl;
    }*/
    
    int q;
    string cq;
    cin >> q >> cq;
    int idq = msi[cq];

    close(mat);
    
    /*cout << endl << endl;
    rep(i, 0, 7){
      rep(j, 0, 7){
	cout << mat[i][j] << "   ";
      }
      cout << endl;
    }
    cout << endl << endl;*/

    string cans;
    int ans;
    double eqans = 1e20;
    for(pair<string, int> p: msi){
      int id = p.second;
      
      //debug(mat[idq][id]);
      if( mat[idq][id] != make_pair(0, 0) && id != idq ){
	double x = (double)q*mat[idq][id].first/mat[idq][id].second;
	  
	if( ceil(x) <= 1e5 ){
	  double realv = ceil(x)*mat[id][idq].first/mat[id][idq].second;

	  if( realv < eqans ){
	    eqans = realv;
	    ans = (int) ceil(x);
	    cans = p.first;
	  }
	}
      }
    }

    cout << ans << " " << cans << endl;
    
    cin >> n;
  }
  return 0;
}

// check if less than 1e5!
