#include <iostream>

using namespace std;

/*
  note that if there is a solution, then it's in [0, k-1]
  and it exists iff there is a subsequence of same integers from i to n-1
  where 0 <= i <= k-1.
  if such subsequence exists, then the answer is i, else -1.
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  int a[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];

  int l = 0;
  int i = n-1;
  while( i >= 0 && a[i] == a[n-1] ){
    i--; l++;
  }

  if( n - l <= k - 1)
    cout << n-l << endl;
  else
    cout << -1 << endl;
  
  return 0;
}

// AC
