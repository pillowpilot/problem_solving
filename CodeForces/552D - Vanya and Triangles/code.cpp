#include <cstdio>
#include <vector>

using namespace std;

struct Point{
  int x, y;
  Point(){
    x = y = 0;
  }
  Point(int a, int b){
    x = a;
    y = b;
  }
};

typedef vector<Point> vp;

vp ps;

void init(){
  ps = vp();
  ps.reserve(2015);
}

Point substract(const Point& a, const Point& o){
  Point p;
  p.x = a.x - o.x;
  p.y = a.y - o.y;
  return p;
}


bool isTriangle(const Point& a, const Point& b, const Point& c){
  Point x = substract(b, a);
  Point y = substract(c, a);

  int area = x.x * y.y - x.y * y.x;
  return (area != 0);
}

int solve(){
  int tric = 0;

  if( ps.size() >= 3 ){
    for( int i = 0; i < ps.size() - 2; i++ ){
      for( int j = i + 1; j < ps.size() - 1; j++ ){
	for( int k = j + 1; k < ps.size() - 0; k++ ){
	  
	  if( isTriangle(ps[i], ps[j], ps[k]) ){
	    tric++;
	    //	    printf("(%d, %d) (%d, %d) (%d, %d)\n", ps[i].x, ps[i].y, ps[j].x, ps[j].y, ps[k].x, ps[k].y);
	  }
	}
      }
    }
  }
  
  return tric++;
}

int main(){
  int n;

  init();
  scanf("%d", &n);
  while( n-- > 0 ){
    int a, b;
    scanf("%d %d", &a, &b);
    ps.push_back( Point(a, b) );
  }

  n = solve();
  printf("%d", n);
  return 0;
}
