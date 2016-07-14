#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
int max_v;
int max_i;

bool marks[1000100];
int p[1000100];
vi g[1000100];

void findMax(int i){
  marks[i] = true;
  if( max_v < p[i] ){
    max_v = p[i];
    max_i = i;
  }
  for(int j = 0; j < g[i].size(); j++){
    if( marks[ g[i][j] ] == false )
      findMax( g[i][j] );
  }
}

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    cin >> p[i];
  }

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) marks[j]=false;
    max_v = p[i];
    max_i = i;
    findMax(i);
    if( max_v != 0 ){
      swap(p[i], p[max_i]);
    }
  }

  for(int i = 0; i < n; i++){
    cout << p[i] << ' ';
  }
  cout << endl;
  
  return 0;
}
