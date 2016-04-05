#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef unsigned long long ull;

vi apps;
vi loc;

int main(){
  int n, m, k;
  
  cin >> n >> m >> k;
  apps = vi(n+10, 0);
  loc  = vi(n+10, 0);

  for(int i = 0; i < n; i++){
    int a;
    
    cin >> a;
    apps[i] = a - 1;
    loc[a - 1]  = i;
  }
  
  ull sum = 0; // Necesario
  for(int i = 0; i < m; i++){
    int a;
    
    cin >> a;
    a--;
    sum += loc[a] / k;
    sum += 1;
    
    if( loc[a] != 0 ){
      int m = loc[a], n = loc[a] - 1, o = a, p = apps[n];
      
      swap( apps[m], apps[n]);
      swap( loc[o], loc[p] );
    }
    
  }
  
  cout << sum << endl;
  
  return 0;
}


// AC
