#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi segmentTree;
vi data;
int n;

inline int getRightChild(int i){
  return i*2 + 1; // (i << 1) ^ 1;
}
inline int getLeftChild(int i){
  return i*2; // i << 1;
}
inline int getParent(int i){
  return i/2; // i >> 1;
}

void build(){
  bool exclusive = false;
  int lvl = n - 1;
  while( lvl > 0 ){
    for(int i = lvl; i > lvl/2; i--){
      int left = segmentTree[ getLeftChild(i) ];
      int right = segmentTree[ getRightChild(i) ];
      int ans;
      if( exclusive ) ans = left ^ right;
      else ans = left | right;
      segmentTree[i] = ans;
    }
    lvl = lvl/2;
    exclusive = !exclusive;
  }
}

void update(int p, int b){
  bool exclusive = false;
  int index = n - 1 + p;
  segmentTree[index] = b;

  index = getParent(index);
  while( index >= 1 ){
    int left = segmentTree[ getLeftChild( index ) ];
    int right = segmentTree[ getRightChild( index ) ];
    int ans = (exclusive)? left ^ right : left | right;
    exclusive = !exclusive;
    segmentTree[index] = ans;
    index = getParent(index);
  }
}

int main(){  
  int exp; //cin >> exp;
  int m; //cin >> m;
  scanf("%d %d", &exp, &m);
  n = 2 << exp-1;

  segmentTree.resize(2*n);
  for(int i = n; i < 2*n; i++){
    int x; //cin >> x;
    scanf("%d ", &x);
    segmentTree[i] = x;
  }
  build();
  
  while( m-- ){
    int p, b; //cin >> p >> b;
    scanf("%d %d ", &p, &b);
    update(p, b);
    int v = segmentTree[1];
    //cout << v << endl;
    printf("%d\n", v);
  }
  return 0;
}

// AC
