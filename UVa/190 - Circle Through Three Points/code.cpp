#include <bits/stdc++.h>

using namespace std;

// Personalized

// Double primitive wrapper
struct Double{
#if __cplusplus <=199711L
  // pre C++11
  // access: Double::EPS
  static const double EPS = 1e-9;
  static const double INF = 1e100;
#else
  // C++11 201103L
  static constexpr double EPS = 1e-9;
  static constexpr double INF = 1e100;
#endif
  double v;
  
  Double(): v(0.0) {} // Keep it to zero!
  Double(double v): v(v) {}
  operator double() const { return v;} // Implicit conversion to double
  inline int cmp(double a, double b) const {
    if( fabs(a-b) < EPS ) return 0;
    if( a < b ) return -1; else return 1;
  }
  
#define smplOp(X) Double operator X (const Double o) const { return Double(v X o.v); }
  smplOp(+) smplOp(-) smplOp(*) smplOp(/)
#undef smplOp
    Double operator-() const { return Double(-v); }
  
  bool operator==(const Double& o) const { return cmp(v, o.v)==0; }
  bool operator!=(const Double& o) const { return !(*this==o); }
  bool operator<(const Double& o) const { return cmp(v, o.v)==-1; }
  bool operator>(const Double& o) const { return cmp(v, o.v)==+1; }
  bool operator<=(const Double& o) const { return !(*this>o); }
  bool operator>=(const Double& o) const { return !(*this<o); }

  istream& read(){ return cin >> v; }
  friend istream& operator>>(istream& is, Double& d){ return is >> d.v; }
  friend ostream& operator<<(ostream& os, const Double& d){ return cout << d.v; }
  friend Double sqrt(const Double& ang){ assert(ang>=Double()); return Double(std::sqrt(ang.v)); }
#define trgFun(X) friend Double X(const Double& a){ return Double(std::X(a.v)); }
  trgFun(sin) trgFun(cos) trgFun(tan) trgFun(atan)
#undef trgFun
  friend Double asin(Double a){ assert(Double(-1)<=a && a<=Double(1)); return std::asin(a.v); }
  friend Double acos(Double a){ assert(Double(-1)<=a && a<=Double(1)); return std::acos(a.v); }
};

/*
  Point (x, y)
  Vector (x, y) from Origin (0, 0)
 */

struct Point{
  Double x, y;
  Point(): x(0), y(0) {} // Keep it in the origin!
  Point(Double x, Double y): x(x), y(y) {}
  Point operator+(const Point& o) const { return Point(x+o.x, y+o.y); }
  Point operator*(Double c) const { return Point(c*x, c*y); }
  Point operator-(const Point& o) const { return *this+o*Double(-1) ; }
  Point operator/(Double c) const { return *this * (1/c); }
  Point operator-() const { return *this*Double(-1); }
  bool operator==(const Point& o) const { return x==o.x && y==o.y; }

  Double dot(const Point& o) const { return x*o.x+y*o.y; }
  Double cross(const Point& o) const { return x*o.y-y*o.x; }
  Double dist2(const Point& o) const { return (*this-o).dot(*this-o); }

  Point rot90ccw(const Point& p=Point()) const { return Point(-(y-p.y), x-p.x); }
  Point rot90cw(const Point& p=Point()) const { return Point(y-p.y, -(x-p.x)); }
  Point rotccw(double ang, const Point& p=Point()) const {
    return Point(Double(cos(ang))*(x-p.x)-Double(sin(ang))*(y-p.y),
		 Double(sin(ang))*(x-p.x)+Double(cos(ang))*(y-p.y));
  }
  Point perp() const { return rot90ccw(); }  
  
  istream& read(){ return cin >> x >> y; }
  friend istream& operator>>(istream& is, Point& p){ return is >> p.x >> p.y; }
  friend ostream& operator<<(ostream& os, const Point& p){ return os << "(" << p.x << ", " << p.y << ")"; }
};

bool compx(const Point& a, const Point& b){ return a.x < b.x || (a.x==b.x && a.y<b.y); }
bool compy(const Point& a, const Point& b){ return a.y < b.y || (a.y==b.y && a.x<b.x); }

/*
  Dot product
  A, B vectors, D := line through and perpendicular to A
  A*B = 0 iff A and B are perpendicular
  A*B > 0 iff A and B are on the SAME semiplane
  A*B < 0 iff A and B are on OPPOSITES semiplanes
 */
Double dot(const Point& a, const Point& b){ return a.x*b.x+a.y*b.y; }
Double dist2(const Point& a, const Point& b){ return dot(a-b, a-b); }
/*
  Cross product
  A, B vectors
  AxB = 0 iff A and B are colinear
  AxB > 0 iff B points to the LEFT (CCW)
  AxB < 0 iff B points to the RIGHT (CW)
 */
Double cross(const Point& a, const Point& b){ return a.x*b.y-a.y*b.x; }
int ccw(const Point& a, const Point& b, const Point& c){
  Double x = cross(b-a, c-a);
  if( x == Double() ) return 0;
  else if( x < Double() ) return -1;
  else return 1;
}
int ccw(const Point& a, const Point& b){
  Double x = cross(a, b);
  if( x == Double() ) return 0;
  else if( x < Double() ) return -1;
  else return 1;
}

/*
  Line y =  a + t*ab, a in Line and ab parallel to Line
  Segment t in [0, 1], Points between a and a+ab
  Ray t in [0, +inf)
 */
struct Line{
  Point a, ab; // Think of ab as the vector ab
  Line() {}
  Line(const Point& a, const Point& b, bool twoPoints=true):
    a(a), ab( twoPoints ? b-a : b) {}
  
