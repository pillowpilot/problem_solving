#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vi;

vi d;

double log4(double x){
  return log(x) / log(4);
}

int main(){
  ull n;
  
  cin >> n;
  d = vi();
  while( n-- > 0 ){
    ull a;
    cin >> a;
    d.push_back(a);
  }
  sort(d.begin(), d.end(), [](ull a, ull b)->bool{return b < a;});

  int k = (int) log4( d.size() ) + 1;
  ull s = d[0] * k;
  cout << "k: " << k << endl;
  cout << 0 << endl;
  k--;
  int i = 1, j = 4;
  while( k > 0 ){
    cout << "k: "<< k << endl;
    ull p = 0;
    while( i < j ){
      p += (ull) d[i];
      cout << i << ' ';
      i++;
    }
    cout << endl;
    s += p * (ull)k;
    k--;
    j *= 4;
  }

  cout << s << endl;
  
  return 0;
}
