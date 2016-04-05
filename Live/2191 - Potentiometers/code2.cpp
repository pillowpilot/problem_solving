#include <cstdio>
#include <vector>

using namespace std;

struct Node{
  size_t left, right;
  int value;
  Node(): left(0), right(0), value(0){}
  Node(size_t l, size_t r, int v): left(l), right(r), value(v){}
};

typedef vector<Node> vn;
typedef vector<int> vi;

vn st;
vi data;

int generateST(const vector<int>& v, size_t leftI, size_t rightI, size_t baseAddr){
  if( leftI == rightI ){
    st[baseAddr] = Node(leftI, rightI, v[leftI]);
  }else{
    size_t midPoint = leftI + (rightI - leftI) / 2;
    int valueL = generateST(v, leftI, midPoint, 2 * baseAddr + 1);
    int valueR = generateST(v, midPoint + 1, rightI, 2 * baseAddr + 2);
    st[baseAddr] = Node(leftI, rightI, valueL + valueR);
  }
  return st[baseAddr].value;
}

int updateST(size_t index, int newValue, size_t baseAddr){
  Node n = st[baseAddr];
  if( n.left == n.right ){
    st[baseAddr].value = newValue;
  }else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    int valueL, valueR;
    if( index <= midPoint ){
      valueL = updateST(index, newValue, 2 * baseAddr + 1);
      valueR = st[2 * baseAddr + 2].value;
    }else{
      valueL = st[2 * baseAddr + 1].value;
      valueR = updateST(index, newValue, 2 * baseAddr + 2);
    }
    st[baseAddr].value = valueL + valueR;
  }
  return st[baseAddr].value;
}

int queryST(size_t leftI, size_t rightI, size_t baseAddr){
  Node n = st[baseAddr];
  if( n.left == leftI && n.right == rightI ) return n.value;
  else{
    size_t midPoint = n.left + (n.right - n.left) / 2;
    if( rightI <= midPoint ) return queryST(leftI, rightI, 2 * baseAddr + 1);
    else if( midPoint + 1 <= leftI ) return queryST(leftI, rightI, 2 * baseAddr + 2);
    else return queryST(leftI, midPoint, 2 * baseAddr + 1) + queryST(midPoint + 1, rightI, 2 * baseAddr + 2);
  }
}

void init(){
  st = vector<Node>(200000 * 18); // (2*10**5)*(log_2(2*10*5))
  data = vector<int>();
  data.reserve(200050);
}

int main(){
  bool flag = false;
  int n, caseId = 1;
  char c;
  
  while( scanf("%d ", &n) == 1 && n != 0 ){
    //Presentation details
    if( flag == true ) printf("\n\n");
    flag = true;
    printf("Case %d:", caseId++);

    init();
    while( n-- > 0 ){
      int a;
      scanf("%d ", &a);
      data.push_back(a);
    }
    generateST(data, 0, data.size() - 1, 0);

    scanf(" ");
    while( scanf("%c", &c) == 1 && c != 'E' ){
      if( c == 'S' ){
	size_t x; int r;
	scanf("%lu %d ", &x, &r); //Consume until EOL
	x--; //Offset for 0-base array
	updateST(x, r, 0);
      }else if( c == 'M' ){
	size_t x, y; int v;
	scanf("%lu %lu ", &x, &y); //Consume until EOL
	x--; y--; //Offset for 0-based array
	v = queryST(x, y, 0);

	printf("\n%d", v);
      }
    }
    scanf("ND ");
  }
 
  return 0;
}
