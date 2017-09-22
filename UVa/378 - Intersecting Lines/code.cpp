#include <bits/stdc++.h>

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

  int n;
  cin >> n;
  cout << "INTERSECTING LINES OUTPUT\n";
  while( n-- > 0 ){
    PT a, b, x, y;
    a.read();
    b.read();
    x.read();
    y.read();

    if( linesCollinear(a, b, x, y ) )
      cout << "LINE\n";
    else if( linesParallel(a, b, x, y) )
      cout << "NONE\n";
    else{
      PT i = computeLineIntersection(a, b, x, y);
      cout << "POINT " << fixed << setprecision(2) << i.x << " " << i.y << "\n";
    }
      
  }
  cout << "END OF OUTPUT\n";
    
  
  return 0;
}

// AC
/*
  Trivial use of library.
 */
