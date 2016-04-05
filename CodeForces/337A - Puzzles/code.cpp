#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
  int n, m, A;
  vector<int> f;

  scanf("%d %d ", &n, &m);

  f.resize(m);
  vector<int>::iterator iter = f.begin();
  while(iter!=f.end()){
    scanf("%d ", &*iter);
    iter++;
  }

  sort(f.begin(), f.end());
  
  A = f[n-1] - f[0];
  for(int i = 0; i < m - n + 1; i++){
    if( A > f[i+n-1] - f[i] ) A = f[i+n-1] - f[i];
  }

  printf("%d\n", A);
  return 0;
}
