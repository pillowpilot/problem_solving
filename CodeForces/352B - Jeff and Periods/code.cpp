#include <iostream>

using namespace std;
int const MAX = (int)1e5+1;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  int p[MAX];
  int last[MAX];

  for(int i = 0; i < MAX+1; i++){
    last[i] = -1;
  }

  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if( last[x] == - 1) { // First time
      last[x] = i;
      p[x] = 0;
    }else{
      if( p[x] == 0 ){ // second time
	p[x] = i - last[x];
	last[x] = i;
      }else{
	if( p[x] == i - last[x] ){ // keep a arithmetic progression so far
	  last[x] = i;
	}else{
	  p[x] = -1; // not a solution as last[x] <= i
	}
      }
    }
  }

  int cnt = 0;
  for(int i = 0; i < MAX+1; i++){
    if( last[i] != -1 && p[i] >= 0 )
      cnt++;
  }

  cout << cnt << '\n';
  for(int i = 0; i < MAX +1; i++){
    if( last[i] != -1 && p[i] >= 0 ){
      cout << i << ' ' << p[i] << '\n';
    }
  }
  
  return 0;
}

// AC
