#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;

vb marks;

int main(){
  int step, mod;

  while( scanf("%d %d", &step, &mod) == 2 ){
    int counter = 0, initial, prev;
    initial = prev = step % mod;
    marks = vb(mod, false);

    marks[initial] = true;
    counter++;
    do{
      prev = (prev+step)%mod;
      if( marks[prev] == false ){
	counter++;
	marks[prev] = true;
      }
    }while( prev != initial );

    printf("%10d%10d    ", step, mod);
    if( counter == mod ){
      printf("Good Choice\n\n");
    }else{
      printf("Bad Choice\n\n");
    }
  }
  return 0;
}

// AC Better Solution: gcd(step, mod) = 1 -> Good Choice
