#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;

vi pp;

bool validInteger(int a){
  bitset<10> bs;

  bs.reset();
  //  cout << bs <<endl;

  while( a > 0 ){
    if( bs[ a%10 ] == true ) break;
    else bs.set( a %10 );
    a /= 10;
  }

  return a == 0;
}

void preprocess(){
  pp = vi(5050);

  for( int i = 0; i < pp.size(); i++ ){
    pp[i] = pp[i-1];
    if( validInteger(i) ){
      pp[i]++;
    }
  }
}

int main(){
  int n, m;

  preprocess();
  while( scanf("%d %d", &n, &m) == 2 ){
    n--;
    printf("%d\n", pp[m] - pp[n]);
  }
  
  return 0;
}

// AC
