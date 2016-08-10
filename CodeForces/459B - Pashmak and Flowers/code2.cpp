#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int f[n];
  for(int i = 0 ; i < n; i++){
    cin >> f[i];
  }
  sort(f, f+n);
  long long ways;
  int dif = f[n-1] - f[0];
  if( dif == 0 ){
    ways = (long long) n*(n-1)/2;
  }else{
    int a = 0, b = 0;
    int i = 0;
    while( f[i] == f[0] ){
      a++;
      i++;
    }
    i = n-1;
    while( f[n-1] == f[i] ){
      b++;
      i--;
    }

    ways = (long long)a*b;
  }

  cout << dif << ' ' << ways << endl;
    
  return 0;
}

// AC Beware the overflow!!! TT_TT
