#include <cstdio>
#include <string>
#include <iostream>

#define CARBONMASS 12.01
#define HYDROGENMASS 1.008
#define OXYGENMASS 16.00
#define NITROGENMASS 14.01

using namespace std;

int main(){
  string line;
  char e;
  int cases;

  scanf("%d ", &cases);
  while( cases-- > 0 ){
    int offset = 0, charRead;
    double molarMass = 0;
    
    getline(cin, line);
    while( sscanf(line.data() + offset, "%c%n", &e, &charRead) == 1 ){
      int amount = 1;
      offset += charRead;
      sscanf(line.data() + offset, "%d%n", &amount, &charRead);
      if( amount != 1) offset += charRead;
      
      // printf("%c: %d\n", e, amount);
      switch( e ){
      case 'C':
	molarMass += CARBONMASS * amount;
	break;
      case 'N':
	molarMass += NITROGENMASS * amount;
	break;
      case 'O':
	molarMass += OXYGENMASS * amount;
	break;
      case 'H':
	molarMass += HYDROGENMASS * amount;
	break;
      default: // En el caso de \n
	break;
      }
    }
    printf("%.3lf\n", molarMass);
  }
  return 0;
}
