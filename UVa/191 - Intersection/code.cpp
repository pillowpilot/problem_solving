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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tests;
  cin >> tests;
  while( tests-- > 0 ){
    PT a, b, x1, x2, x3, x4;  
    a.read();
    b.read();
    x1.read();
    x2.read();

    if( x1.x > x2.x ) swap(x1.x, x2.x);
    if( x1.y > x2.y ) swap(x1.y, x2.y);
    // x1 is bottom left
    // x2 is up right

    x3.x = x1.x;
    x3.y = x2.y;

    x4.x = x2.x;
    x4.y = x1.y;

    // x3 is up left
    // x4 is bottom right

    // Rectangle lines
    // (x1, x3) (x1, x4) (x2, x3) (x2, x4)

    bool ans = false;
    ans |= x1.x <= a.x && a.x <= x4.x && x1.y <= a.y && a.y <= x3.y;
    ans |= x1.x <= b.x && b.x <= x4.x && x1.y <= b.y && b.y <= x3.y;
    ans |= segmentsIntersect(a, b, x1, x3);
    ans |= segmentsIntersect(a, b, x1, x4);
    ans |= segmentsIntersect(a, b, x2, x3);
    ans |= segmentsIntersect(a, b, x2, x4);    

    if( ans )
      cout << "T\n";
    else
      cout << "F\n";
  }
  
  
  return 0;
}

// AC
/*
  Consider cases when a or b are in rectangle.
  If at least one is in rectangle, then T.
  Else segment ab must intersect at least one (always 2) rectangle side.
 */
