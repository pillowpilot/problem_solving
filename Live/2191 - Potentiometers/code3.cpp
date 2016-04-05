#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
  size_t left, right;
  int value;
  Node(){ left = right = value = 0;}
  Node(size_t left, size_t right, int value): left(left), right(right), value(value) {}
};

vector<Node> st;
vector<int> data;

int generate(size_t leftI, size_t rightI, size_t baseAddr, const vector<int>& data){
  if( leftI == rightI ){
    st[baseAddr] = Node(leftI, rightI, data[leftI]);
    return data[leftI];
  }else{
    size_t midPoint = leftI + (rightI - leftI) / 2;
    int valueL = generate(leftI, midPoint, 2 * baseAddr + 1, data);
    int valueR = generate(midPoint + 1, rightI, 2 * baseAddr + 2, data);
    
    st[baseAddr] = Node(leftI, rightI, valueL + valueR);
    return valueL + valueR;
  }
}

void update(size_t index, int newValue, size_t baseAddr){
  Node& n = st[baseAddr];
  if( n.left == n.right ){
    n.value = newValue;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;

    if( index <= midPoint ) update(index, newValue, 2 * baseAddr + 1);
    else                    update(index, newValue, 2 * baseAddr + 2);
    int valueL = st[2 * baseAddr + 1].value;
    int valueR = st[2 * baseAddr + 2].value;

    n.value = valueL + valueR;
  }
}

int query(size_t leftI, size_t rightI, size_t baseAddr){
  Node& n = st[baseAddr];
  if( n.left == leftI && n.right == rightI ){
    return n.value;
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

void init(size_t n){
  st = vector<Node>(n * (log2(n) + 1));
  data = vector<int>();
  data.reserve(n);
}

void printST(){
  int e = 0;
  size_t index = 0;

  while( index != st.size() ){
    for( int i = 0; i < pow(2, e); i++){
      Node& n = st[index++];
      printf("[%lu, %lu] (%d) ", n.left, n.right, n.value);
    }
    e++;
    printf("\n");
  }
}

int main(){
  bool flagC = false;
  char str[50];
  int n, caseID = 1;

  while( scanf("%d ", &n) == 1 && n != 0){
    bool flag = false;
    if( flagC == true ){
      printf("\n");
    }
    flagC = true;
    printf("Case %d:\n", caseID++);
    init(n);
    while(n-- > 0){
      int a;
      scanf("%d ", &a);
      data.push_back(a);
    }
    generate(0, data.size() - 1, 0, data);
    //printST();
    
    scanf("%s", str);
    while( str[0] != 'E' ){
      int a, b, r;
      scanf("%d %d ", &a, &b);
      switch(str[0]){
      case 'S':
	a--;
	update(a, b, 0);
	break;
      case 'M':
	a--; b--;
	r = query(a, b, 0);
	printf("%d\n", r);
	break;
      }
      scanf("%s", str);
    }
  }
  
  return 0;
}
