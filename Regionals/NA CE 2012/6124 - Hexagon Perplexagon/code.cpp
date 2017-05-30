#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << endl;

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

void rotate(vi& p){
  int last = p[p.size()-1];
  for(int i = p.size()-1; i > 0; i--){
    p[i] = p[i-1];
  }
  p[0] = last;
}

void shift(vi& p, int d){
  vi a(p);
  rep(i, 0, a.size()-1){
    p[(i+d)%p.size()] = a[i];
  }
}

int distance(vi& p, int e, int n){
  int c = 0;
  while( p[e] != n ){
    e = (e==0)?5:e-1;
    c++;
  }
  return c;
}

vi a(6);
void fastshift(vi& p, int e, int n){
  int d = 0;
  while( p[e] != n ){
    e = (e==0)?5:e-1;
    d++;
  }
  a = p;
  rep(i, 0, a.size()-1){
    p[(i+d)%p.size()] = a[i];
  }
}

vvi m;
bool check(const vi& p){
  // p.size(0 == 7)
  int h0 = p[0];
  int h1 = p[1];
  int h2 = p[2];
  int h3 = p[3];
  int h4 = p[4];
  int h5 = p[5];
  int h6 = p[6];

  fastshift(m[h0], 0, 1);
  fastshift(m[h1], 3, m[h0][0]);
  fastshift(m[h2], 4, m[h0][1]);
  fastshift(m[h3], 5, m[h0][2]);
  fastshift(m[h4], 0, m[h0][3]);
  fastshift(m[h5], 1, m[h0][4]);
  fastshift(m[h6], 2, m[h0][5]);
	    
  /*shift(m[h0], distance(m[h0], 0, 1));
  shift(m[h1], distance(m[h1], 3, m[h0][0]));
  shift(m[h2], distance(m[h2], 4, m[h0][1]));
  shift(m[h3], distance(m[h3], 5, m[h0][2]));
  shift(m[h4], distance(m[h4], 0, m[h0][3]));
  shift(m[h5], distance(m[h5], 1, m[h0][4]));
  shift(m[h6], distance(m[h6], 2, m[h0][5]));*/
  
  /*while( m[h1][3] != m[h0][0] ) rotate(m[h1]);
  while( m[h2][4] != m[h0][1] ) rotate(m[h2]);
  while( m[h3][5] != m[h0][2] ) rotate(m[h3]);
  while( m[h4][0] != m[h0][3] ) rotate(m[h4]);
  while( m[h5][1] != m[h0][4] ) rotate(m[h5]);
  while( m[h6][2] != m[h0][5] ) rotate(m[h6]);*/
  
  if( m[h1][2] != m[h2][5] ) return false;
  if( m[h2][3] != m[h3][0] ) return false;
  if( m[h3][4] != m[h4][1] ) return false;
  if( m[h4][5] != m[h5][2] ) return false;
  if( m[h5][0] != m[h6][3] ) return false;
  if( m[h6][1] != m[h1][4] ) return false;

  return true;
}

bool heaps(vi& ans, int n){
  if( n == 1 ){
    //cout << ans << endl;
    return check(ans);
  }
  rep(i, 0, n-1){
    bool result = heaps(ans, n-1);
    if( result )
      return result;
    
    if( n % 2 == 1 )
      swap(ans[0], ans[n-1]);
    else
      swap(ans[i], ans[n-1]);
  }
  return false;
}

int main(){

  int n;
  cin >> n;
  rep(cs, 1, n){
    m.clear();
    rep(i, 1, 7){
      vi v;
      rep(j, 1, 6){
	int x;
	cin >> x;
	v.pb(x);
      }
      m.pb(v);
    }

    vi ans;
    ans.clear();
    rep(i, 0, 6){
      ans.pb(i);
    }
    //ans = {3, 0, 5, 6, 1, 4, 2};

    bool found = heaps(ans, ans.size());
    /*bool found=false;
    do{
      //cout << ans << " " << found << endl;
      if( check(ans) ){
	found = true;
      }
    }while( !found && next_permutation(all(ans)));*/
    
    cout << "Case " << cs << ": ";
    if( found ){
      rep(i, 0, 5)
	cout << ans[i] << " ";
      cout << ans[6] << endl;
    }else{
      cout << "No solution" << endl;
    }
    
  }
  
  return 0;
}

// TLE
