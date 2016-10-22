#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi prices;

int main(){
  int n;
  while( cin >> n ){
    prices.clear();
    while( n-- ){
      int p; cin >> p;
      prices.push_back(p);
    }
    sort(begin(prices), end(prices));
    int money; cin >> money;

    int ans = 0; // worst possible solution and 2 <= n
    for(int i = 0; i < prices.size(); i++){
      int p = prices[i];
      int x = money - p;

      if( binary_search(begin(prices), end(prices), x) ){
	auto lb = lower_bound(begin(prices), end(prices), x);
	auto ub = upper_bound(begin(prices), end(prices), x);
	int count = ub - lb;

	if( count > 1 || ( count == 1 && p != x ) ){
	  if( abs(ans-(money-ans)) > abs(p-x) )
	    ans = p;
	}
      }
    }

    int a = ans;
    int b = money - ans;
    if( a > b ) swap(a, b);

    cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";
  }

  flush(cout);
  return 0;
}

// AC
