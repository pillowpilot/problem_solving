#include <cstdio>

using namespace std;

int main(){
  double H, U, D, F, height, step, days, fatigue;
  bool working;
  
   do{
    scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
    if(H != 0){
      height = 0; 
      days = 0;
      step = U; 
      working = true;
      fatigue = U * (F / 100);

      while(true){
	days++;
	height += step;
	if( height > H ) break;

	height -= D;
	if( height < 0 ) break;

	if( step - fatigue > 0 ) step -= fatigue;
	else step = 0;
	//printf("Height: %lf, Step: %lf, day: %lf\n", height, step, days);
      }
      
      if(height > H){
	printf("success on day %ld\n", (long) days);
      }else{
	printf("failure on day %ld\n", (long) days);
      }
    }
  }while(H != 0);
  
  return 0;
}
