#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vi;

vi tree;
vi lazy;

inline void push(int node, ull a, ull b){
  int left = node*2;
  int right= node*2 + 1;
  if( lazy[node] != 0 ){
    tree[node] += lazy[node] * (b-a+1); // depends on the operation
    if( a != b ){
      lazy[ left ] += lazy[node];
      lazy[ right ] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_tree(int node, ull a, ull b, ull i, ull j, int value) {
  assert(0 <= node); assert(node < tree.size());
  assert(node < lazy.size());
  assert(a <= i && j <= b);
  
  int left = node*2;
  int right = node*2+1;
  push(node, a, b);

  if( a == i && j == b ){
    tree[node] += value * (j-i+1); // depends on the operation
    if( a != b ){
      lazy[ left ] += value;
      lazy[ right ] += value;
    }
  }else if( a != b ){
    int mid = (a+b)/2;
    if( j <= mid ){
      update_tree(left, a, mid, i, j, value);
    }else if( mid + 1 <= i ){
      update_tree(right, mid+1, b, i, j, value);
    }else{
      update_tree(left, a, mid, i, mid, value);
      update_tree(right, mid+1, b, mid+1, j, value);
    }
    tree[node] = tree[left] + tree[right];
  }
}

ull query_tree(int node, ull a, ull b, ull i, ull j) {
  assert(0 <= node); assert( node < tree.size() );
  assert(a <= i && j <= b);
  
  int left = node*2;
  int right = node*2+1;
  push(node, a, b);

  if( a != b ){
    ull mid = (a+b)/2;
    if( j <= mid ){
      return query_tree(left, a, mid, i, j);
    }else if( mid + 1 <= i ){
      return query_tree(right, mid+1, b, i, j);
    }else{
      ull ans = query_tree(left, a, mid, i, mid);
      ans += query_tree(right, mid+1, b, mid+1, j);
      return ans;
    }
  }else{
    return tree[node];
  }
}

int main(){  
  int tests; scanf("%d", &tests);
  while( tests-- ){
    int n; scanf("%d", &n);
    int q; scanf("%d", &q);


    n = pow(2, (int)(log(n)/log(2)) + 1 );
    tree.resize(2*n); fill( begin(tree), end(tree), 0 );
    lazy.resize(2*n); fill( begin(lazy), end(lazy), 0 );

    //cout << tree << endl;
    while( q-- ){
      int type; scanf("%d", &type);
      if( type == 0 ){ // range update
	int p, q, v; scanf("%d %d %d", &p, &q, &v);
	update_tree(1, 1, n, p, q, v);
	//cout << "update: " << tree << " " << lazy << endl;
      }else{ // range query
	int p, q; scanf("%d %d", &p, &q);
	ull ans = query_tree(1, 1, n, p, q);
	//cout << "query : " << tree << " " << lazy << endl;

	printf("%lld\n", ans);
      }	  
    }
  }
  return 0;
}
