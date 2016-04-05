#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi memo;

int f(int n){
  if( memo[n] != -1 ) return memo[n];
  else if( n == 0 || n == 2 ) return 1;
  else{
    int k = 0;
    for( int i = 0; i < n; i += 2 ){
      k += f( n - (i+2) )*f(i);
    }
    memo[n] = k;
    return k;
  }
}

int main(){
  bool flag = false;
  int ps;
  memo = vi(30, -1);

  while( scanf("%d", &ps) == 1 ){
    if( flag == true ) printf("\n");
    flag = true;
    printf("%d\n", f(ps*2));
  }
  
  return 0;
}

// AC
