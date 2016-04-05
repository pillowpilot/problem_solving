#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int > vi;

int main(){
  int n;
  vi d;
  cin >> n;
  while( n-- > 0 ){
    int a;
    cin >> a;
    d.push_back(a);
  }
  sort( d.begin(), d.end(), [](int a, int b)->bool{return b < a;} );
  long long s = 0;
  int i = 1, j = 3;
  while( i < d.size() ){
    for(int l = 0; l < j; l++){
      s += (long long) d[i++];
    }
    j *= 4;
  }
  
  return 0;
}