  operator bool() const{ return ab==Point(); } // If Line degenerate to point
  Point b() const{ return a+ab; }
  Point operator()(Double t) const{ return a+ab*t; } // Eval
  bool inLine(const Point& p) const{ return cross(p-a, ab)==Double(); }
  bool inSegment(const Point& p) const{
    if( !inLine(p) ) return false;
    if( dot(ab, p-a) < Double() || dot(-ab, p-b()) < Double() ) return false;
    return true;
  }
  bool isParallelTo(const Line& l) const { return cross(ab, l.ab)==Double(); }
  bool isCollinearTo(const Line& l) const {
    return isParallelTo(l) && cross(a-l.a, ab)==Double();
  }
  bool intersectsSegment(const Line& s) const {
    if( isCollinearTo(s) ){
      if( dist2(a, s.a)==Double() || dist2(a, s.b())==Double() ||
	  dist2(b(), s.a)==Double() || dist2(b(), s.b())==Double() )
	return true;
      if( dot(s.a-a, s.a-b()) > Double() &&
	  dot(s.b()-a, s.b()-b()) > Double() &&
	  dot(s.a-b(), s.b()-b()) > Double() )
	return false;
      return true;
    }
    if( cross(s.b()-a, ab)*cross(s.a-a, ab) > Double() )
      return false;
    if( cross(a-s.a, s.ab)*cross(b()-s.a, s.ab) > Double() )
      return false;
    return true;
  }
  /*
    If collinear, then inf solutions
    If !collinear and parallel, then 0 solutions
   */
  Point intersection(const Line& l) const {    
    Double t(cross(l.a-a, ab) / cross(ab, l.ab));
    return l(t);
  }
  Point projectOverLine(const Point& p) const { return intersection(Line(p, ab.perp(), false)); }
  Point projectOverSegment(const Point& p) const {
    if( ab==Point() ) return a;
    if( dot(ab, p-a) <= Double() ) return a;
    if( dot(-ab, p-b()) <= Double() ) return b();
    return projectOverLine(p);
  }
};

/*
  Circle from center and radius or 3 no colinear points
 */
struct Circle{
  Point c;
  Double r;
  Circle() {}
  Circle(Point c, Double r): c(c), r(r) {}
  Circle(Point x, Point y, Point z){ // Must not be colinear!
    Line xy((x+y)*Double(0.5), (x-y).perp(), false);
    Line xz((x+z)*Double(0.5), (x-z).perp(), false);
    c = xy.intersection(xz);
    r = sqrt(c.dist2(x));
  }
  bool inCircle(const Point p) const { return r*r == dist2(p, c); }
  bool isPoint() const { return r==Double(); } // Degenerate case    
  bool operator==(const Circle other) const {
    return c == other.c && r == other.r;
  }
  vector<Point> intersects(const Line l) const{
    vector<Point> intersections;
    Point x = l.a-c;
    Double A = dot(l.ab, l.ab);
    Double B = dot(x, l.ab);
    Double C = dot(x, x) - r*r;
    Double D = B*B - A*C;
    if( D < Double() ) return intersections;
    intersections.push_back(c+l.a+l.ab*(-B+sqrt(D))/A);
    if ( D > Double() )
      intersections.push_back(c+l.a+l.ab*(-B-sqrt(D))/A);
    return intersections;
  }
  vector<Point> intersects(const Circle other) const {
    vector<Point> intersections;
    Double D = sqrt(c.dist2(other.c));
    if( D > r+other.r || D+min(r, other.r) < max(r, other.r) )
      return intersections;
    Double x = (D*D-other.r*other.r+r*r)/(D*Double(2.0));
    Double y = sqrt(r*r-x*x);
    Point v = (other.c-c)/D;
    intersections.push_back(c+v*x+v.rot90ccw()*y);
    if( y > Double() )
      intersections.push_back(c+v*x-v.rot90ccw()*y);
    return intersections;
  }
  friend istream& operator>>(istream& is, Circle& c){ return is >> c.c >> c.r; }
};

void print1(Circle c){
  //(x  -  3.000)^2  +  (y  +  2.000)^2  =  5.000^2

  cout << "(x ";  
  if( c.c.x < Double() ) cout << "+ ";
  else cout << "- ";
  cout << setprecision(3) << fixed << abs(c.c.x) << ")^2 + ";
    
  cout << "(y ";
  if( c.c.y < Double() ) cout << "+ ";
  else cout << "- ";
  cout << setprecision(3) << fixed << abs(c.c.y) << ")^2 = ";

  cout << setprecision(3) << fixed << abs(c.r) << "^2\n";
}

void print2(Circle c){
  Double a = c.c.x*Double(2);
  Double b = c.c.y*Double(2);
  Double cv = c.r*c.r - c.c.x*c.c.x - c.c.y*c.c.y;
  cout << "x^2 + y^2 ";
  
  if( a < Double() ) cout << "+ ";
  else cout << "- ";
  cout << setprecision(3) << fixed << abs(a) << "x ";
  
  if( b < Double() ) cout << "+ ";
  else cout << "- ";
  cout << setprecision(3) << fixed << abs(b) << "y ";
  
  if( cv >= Double() ) cout << "- ";
  else cout << "+ ";
  cout << setprecision(3) << fixed << abs(cv) << " ";
  
  cout << "= 0\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  Point a, b, c;
  while( cin >> a >> b >> c ){
    Circle x(a, b, c);
    print1(x);
    print2(x);
    cout << "\n";
  }

  return 0;
}

// AC
/*
  Trivial Geometry and Algebra
  Incredible annoying output!!!!  
 */
