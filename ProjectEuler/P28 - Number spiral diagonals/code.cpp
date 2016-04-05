#include <iostream>

using namespace std;

int main(){
  const int grid_size = 1001;
  unsigned long long m = int ( grid_size / 2 );
  cout << (16*m*m*m + 30*m*m + 26*m + 3)/3 << endl;
  return 0;
}

/*
  Notamos que si a cada "nivel" (cuadrados desde el centro) identificamos
  cada esquina como a_n, b_n, c_n y d_n, donde a_n esta en la equina superior
  derecha y continuamos en sentido horario, entonces tenemos las funciones 
  recursivas:
  a_0 = b_0 = c_0 = d_0 = 1
  a_n = a_{n-1} + 8n
  b_n = a_{n-1} + 2n
  c_n = a_{n-1} + 4n
  d_n = a_{n-1} + 6n
  
  Donde concluimos que
  a_n = 4*n^2 + 4*n + 1
  b_n = 4*n^2 - 2*n + 1
  c_n = 4*n^2       + 1
  d_n = 4*n^2 - 2*n + 1
  Para todo n entero positivo.

  Finalmente, sum_{n=0}^m (a_n+b_n+c_n+d_n) = (16*m^3 + 30*m^2 + 26*m + 3)/3
  donde m = floor( grid size / 2 )
 */

// AC
