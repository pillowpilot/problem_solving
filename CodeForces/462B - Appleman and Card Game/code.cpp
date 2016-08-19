#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef map<char, int> mci;
typedef priority_queue<int> qi;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  mci mp;
  while( n-- > 0 ){
    char c;
    cin >> c;
    mp[c]++;
  }

  qi q;
  mci::const_iterator iter = mp.begin();
  while( iter != mp.end() ){
    q.push( iter->second );
    iter++;
  }

  unsigned long long ans = 0;
  while( k > 0 ){
    int trend = q.top();
    q.pop();

    unsigned long long choosed = min(trend, k);

    ans += choosed*choosed;

    k -= choosed;
  }

  cout << ans << endl;
  
  return 0;
}

// AC
