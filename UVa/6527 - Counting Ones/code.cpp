#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

double log(double arg, double base){
  return log(arg) / log(base);
}

long countOnes(long i){
  long countOnes = 0;
  
  if(i != 0){
    long digits = long(log(i, 2)) + 1; //Verificar recorrido
    vector<long> sums(digits + 1, 0);
    long sum, segAmount, segFaltante, longSeg = 1;

    for(long exp = 1; exp <= digits; exp++){
      sum = 0;
      longSeg = longSeg << 1;
      segAmount = i / longSeg;
      segFaltante = i % longSeg + 1;

      if(segFaltante > longSeg >> 1){
	sum += segFaltante - (longSeg >> 1);
      }
      sum += (longSeg >> 1 ) * segAmount;
      sums[exp-1] = sum;
    }
    vector<long>::iterator iter;
    for(iter = sums.begin(); iter != sums.end(); iter++){
      countOnes += *iter;
    }
  }
  return countOnes;
}

long countOnesRange(long a, long b){
  return countOnes(b) - countOnes(a - 1);
}

int main(){
  long a, b;
  while(scanf(" %ld %ld \n", &a, &b) == 2){
    printf("%ld\n", countOnesRange(a, b));
  }

  return 0;
}
