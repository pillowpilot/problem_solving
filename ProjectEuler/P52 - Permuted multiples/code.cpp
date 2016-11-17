#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sameDigits(int a, int b){
  int d[10] = {0};

  do{
    d[a%10]++;
    a/=10;
  }while(a!=0);

  do{
    d[b%10]--;
    b/=10;
  }while(b!=0);

  for(int i = 0; i < 10; i++){
    if( d[i] != 0 )
      return false;
  }
  return true;
}


int main(){
  int limit = (int) 1e6;
  for(int i = 1; i < limit; i++){
    int k = 2;
    while( k <= 6 && sameDigits(i, k*i) ){
      k++;
    }
    if( k == 7 ){
      cout << i << endl;
      break;
    }
  }

  return 0;
}

// AC
// ans = 142857


/*
  the decimal expantion of 1/7 has the desired property
 */
