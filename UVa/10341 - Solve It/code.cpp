#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

bool noSolution;
int p, q, r, s, t;
ll u;
double solution;

double eval(double x){
  // Soy decreciente !! Pero mi progrador no queria saber sobre Calculo. XD
  double a =  p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2);
  return a + u;
}

void solve(){
  double l = 0, h = 1, eH = eval(h), eL = eval(l), eS;
  noSolution = false;
  if( ( eL > 0 && eH > 0 ) || (eL < 0 && eH < 0) ){
    noSolution = true;
  }else{
    solution = l + ((h-l) / 2);
    eS = eval(solution);
   
    while( abs(eS) > 1e-7 ){
      if( eH > eL ){ // Creciente
	if( eS > 0 ){
	  h = solution;
	}else{
	  l = solution;
	}
      }else{ // Decreciente
	if( eS > 0 ){
	  l = solution;
	}else{
	  h = solution;
	}
      }
      solution = l + ((h-l) / 2);
      eS = eval( solution );
    }
    
  }
}

int main(){
  while( scanf("%d %d %d %d %d %llu", &p, &q, &r, &s, &t, &u) == 6 ){
    solve();
    if( noSolution == true ){
      printf("No solution\n");
    }else{
      printf("%.4lf\n", solution);
    }
  }
  return 0;
}
