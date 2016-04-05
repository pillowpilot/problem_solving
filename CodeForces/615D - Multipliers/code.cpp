#include <iostream>
#include <map>
#include <cmath>

#define PRIME (ull)(1e9+7)

using namespace std;

typedef unsigned long long ull;
typedef map<ull, int> mui;

mui m;

int main(){
  ios_base::sync_with_stdio(false);
  ull n, p, pp = 1, c = 1, power = 1;
  cin >> n;
  while( n-- > 0 ){
    cin >> p;
    
    auto iter = m.find(p);
    if( iter == m.end() ) m[p] = 1;
    else m[p]++;
    
    p = p % PRIME;
    pp = pp * p;
    pp = pp % PRIME;
  }

  //cout << pp << endl;

  auto iter = m.begin();
  while( iter != m.end() ){
    //    cout << iter->first << ", " <<iter->second << endl;
    c *= (iter->second + 1);
    iter++;
  }
  cout << c << endl;
  if( c % 2 == 0 ){
    c /= 2;
  }else{
    c /= 2;
    c--;
    power = power * sqrt(pp);
    power = power % PRIME;
  }

  //cout << c << endl;

  while( c-- > 0 ){
    power = power * pp;
    power = power % PRIME;
  }

  cout << power << endl;
  
  return 0;
}
