#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int currC;
int maxC;
int fuseCapasity;
vi compData;
vb compState;

void init(){
  maxC = currC = 0;
  compData.clear();
  compState.clear();
}

int main(){
  int n, m, caseID = 1;
  scanf("%d %d %d", &n, &m, &fuseCapasity);
  while( !(n == 0 && m == 0 && fuseCapasity == 0) ){

    init();

    while( n-- > 0 ){
      int cap;
      scanf("%d", &cap);
      compData.push_back(cap);
      // printf("Componente de %d A.\n", cap);
    }

    compState = vb( compData.size(), false );

    while( m-- > 0 ){
      int comp;
      scanf("%d", &comp);
      comp--; // Fixing 0-based array offset
      if( compState[comp] == true ){
	currC -= compData[comp];
	compState[comp] = false;
      }else{
	currC += compData[comp];
	compState[comp] = true;
      }
      // printf("Consumo: %d-%d\n", currC, maxC);
      if( currC > maxC ) maxC = currC;
    }

    printf("Sequence %d\n", caseID++);
    if( maxC > fuseCapasity ){
      printf("Fuse was blown.");
    }else{
      printf("Fuse was not blown.\nMaximal power consumption was %d amperes.", maxC);
    }
    printf("\n\n");

    scanf("%d %d %d", &n, &m, &fuseCapasity);
  }
  return 0;
}
