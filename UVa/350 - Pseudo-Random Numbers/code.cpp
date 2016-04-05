#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;

vb marks;
vi lengths;

int main(){
  int multi, incre, mod, seed, css = 1;

  while( scanf("%d %d %d %d", &multi, &incre, &mod, &seed) == 4 && multi != 0 && incre != 0 && mod != 0 && seed != 0 ){
    int counter = 0, prev = ( multi * seed + incre ) % mod;

    marks = vb(mod, false);
    marks[seed] = true;

    lengths = vi(mod, 0);
    //lengths[seed] = counter;

    while( marks[prev] == false ){
      marks[prev] = true;
      counter++;
      lengths[prev] = counter;
      prev = ( multi * prev + incre ) % mod;
    }

    printf("Case %d: %d\n", css, counter - lengths[prev] + 1);
    css++;
    
  }
  return 0;
}

// AC
