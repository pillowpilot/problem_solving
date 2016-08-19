#include <iostream>
#include <algorithm>

using namespace std;

/*
  min ((1/d)sum abs(a_i - e)) where e is the 'target value'.
  e is optimal when is the median of {a_i}.
  if |{a_i}| is even, e = a_{n/2} after {a_i} is sorted.
  else e = a_{(n-1)/2} = a_{(n+1)/2} after {a_i} is sorted.
 */

int cost(int a[], int n, int e, int d){
  int m = 0;
  for(int i = 0; i < n; i++){
    m += abs(e - a[i]);
  }
  m /= d;
  return m;
}

int main(){
  int n, m, d;
  cin >> n >> m >> d;
  n *= m;

  int a[n];
  int minV, maxV;
  cin >> a[0];
  minV = maxV = a[0];
  for(int i = 1; i < n; i++){
    cin >> a[i];
    minV = min(minV, a[i]);
    maxV = max(maxV, a[i]);
  }
  sort(a, a+n);

  bool ans = true;
  for(int i = 1; i < n; i++){
    if( a[i] % d != a[0] % d )
      ans = false;
  }

  if( ans ){/*
    int low = minV, high = maxV, e;
    while( 1 < high - low ){
      e = low + (high-low)/2;
      int derivative = cost(a, n, e+1, d) - cost(a, n, e, d);
      if( derivative < 0 ){
	low = e;
      }else{
	high = e;
      }
    }
    if( high - low == 0 ){
      cout << cost(a, n, high, d) << endl;
    }else if( high - low == 1 ){
      cout << min( cost(a, n, high, d), cost(a, n, low, d)) << endl;
    }else{
      cout << cost(a, n, e, d) << endl;
      }*/

    int e = a[n/2];
    cout << cost(a, n, e, d) << endl;
    
  }else{
    cout << -1 << endl;
  }

  
}

// AC
