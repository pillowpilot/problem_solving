#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
  size_t a, b;
  int x, y, z, lazy;
 
  Node(){a = b = x = y = z = lazy = 0;}
  Node(size_t a, size_t b): a(a), b(b) {x = y = z = lazy = 0;}
  void update(){
    while( lazy > 0 ){
      int t = z;
      z = y;
      y = x;
      x = t;
      lazy--;
    }
  }
};

typedef vector<Node> vn;

vn tree;

ostream& operator<<(ostream& os, const Node& n){
  os << "[" << n.a << ", " << n.b << "](" << n.x << ", " << n.y << ", " << n.z << ")[" << n.lazy << "]";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  int e = 0;
  typename vector<T>::const_iterator iter = v.begin();
  while( iter != v.end() ){
    for( int i = 0; i < pow(2, e) && iter != v.end(); i++ ){
      os << *iter << " ";
      iter++;
    }
    e++;
    os << endl;
  }
  return os;
}

void constructTreeAux(size_t a, size_t b, size_t baseAddr){
  if( a == b ){
    Node n = Node(a, b);
    n.x = 1;

    tree[baseAddr] = n;
  }else{
    Node n = Node(a, b);
    size_t midPoint = a + (b - a)/2;
    constructTreeAux( a, midPoint, 2 * baseAddr + 1 );
    constructTreeAux( midPoint + 1, b, 2 * baseAddr + 2);
    
    n.x = tree[2 * baseAddr + 1].x + tree[2 * baseAddr + 2].x;
    n.y = tree[2 * baseAddr + 1].y + tree[2 * baseAddr + 2].y;
    n.z = tree[2 * baseAddr + 1].z + tree[2 * baseAddr + 2].z;

    tree[baseAddr] = n;
  }
}

void constructTree(int n){
  tree = vn(n * log2(n));
  constructTreeAux(0, n-1, 0);
}

int query(size_t a, size_t b, size_t baseAddr){
  Node& n = tree[baseAddr];
  //printf("D [%lu, %lu] in [%lu, %lu]\n", a, b, n.a, n.b);
  if( n.lazy != 0 ){
    if( n.a != n.b ){ //If internal node
      tree[2 * baseAddr + 1].lazy += n.lazy;
      tree[2 * baseAddr + 2].lazy += n.lazy;
    }
    n.update();
  }
  if( n.a == a && n.b == b ){
    return n.x;
  }else{
    size_t midPoint = n.a + (n.b - n.a) / 2;
    if( b <= midPoint) return query(a, b, 2 * baseAddr + 1);
    else if( midPoint + 1 <= a ) return query(a, b, 2 * baseAddr + 2);
    else return query(a, midPoint, 2 * baseAddr + 1) + query(midPoint + 1, b, 2 * baseAddr + 2);
  }
}

void update(size_t a, size_t b, size_t baseAddr){
  Node& n = tree[baseAddr];
  printf("DU [%lu, %lu] in ", a, b);
  cout << n << endl;
  if( n.lazy != 0 ){
    if( n.a != n.b ){ //If internal node
      tree[2 * baseAddr + 1].lazy += n.lazy;
      tree[2 * baseAddr + 2].lazy += n.lazy;
    }
    n.update();
  }

  if( n.a == a && n.b == b ){
    if( n.a != n.b ){
      tree[2 * baseAddr + 1].lazy++;
      tree[2 * baseAddr + 2].lazy++;
    }
    n.lazy++;
    n.update();
  }else{
    size_t midPoint = n.a + (n.b - n.a) / 2;
    if( b <= midPoint ) update(a, b, 2 * baseAddr + 1);
    else if( midPoint + 1 <= a ) update(a, b, 2 * baseAddr + 2);
    else{
      update(a, midPoint, 2 * baseAddr + 1);
      update(midPoint + 1, b, 2 * baseAddr + 2);
    }
    
    n.x = tree[2 * baseAddr + 1].x + tree[2 * baseAddr + 2].x;
    n.y = tree[2 * baseAddr + 1].y + tree[2 * baseAddr + 2].y;
    n.z = tree[2 * baseAddr + 1].z + tree[2 * baseAddr + 2].z;

    //cout << ">>" << n << endl;
  }
}

void assert(int n){
  /*for( size_t i = 0; i < n; i++ ){
    for( size_t j = i; j < n; j++ ){
      printf("(%lu, %lu): %d\n", i, j, query(i, j, 0));
    }
  }*/

  cout << tree << endl;
}

int main(){
  int n, q;

  scanf("%d %d ", &n, &q);
  constructTree(n);
  assert(n);
  while( q-- > 0 ){
    int c, a, b, r;
    scanf("%d %d %d ", &c, &a, &b);
    switch(c){
    case 0: //Update
      printf("U %d %d\n", a, b);
      update(a, b, 0);
      //assert(n);
      //printf("\n");
      break;
    case 1: //Query
      r = query(a, b, 0);
      printf("Q %d %d > %d\n", a, b, r);
      break;
    }
  }
  return 0;
}
