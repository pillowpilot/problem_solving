#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int perm[5] = {0, 1, 2, 3, 4};
int g[5][5];

ull f(int i, int j){
  i = perm[i];
  j = perm[j];
  return g[i][j] + g[j][i];
}

ull eval(){
  return f(0, 1) + f(1, 2) + 2*f(2, 3) + 2*f(3, 4);
}

int main(){
  
  for(int i = 0; i < 5; i ++){
    for(int j = 0; j < 5; j++){
      cin >> g[i][j];
    }
  }

  ull maxv = 0;
  do{
    maxv = max(maxv, eval());
  }while( next_permutation(perm, perm+5));
  cout << maxv << endl;
  
  return 0;
}
// AC
