#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef vector<double> vd;

vd vr;
double minSum;

void print(){
  vd::const_iterator iter = vr.begin();
  while( iter != vr.end() ){
    printf("%lf ", *iter);
    iter++;
  }
  printf("\n");
}

void  checkAll(){
  //Se asume que vector contine al menos un radio!.
  minSum = numeric_limits<double>::max();
  sort(vr.begin(), vr.end());
  do{
    //    printf("Comprobando: ");
    //    print();
    double sum = vr.front() + vr.back();
    //TODO sumar radios inicial y final...
    vd::const_iterator r1 = vr.begin();
    vd::const_iterator r2 = next(r1);
    while( r2 != vr.end() ){
      sum += 2 * sqrt( *r1 * *r2  );
      r1++;
      r2++;
    }
    if( sum < minSum ) minSum = sum;
    //    printf("Se calculo: %lf\n", sum);
  }while( next_permutation( vr.begin(), vr.end() ) );
}

int main(){
  int cases, circles;
  double radii;

  vr.reserve(51);
  scanf("%d", &cases);
  while( cases-- > 0 ){
    scanf("%d", &circles);
    vr.clear();
    while( circles-- > 0){
      scanf("%lf", &radii);
      vr.push_back(radii);
    }
    //    printf("Leido: ");
    //    print();
    if( vr.size() > 0 ){
      checkAll();
    }else{
       minSum = 0;
    }
    printf("%.3lf\n", minSum);
    
  }
  return 0;
}
