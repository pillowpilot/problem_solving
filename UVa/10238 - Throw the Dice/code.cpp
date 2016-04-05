#include <cstdio>
#include <vector>

#define MAXSUM 4050
#define MAXFAC 55
#define MAXTHR 55

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> v3;

v3 memo;

ll dp(int s, int k, int n){
  if( s <= 0 || 0 == k ){
    //    printf("dp(%d, %d, %d) = 0\n", s, k, n);
    return 0;
  }else if(k == 1 && s <= n){
    //    printf("dp(%d, %d, %d) = 1\n", s, k, n);
    return 1;
  }else{
    if( memo[s][k][n] == -1 ){
      ll sum = 0, lim = n;
      for( int i = 1; i <= lim; i++ ){
	// Check for overflow
	sum += dp(s - i, k - 1, n);
      }
      memo[s][k][n] = sum;
    }
    //    printf("dp(%d, %d, %d) = %lld\n", s, k, n, memo[s][k][n]);
    return memo[s][k][n];
  }
}

ll pow(int b, int e){
  if( e == 0 ) return 1;
  else{
    ll a = pow(b, e / 2);
    if( e % 2 == 0 ){
      return a*a;
    }else{
      return a*a*b;
    }
  }
}

void init(){
  memo = v3(MAXSUM, vvll(MAXTHR, vll(MAXFAC, -1)));
}

int main(){
  bool flag = false;
  int faces, n, sum;

  init();
  while( scanf("%d %d %d", &faces, &n, &sum) == 3 ){
    ll posibles = dp(sum, n, faces);
    ll power = pow(faces, n);
    if( flag == true ) printf("\n");
    printf("%lld/%lld", posibles, power);
    flag = true;
  }
    
  return 0;
}
