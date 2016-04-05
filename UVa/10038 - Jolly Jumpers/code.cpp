#include <stdio.h>
#include <bitset>
#include <cmath>

using namespace std;

int main(){
  int n, a, b, difAmount, diference;
  bitset<3002> diferences;

  while(scanf("%d", &n) == 1 && n > 0 && n <= 3000){
    diferences.reset(); //Posible (pequeña) mejora de rendimiento. Solo recorrer los primeros n bits.
    difAmount = 0;

    scanf("%d", &a);
    for(int i = 0; i < n - 1; i++){
      scanf("%d", &b);
      diference = abs(a - b); //Posible mejora de rendimiento.
      if( diference > 0 && diference < n && diferences.test( diference ) == false ){
	diferences.set( diference );
	difAmount++;
      }
      a = b;
    }

    scanf("%*c"); //Quemar fin de linea
    if( difAmount == n - 1 ){
      printf("Jolly\n");
    }else{
      printf("Not jolly\n");
    }
  }
	
      
  return 0;
}
