#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define GC getc_unlocked(stdin)

using namespace std;

struct Node{
  size_t left, right;
  int a, b, c; // (a, b, c) = #nmbrs with remainder (0, 1, 2)
  int lazy;
  Node(){ left = right = a = b = c = lazy = 0;}
  Node(size_t left, size_t right): left(left), right(right) {a = b = c = lazy = 0;}
  void setA(int amount){a = amount;}
  void setB(int amount){b = amount;}
  void setC(int amount){c = amount;}
  int  getA() const {return a;}
  int  getB() const {return b;}
  int  getC() const {return c;}
  void setLazy(int amount){lazy = amount;}
  int  getLazy() const {return lazy;}
  void removeLazyness(){
    lazy %= 3;
    while( lazy-- > 0 ){
      int t = a;
      a = c;
      c = b;
      b = t;
    }
  }
};

vector<Node> st;

const Node& generateST(size_t leftI, size_t rightI, size_t baseAddr){
  if( leftI == rightI ){
    st[baseAddr] = Node(leftI, rightI);
    switch(leftI % 3){
    case 0:
      st[baseAddr].setA(1);
      break;
    case 1:
      st[baseAddr].setB(1);
      break;
    case 2:
      st[baseAddr].setB(1);
      break;
    }
    return st[baseAddr];
  }else{
    size_t midPoint = leftI + (rightI - leftI) / 2;
    const Node& valueL = generateST(leftI, midPoint, 2 * baseAddr + 1);
    const Node& valueR = generateST(midPoint + 1, rightI, 2 * baseAddr + 2);
    st[baseAddr] = Node(leftI, rightI);
    st[baseAddr].setA( valueL.getA() + valueR.getA() );
    st[baseAddr].setB( valueL.getB() + valueR.getB() );
    st[baseAddr].setC( valueL.getC() + valueR.getC() );
    return st[baseAddr];
  }
}

int query(size_t leftI, size_t rightI, size_t baseAddr){
  Node& n = st[baseAddr];

  if( n.lazy != 0 ){
    if( n.left != n.right ){ //If not leaf
      st[2 * baseAddr + 1].lazy += n.lazy;
      st[2 * baseAddr + 2].lazy += n.lazy;
    }
    n.removeLazyness();
  }

  if( n.left == leftI && n.right == rightI ){
    return n.a;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    if( rightI <= midPoint ) return query(leftI, rightI, 2 * baseAddr + 1);
    else if( midPoint + 1 <= leftI ) return query(leftI, rightI, 2 * baseAddr + 2);
    else{
      int valueL = query(leftI, midPoint, 2 * baseAddr + 1);
      int valueR = query(midPoint + 1, rightI, 2 * baseAddr + 2);
      return valueL + valueR;
    }
  }
}

void update(size_t leftI, size_t rightI, size_t baseAddr){
  Node n = st[baseAddr];

  if( n.lazy != 0 ){
    if( n.left != n.right ){ //If not leaf
      st[2 * baseAddr + 1].lazy += n.lazy;
      st[2 * baseAddr + 2].lazy += n.lazy;
    }
    n.removeLazyness();
  }


  if( n.left == leftI && n.right == rightI ){
    n.lazy++;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    if( rightI <= midPoint ) update(leftI, rightI, 2 * baseAddr + 1);
    else if( midPoint + 1 <= leftI ) update(leftI, rightI, 2 * baseAddr + 2);
    else{
      update(leftI, midPoint, 2 * baseAddr + 1);
      update(midPoint + 1, rightI, 2 * baseAddr + 2);
    }
  }
}

void init(size_t n){
  st = vector<Node>(n * ( log2(n) + 1));
}

int readInt();
void printST();
int main(){
  int n, q;

  n = readInt();
  q = readInt();

  init(n);
  generateST(0, n-1, 0);

  while(q-- > 0){
    int a, b, c, r;
    a = readInt();
    b = readInt();
    c = readInt();
    switch(a){
    case 0:
      update(b, c, 0);
      break;
    case 1:
      r = query(b, c, 0);
      printf("%d\n", r);
      break;
    }
  }

  return 0;
};

int readInt(){
  int c = GC, r = 0;

  while( c < '0' && '9' < c ) c = GC;
  
  r = c - '0';
  c = GC;
  while( '0' <= c && c <= '9' ){
    r *= 10;
    r += c - '0';
    c = GC;
  }

  return r;
}
