#include <cstdio>
#include <string>

using namespace std;

typedef unsigned long long ull;

void solve(ull a, ull b, string& s){
  ull x = 0, y = 1, m = 1, n = 0, o = 1, p = 1;
  while( o != a || p != b ){
    //    printf("(%llu, %llu)\n", o, p);
    if( p*a < o*b ){ // Posible overflow
      m = o;
      n = p;
      s.push_back('L');
    }else{
      x = o;
      y = p;
      s.push_back('R');
    }
    // Posibles overflows
    o = x + m;
    p = y + n;
  }
}

int main(){
  ull a, b;
  string s;

  while( scanf("%llu %llu", &a, &b) == 2 && !( 1 == a && 1 == b ) ){
    s = "";
    solve( a, b, s );
    printf("%s\n", s.data());
  }
  return 0;
}
