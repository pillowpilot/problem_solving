//#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
  size_t left, right;
  int value;
  Node(): left(0), right(0), value(0) {}
  Node(size_t left, size_t right, int value): left(left), right(right), value(value) {}
};

vector<Node> st;

/*ostream& operator<<(ostream& os, const Node& n){
  os << n.value << '(' << n.left << ", " << n.right << ')';
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << '[';
  if( v.size() > 0 ){
    os << v[0];
    auto iter = v.begin();
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  os << ']';
}
*/

int generateST(size_t leftI, size_t rightI, size_t baseAddr){
  if( leftI == rightI ){
    st[baseAddr] = Node(leftI, rightI, 0);
    return 1; // 0%3=0
  }else{
    size_t midPoint = leftI + (rightI - leftI) / 2;
    int valueL = generateST(leftI, midPoint, 2 * baseAddr + 1);
    int valueR = generateST(midPoint + 1, rightI, 2 * baseAddr + 2);
    st[baseAddr] = Node(leftI, rightI, valueL + valueR);
    return valueL + valueR;
  }
}

int update(size_t index, size_t baseAddr){
  Node& n = st[baseAddr];
  if( n.left == n.right ){
    n.value++;
    return ( n.value % 3 == 0 )?1:0;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    int valueL, valueR;
    Node child;
    if( index <= midPoint ){
      child = st[2 * baseAddr + 2];
      valueL = update(index, 2 * baseAddr + 1);
      valueR = (child.left == child.right)?(child.value % 3 == 0)?1:0:child.value;
    }else if( midPoint + 1 <= index ){
      child = st[2 * baseAddr + 1];
      valueL = (child.left == child.right)?(child.value % 3 == 0)?1:0:child.value;
      valueR = update(index, 2 * baseAddr + 2);
    }
    n.value = valueL + valueR;
    return n.value;
  }
}

int query(size_t leftI, size_t rightI, size_t baseAddr){
  Node n = st[baseAddr];
  if( n.left == leftI && n.right == rightI ){
    return (leftI == rightI)?(n.value % 3 == 0)?1:0:n.value;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    if( rightI <= midPoint ){
      return query(leftI, rightI, 2 * baseAddr + 1);
    }else if( midPoint + 1 <= leftI ){
      return query(leftI, rightI, 2 * baseAddr + 2);
    }else{
      return query(leftI, midPoint, 2 * baseAddr + 1) + query(midPoint + 1, rightI, 2 * baseAddr + 2);
    }
  }
}

void init(size_t n){
  st = vector<Node>(n * (log2(n) + 1));
}

int readInt(){
  register int cc = getc_unlocked(stdin);
  for (;cc < '0' || cc > '9';)  cc = getc_unlocked(stdin);
  register int ret = 0;
  for (;cc >= '0' && cc <= '9';)
    {
      ret = ret * 10 + cc - '0';
      cc = getc_unlocked(stdin);
    }
  return ret;
}

int main(){
  int n, q;

  //  scanf("%d %d ", &n, &q);
  n = readInt();
  q = readInt();

  init(n);
  generateST(0, n - 1, 0);
  // cout << st << endl;
  
  while( q-- > 0 ){
    int type, a, b;
    //    scanf("%d %d %d ", &type, &a, &b);
    type = readInt();
    a = readInt();
    b = readInt();

    if( type == 0 ){ // 0-type query increases values
      while( a <= b ){
	update(a, 0);
	a++;
      }
      //      cout << st << endl;
    }else{
      int r = query(a, b, 0);
      printf("%d\n", r);
    }
  }
  
  return 0;
}
