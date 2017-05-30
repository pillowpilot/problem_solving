#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << (x) << endl;

using namespace std;

typedef vector<int> vi;

int n;
vi x, y;
vi sx, sy;

void init(){
  sx = vi(n);
  sy = vi(n);

  sx[0] = x[0];
  sy[0] = y[0];
  rep(i, 1, n-1){
    sx[i] = sx[i-1] + x[i];
    sy[i] = sy[i-1] + y[i];    
  }
}

int findIndex(const vi& v, int x){
  return lower_bound(all(v), x) - v.begin()-1;
}

int eval2(const vi& v, const vi& sv, int x){
  int index = findIndex(v, x);

  int sbef = sv[index];
  int saft = sv[sv.size()-1] - sv[index];

  int ans = sbef - index*x + (v.size()-index)*x - saft;

    debug("inside findIndex");
  debug(x);
  debug(index);
  debug(sbef);
  debug(saft);
  debug(ans);
  debug("");
  
  return ans;
}

int eval(const vi& v, const vi& sv, int x){
  int ans = 0;
  rep(i, 0, v.size()-1){
    ans += abs(v[i]-x);
  }
  return ans;
}

int solve(const vi& v, const vi& sv){
  int lower = v[0], high = v[v.size()-1];

  while( lower < high ){
    int mid = (lower+high)/2;
    int x1 = eval(v, sv, mid);
    int x2 = eval(v, sv, mid+1);
    /*debug(lower);
    debug(high);
    debug(mid);
    debug(x1);
    debug(x2);
    debug("");*/

    if( x1 <= x2 ){
      high = mid;
    }else if(x1 > x2){
      lower = mid+1;
    }
  }

  return lower;
}

int main(){
  int c = 1;
  cin >> n;
  while( n != 0 ){
    x.clear();
    y.clear();
    rep(i, 1, n){
      int a, b;
      cin >> a >> b;
      x.pb(a);
      y.pb(b);
    }
    sort(all(x));
    sort(all(y));
    init();
    
    int ansx = solve(x, sx);
    int ansy = solve(y, sy);
    int anst = eval(x, sx, ansx)+eval(y, sy, ansy);

    cout << "Case " << c << ": (" << ansx << "," << ansy << ") " << anst << endl;

    cin >> n;
    c++;
  }
  return 0;
}

// AC
