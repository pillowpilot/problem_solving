#include <cstdio>
#include <vector>

using namespace std;

struct Node{
  size_t left, right;
  int value, freq;
  Node():left(0), right(0), value(0), freq(0){}
  Node(size_t l, size_t r, size_t v, size_t f): left(l), right(r), value(v), freq(f){}
};

typedef vector<Node> vn;

vn st;

size_t queryST(

void generateST(const vn& v, size_t l, size_t r, size_t baseAddr){
  if( l == r ){
    st[baseAddr] = Node(l, r, v[l], 1);
  }else{
    size_t midPoint = l + (r - l) / 2;
    generateST(v, l, midPoint, 2 * baseAddr + 1);
    generateST(v, midPoint + 1, r, 2 * baseAddr + 2);
    Node nl = st[2 * baseAddr + 1], nr = st[2 * baseAddr + 2];
    
  }
}

void init(){
  st = vector<Node>(1e5 * 17);
}

int main(){
  
  return 0;
}
