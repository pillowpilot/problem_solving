#include <cstdio>

using namespace std;

struct Point{
  double x, y;
  Point(){ x = y = 0; }
  Point(double x, double y):x(x), y(y) {}
  Point(const Point& p){ x = p.x; y = p.y; }
  bool operator==(const Point& p){
    return (x == p.x && y == p.y);
  }
};

void diference(Point& a, const Point& b){
  a.x -= b.x;
  a.y -= b.y;
}
void add(Point& a, const Point& b){
  a.x += b.x;
  a.y += b.y;
}
void asig(Point& a, const Point& b){
  a.x = b.x;
  a.y = b.y;
}

bool readPoint(Point& p){
  double x, y;

  if( scanf("%lf %lf", &x, &y) == 2){
    p.x = x;
    p.y = y;
    return true;
  }else{
    return false;
  }
}

int main(){
  Point a, b, c, d;
  Point O, A, B, C;

  while( readPoint(a) && readPoint(b) && readPoint(c) && readPoint(d) ){
    // Find Common point... a != b && c != d by problem definition
    if( b == c ){
      O = Point(b);
      A = Point(a);
      B = Point(d);
    }else if( a == c ){
      O = Point(a);
      A = Point(b);
      B = Point(d);
    }else if( b == d ){
      O = Point(b);
      A = Point(a);
      B = Point(c);
    }else{ // a == d
      O = Point(a);
      A = Point(b);
      B = Point(c);
    }

    diference(A, O);
    diference(B, O);

    C = Point(0, 0);
    add(C, A);
    add(C, B);
    add(C, O);

    printf("%.3lf %.3lf\n", C.x, C.y);
  }
  
}

// AC
