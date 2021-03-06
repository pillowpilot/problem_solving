#include <cstdio>
#include <vector>

#define NMAX 70
#define SMAX 70

using namespace std;

typedef long long ll;
typedef struct{
  ll a, b, c, d;
} container;
typedef vector<container> vc;
typedef vector<vc> vvc;

vvc memo;

ll a(int, int);
ll b(int, int);
ll c(int, int);
ll d(int, int);

ll a(int n, int s){
  if( memo[n][s].a == -1 ){
    memo[n][s].a = a(n-1, s) + b(n-1, s);
  }
  printf("a(%d, %d) = %lld\n", n, s, memo[n][s].a);
  return memo[n][s].a;
}

ll b(int n, int s){
  if( memo[n][s].b == -1 ){
    memo[n][s].b = a(n-2, s) + b(n-2, s) + c(n-2, s) + d(n-2, s);
  }
  printf("b(%d, %d) = %lld\n", n, s, memo[n][s].b);  
  return memo[n][s].b;
}

ll c(int n, int s){
  if( memo[n][s].c == -1 ){
    memo[n][s].c = a(n, s-1);
  }
  printf("c(%d, %d) = %lld\n", n, s, memo[n][s].c); 
  return memo[n][s].c;
}

ll d(int n, int s){
  if( memo[n][s].d == -1 ){
    memo[n][s].d = b(n, s-2);
  }
  printf("d(%d, %d) = %lld\n", n, s, memo[n][s].d);
  return memo[n][s].d;
}

ll f(int n, int s){
  ll s1 = a(n, s);
  ll s2 = b(n, s);
  ll s3 = c(n, s);
  ll s4 = d(n, s);
  
  return s1 + s2 + s3 + s4;
}

void constCon(container& cont, int a, int b, int c, int d){
  cont.a = a;
  cont.b = b;
  cont.c = c;
  cont.d = d;
}

void print(){
  int upTo = 10;
  for( int i = 0; i < upTo; i++ ){
    for( int j = 0; j < upTo; j++ ){
      printf("%4lld", memo[i][j].d);
    }
    printf("\n");
  }
}

void init(){
  container c0, c1, c2;
  constCon(c0, -1, -1, -1, -1);
  constCon(c1, 1, 0, 0, 0);
  constCon(c2, 0, 0, 0, 1);
  
  memo = vvc(NMAX, vc(SMAX, c0));
  
  for( int i = 1; i < NMAX; i++ ){
    if( i > 2 ) memo[i][1].d = 0;
    memo[i][i-1] = c2;
    memo[i][i] = c2;
    memo[i][0] = c1;
    c1.a += c1.b;
    c1.b = c1.a - c1.b;
  }

  constCon(c1, 0, 0, 1, 0);
  constCon(c2, 0, 1, 2, 0);
  memo[2][1] = c1;
  memo[3][1] = c2;

  //print();
}

int main(){
  int n, s;
  
  init();
  scanf("%d %d", &n, &s);
  while( 0 <= n && 0 <= s ){
    printf("%lld", f(n, s));
    scanf("%d %d", &n, &s);
    if( 0 <= n && 0 <= s ) printf("\n");
  }
  return 0;
}
