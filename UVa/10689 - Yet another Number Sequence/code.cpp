#include <cstdio>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef map<int, ull> miu;

miu memo;
const int M = (int) 1e5;

ull fibo(int n){
  ull ans;
  if( n == 0 || n == 1)
    return n;
  else if( n == 2 )
    return 1;
  
  auto iter = memo.find(n);
  if( iter != memo.end() )
    return iter->second;
  
  ull a = fibo(n/2);
  ull b = fibo(n/2 + 1);
  if( n % 2 == 0 ){
    ans = fibo(n/2 - 1);
    ans = (ans*a) % M + (a*b) % M;
  }else{
    ans = (a*a) % M + (b*b) % M;
  }
  ans = ans % M;
  memo[n] = ans;
  return ans;
}

int main(){
  int t, a, b, n, m;
  scanf("%d", &t);
  while( t-- ){
    scanf("%d %d %d %d", &a, &b, &n, &m);

    int power = 1;
    while( m-- )
      power *= 10;
    
    int f = a*fibo(n-1) % power + b*fibo(n) % power;
    f = f % power;
    printf("%d\n", f);
  }

  return 0;
}

// AC
