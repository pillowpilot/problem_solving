#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(){
  int n, m;
  vi v;

  while( scanf("%d ", &n) == 1 && n != -1 ){
    v = vi();
    
    while( n-- > 0 ){
      int a;
      scanf("%d ", &a);
      v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    n = v.size();

    if( n % 2 == 0 ){
      m = v[n/2 - 1] + v[n/2];
      m /= 2;
    }else{
      m = v[n/2];
    }
    printf("%d\n", m);
  }
  return 0;
}
