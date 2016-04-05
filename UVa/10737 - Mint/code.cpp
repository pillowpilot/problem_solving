#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> vi;

vi coin;
vi table;
vi lower;
vi upper;

int floor(int a, int b){
  return a / b;
}

int ceil(int a, int b){
  if( a % b == 0 ) return a / b;
  else return a / b + 1;
}

int gcd(int a, int b){
  if( a < b ){
    int t = a;
    a = b;
    b = t;
  }
  if( b == 0 ) return a;
  else return gcd(b, a % b);
}

int lcm(int a, int b){
  return a*b/gcd(a, b);
}

int lcm(int a, int b, int c, int d){
  return lcm(a, lcm(b, lcm(c, d)));
}

void calculate(){
  size_t s = coin.size();
  for(int a = 0; a < s - 3; a++){
    for(int b = a + 1; b < s - 2; b++){
      for(int c = b + 1; c < s - 1; c++){
	for(int d = c + 1; d < s - 0; d++){
	  int f = lcm(coin[a], coin[b], coin[c], coin[d]);
	  //printf("lcm(%d, %d, %d, %d)=%d\n", coin[a], coin[b], coin[c], coin[d], f);
	  for(int t = 0; t < table.size(); t++){
	    int loLen, hiLen;
	    loLen = f * floor(table[t], f);
	    hiLen = f * ceil(table[t], f);
	    if( table[t] - loLen < lower[t] ) lower[t] = table[t] - loLen;
	    if( hiLen - table[t] < upper[t] ) upper[t] = hiLen - table[t];
	  }
	}
      }
    }
  }
}

void print(){
  for(int i = 0; i < lower.size(); i++){
    printf("%d %d\n", table[i] - lower[i], table[i] + upper[i]);
  }
}

void init(int n, int t){
  coin.clear();
  table.clear();
  lower.clear();
  upper.clear();
  //coin = vi(n);
  //table = vi(t);
  lower = vi(t, numeric_limits<int>::max());
  upper = vi(t, numeric_limits<int>::max());
}

int main(){
  int n, t;

  coin.reserve(55);
  table.reserve(15);
  lower.reserve(15);
  upper.reserve(15);

  scanf("%d %d", &n, &t);
  while( !(n == 0 && t == 0) ){
    init(n, t);
    while( n-- > 0 ){
      int a;
      scanf("%d", &a);
      coin.push_back(a);
    }
    while( t-- > 0 ){
      int a;
      scanf("%d", &a);
      table.push_back(a);
    }
    calculate();
    print();
    scanf("%d %d", &n, &t);
  }
  return 0;
}
