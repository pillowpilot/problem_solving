#include <cstdio>

using namespace std;

int main(){
  double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
  double Xx, Xy, Ox, Oy, Zx, Zy;
  double Sx, Sy;

  while( scanf(" %lf %lf %lf %lf %lf %lf %lf %lf ", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy ) == 8 ){
    if( Ax == Cx && Ay == Cy ){
      Ox = Ax;
      Oy = Ay;
      
      Xx = Bx;
      Xy = By;

      Zx = Dx;
      Zy = Dy;
    }else if( Bx == Cx && By == Cy ){
      Ox = Bx;
      Oy = By;
      
      Xx = Ax;
      Xy = Ay;

      Zx = Dx;
      Zy = Dy;      
    }else if( Ax == Dx && Ay == Dy ){
      Ox = Ax;
      Oy = Ay;
      
      Xx = Bx;
      Xy = By;

      Zx = Cx;
      Zy = Cy;
    }else{
      Ox = Bx;
      Oy = By;
      
      Xx = Ax;
      Xy = Ay;

      Zx = Cx;
      Zy = Cy;
    }

    Sx = Xx + Zx - Ox;
    Sy = Xy + Zy - Oy;

    printf("%.3lf %.3lf\n", Sx, Sy);
  }
  return 0;
}

// AC
