#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef set<ll> sll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;

  sll s;
  while( n-- > 0 ){
    ll x;
    cin >> x;
    s.insert(x);
  }

  if( s.size() > 3 )
    cout << "NO";
  else if( s.size() == 1 || s.size() == 2 )
    cout << "YES";
  else{
    ll t[3];
    auto iter = s.begin();
    t[0] = *iter;
    iter++;
    t[1] = *iter;
    iter++;
    t[2] =  *iter;

    sort(t, t+3);

    if( t[1] - t[0] == t[2] - t[1] ){
      cout << "YES";
    }else{
      cout << "NO";
    }
  }
  

  cout << endl;
  return 0;
}
  
// AC
