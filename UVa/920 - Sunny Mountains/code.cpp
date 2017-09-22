#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

const double EPS = 1e-10;

struct PT{
  double x, y;
  PT(): x(0), y(0) {}
  PT(double x, double y): x(x), y(y) {}
  PT(const PT& o): x(o.x), y(o.y) {}
  PT operator+(const PT& o) const{ return PT(x+o.x, y+o.y); }
  PT operator*(double c) const{ return PT(x*c, y*c); }
  PT operator-(const PT& o) const{ return *this+o*-1; }
  PT operator/(double c) const{ return *this*(1/c); }
  void read(){
    cin >> x >> y;
  }
};

bool cmpx(const PT& a, const PT& b){ return a.x<b.x || (fabs(a.x-b.x)<EPS && a.y<b.y); }

ostream& operator<<(ostream& os, const PT& p){
  return os << "(" << p.x << ", " << p.y << ")";
}

double dot(PT a, PT b){ return a.x*b.x+a.y*b.y; }
double dist2(PT a, PT b){ return dot(a-b, a-b); }
double cross(PT a, PT b){ return a.x*b.y-a.y*b.x; }
bool linesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b-a, c-d)) < EPS;
}
bool linesCollinear(PT a, PT b, PT c, PT d) {
  return linesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}
bool segmentsIntersect(PT a, PT b, PT c, PT d) {
  if(linesCollinear(a, b, c, d)) {
    if(dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS)
      return true;
    if(dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if(cross(d-a, b-a)*cross(c-a, b-a) > 0)
     return false;
  if(cross(a-c, d-c)*cross(b-c, d-c) > 0)
    return false;
  return true;
}

PT computeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tests;
  cin >> tests;
  while( tests-- > 0 ){
    int n;
    cin >> n;

    vector<PT> v;
    rep(i, 0, n){
      PT a;
      a.read();
      v.push_back(a);
    }
    sort(all(v), cmpx);

    cout << "---" << endl;
    rep(i, 0, v.size()){
      cout << v[i] << endl;
    }
    cout << "---" << endl;

    double ans = 0;
    double curmaxy = 0;
    PT a = v.back();
    for(int i = v.size()-2; i >= 0; i--){
      PT b = v[i];
      if( b.y > curmaxy ){
	PT p(1, curmaxy);
	PT q(0, curmaxy);
	PT x = computeLineIntersection(a, b, p, q);
	cout << x << endl;
	cout << sqrt(dist2(x, b)) << endl;
	ans += sqrt(dist2(x, b));
	curmaxy = b.y;
      }
      //cout << a << b << endl;      
      a = b;
    }
    cout << fixed << setprecision(2) << ans << endl;
  }
  
  return 0;
}

// AC
/*
  Iterate segments from the right to the left.
  (Sort by x, and iterate from back to begin)
  Keep a maxy (init at 0) to check if a given segment recive sunlight
  If it does, then compute its intersection x with an horizontal line passing through x
  Get euclidean distance and add.
 */
