#include <iostream>

using namespace std;

bool f(int a, int b, int maxS){
  int c = maxS - a - b;
  return a*a + b*b == c*c;
}

int main(){
  // Easiest solution
  for(int a = 1; a < 1000; a++){
    for(int b = a + 1 ; b < 1000; b++){
      int c = 1000 - a - b;
      if( a*a + b*b == c*c )
	cout << a*b*c << endl;
    }
  }

  // Optimal? solution
  const int maxS = 1000;
  
  int a = 1, b = 2;
  while( !f(a, b, maxS) && a <= maxS - 2 ){
    b = a + 1;
    while( !f(a, b, maxS) && b <= maxS - a - 1 ){      
      b++;
    }
    if( !f(a, b, maxS) )
      a++;
  }

  cout << a*b*(maxS - a - b) << endl;
  
  return 0;
}

// AC
