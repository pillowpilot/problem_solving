#include <cstdio>

using namespace std;

typedef struct{
  double x, y;
} p;

bool equals(p a, p b){
  return ( a.x == b.x && a.y == b.y );
}

p calculate(p p1, p p2, p p3, p p4){
  p a, b, c, f;

  if( equals(p1, p3) ){
    a = p2; b = p1; c = p4;
  }else if( equals(p1, p4) ){
    a = p2; b = p1; c = p3;
  }else if( equals(p2, p3) ){
    a = p1; b = p2; c = p4;
  }else{
    a = p1; b = p2; c = p3;
  }

  f.x = a.x + c.x - b.x;
  f.y = a.y + c.y - b.y;
  
  return f;
}

int main(){
  p p1, p2, p3, p4;
  while( scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) == 8 ){
    p pf = calculate(p1, p2, p3, p4);
    printf("%.3lf %.3lf\n", pf.x, pf.y);
  }
  return 0;
}

// AC
