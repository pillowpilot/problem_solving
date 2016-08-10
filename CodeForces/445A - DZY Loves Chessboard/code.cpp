#include <iostream>
#include <string>

using namespace std;
int n, m;
string b[100];

bool isValid(int i, int j){
  return (0<=i && 0<=j && i < n && j < m);
}

void solve(int i, int j, char c){
  b[i][j] = c;
  int osi[] = {-1, +1, 0, 0};
  int osj[] = {0, 0, -1, +1};
  for(int k = 0;k<4; k++){
    int x = i+osi[k];
    int y = j+osj[k];
    if( isValid(x, y) && b[x][y] == '.' )
      solve(x, y, (c=='W')?'B':'W');
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  for(int i = 0 ; i< n; i++){
    for(int j = 0; j < m; j++){
      if( b[i][j] == '.' )
	solve(i, j, 'W');
    }
  }

  for(int i = 0 ; i< n; i++){
    cout << b[i] << '\n';
  }
  
  return 0;
}

// AC
