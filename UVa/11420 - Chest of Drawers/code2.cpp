#include <cstdio>
#include <vector>

#define NMAX 70

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vvll ma;
vvll mb;
vvll mc;
vvll md;

ll a(int, int);
ll b(int, int);
ll c(int, int);
ll d(int, int);
void print();

ll a(int n, int s){
  if( ma[n][s] == -1 ){
    ma[n][s] = a(n-1, s) + b(n-1, s);
  }
  //  printf("a(%d, %d) = %lld\n", n, s, ma[n][s]);
  return ma[n][s];
}

ll b(int n, int s){
  if( mb[n][s] == -1 ){
    mb[n][s] = a(n-2, s) + b(n-2, s) + c(n-2, s) + d(n-2, s);
  }
  //  printf("b(%d, %d) = %lld\n", n, s, mb[n][s]);
  return mb[n][s];
}

ll c(int n, int s){
  if( mc[n][s] == -1 ){
    mc[n][s] = a(n, s-1);
  }
  //  printf("c(%d, %d) = %lld\n", n, s, mc[n][s]);
  return mc[n][s];
}

ll d(int n, int s){
  if( md[n][s] == -1 ){
    md[n][s] = b(n, s-2);
  }
  //  printf("d(%d, %d) = %lld\n", n, s, md[n][s]);
  return md[n][s];
}

ll f(int n, int s){
  if( n < s ) return 0;
  ll s1, s2, s3, s4;
  s1 = a(n, s);
  s2 = b(n, s);
  s3 = c(n, s);
  s4 = d(n, s);
  return s1 + s2 + s3 + s4;
}

void init(){
  ma = vvll(NMAX, vll(NMAX, -1));
  mb = vvll(NMAX, vll(NMAX, -1));
  mc = vvll(NMAX, vll(NMAX, -1));
  md = vvll(NMAX, vll(NMAX, -1));

  ma[1][0] = 1;
  mb[1][0] = 0;
  mc[1][0] = md[1][0] = 0;

  ma[2][1] = mb[2][1] = md[2][1] = 0;
  mc[2][1] = 1;

  ma[3][1] = md[3][1] = 0;
  mb[3][1] = 1;
  mc[3][1] = 2;

  for( int i = 1; i < NMAX; i++ ){
    ma[i][i] = mb[i][i] = mc[i][i] = 0;
    md[i][i] = 1;
  }
  for( int i = 2; i < NMAX; i++ ){
    ma[i][0] = mb[i-1][0] + ma[i-1][0];
    mb[i][0] = ma[i-1][0];
    mc[i][0] = md[i][0] = 0;
  }
  for( int i = 3; i < NMAX; i++ ){
    md[i][1] = 0;

    ma[i][i-1] = mb[i][i-1] = mc[i][i-1] = 0;
    md[i][i-1] = 1;
  }
}

void print(){
  int upto = 10;
  for(int i = 0; i < upto; i++){
    for(int j = 0; j < upto; j++){
      printf("%5lld", ma[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int n, s;
 
  init();

  scanf("%d %d", &n, &s);
  while( 0 <= n && 0 <= s ){
    printf("%lld\n", f(n, s));    

    scanf("%d %d", &n, &s);
    //    if( 0 <= n && 0 <= s ) printf("\n");
  }
  /*
  for( int i = 1; i < NMAX; i++){
    for( int j = 0; j <= i; j++){
      f(i, j);
    }
  }
  */
  return 0;
}
