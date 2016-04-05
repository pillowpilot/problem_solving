#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n, t, pos = 1;
  vector<int> a;
  vector<int>::iterator iter;

  scanf("%d %d", &n, &t);

  a.resize(n);
  iter = a.begin() + 1;
  while(iter != a.end()) scanf("%d", &(*iter++));

  while(pos < t){
    pos += a[pos];
  }

  if( pos == t ){
    printf("YES");
  }else{
    printf("NO");
  }
}
