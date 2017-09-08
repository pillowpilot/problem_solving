#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)

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
  istream& read(){
    return cin >> x >> y;
  }
};

bool cmpx(const PT& a, const PT& b){ return a.x<b.x || (fabs(a.x-b.x)<EPS && a.y<b.y); }
bool cmpy(const PT& a, const PT& b){ return a.y<b.y || (fabs(a.y-b.y)<EPS && a.x<b.x); }

ostream& operator<<(ostream& os, const PT& p){
  return os << "(" << p.x << ", " << p.y << ")";
}

double dot(PT a, PT b){ return a.x*b.x+a.y*b.y; }
double dist2(PT a, PT b){ return dot(a-b, a-b); }
double cross(PT a, PT b){ return a.x*b.y-a.y*b.x; }

// project point c onto line segment through a and b
PT projectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if(fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if(r < 0)return a;
  if(r > 1)return b;
  return a + (b-a)*r;
}

double distancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, projectPointSegment(a, b, c)));
}

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

struct segment{
  PT a, b;
  int id;
  segment(PT a, PT b, int id): a(a), b(b), id(id) {}  
};

bool segmentsIntersect(segment a, segment b){
  return segmentsIntersect(a.a, a.b, b.a, b.b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  PT m;
  while( m.read() ){
    int n;
    cin >> n;

    vector<PT> pp;
    rep(i, 0, n+1){
      PT a;
      a.read();
      pp.push_back(a);
    }

    PT ansp;
    double ansd2 = 1e100;
    rep(i, 0, pp.size()-1){
      PT proy = projectPointSegment(pp[i], pp[i+1], m);
      //cout << proy << endl;
      double d2 = dist2(m, proy);

      /*cout << proy << endl;
      cout << d2 << endl;
      cout << endl;*/
      
      if( d2 < ansd2 ){
	ansd2 = d2;
	ansp = proy;
      }
    }

    cout << fixed << setprecision(4) << ansp.x << "\n";
    cout << fixed << setprecision(4) << ansp.y << "\n";
    //cout << "**********************" << endl;
  }
  
  
  return 0;
}

// AC
/*
  The railway is a set of continous (not necesarily colinear) segments.
  For each segment find the projection of M to it. 
  The projection must belong to the segment and its distance is minimum.
  Keep the projection will minimum distance.
 */
