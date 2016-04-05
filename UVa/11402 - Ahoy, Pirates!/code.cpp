#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
  size_t left, right;
  int value;
  Node(){ left = right = value = 0}
  Node(size_t left, size_t right, int value): left(left), right(right), value(value){}
};

typedef vector<int> vi;
typedef vector<Node> vn;

vi pData;
vn st;

int generate(size_t leftI, size_t rightI, size_t baseAddr){
  if( leftI == rightI ){
    st[baseAddr] = Node(leftI, rightI, pData[leftI]);
    return pData[leftI];
  }else{
    size_t midPoint = leftI + (rightI - leftI) / 2;
    int valueL = generate(leftI, midPoint, 2 * baseAddr + 1);
    int valueR = generate(midPoint + 1, rightI, 2 * baseAddr + 2);
    st[baseAddr] = Node(leftI, rightI, valueL + valueR);
    return valueL + valueR;
  }
}



int readInt();
size_t readLine(char*);
void readPirateData();
char readQueryType();
template <typename T>
ostream& operator<<(ostream&, const vector<T>&);
int main(){
  int css;

  css = readInt();
  for(int caseId = 1; caseId <= css; caseId++){
    readPirateData();
    int queries = readInt();
    while( queries-- > 0 ){
      char qType = readQueryType();
      int a = readInt(), b = readInt();

      //cout << "Query " << qType << endl;
    }
  }


  return 0;
}


int readInt(){
  int c, value;

  c = getc_unlocked(stdin);
  while( c < '0' || '9' < c ) c = getc_unlocked(stdin);

  value = c - '0';
  c = getc_unlocked(stdin);
  while( '0' <= c && c <= '9' ){
    value *= 10;
    value += c - '0';
    c = getc_unlocked(stdin);
  }

  return value;
}

size_t readLine(char* l){
  size_t index = 0;
  int c;

  c = getc_unlocked(stdin);
  while( c != '\n'){
    l[index++] = (char) c;
    c = getc_unlocked(stdin);
  }
  l[index++] = '\0'; //Append null character
  //  c = getc_unlocked(stdin); //Consume EOL

  return index;
}

void readPirateData(){
  int m;

  pData = vi();
  pData.reserve(1024555);

  m = readInt(); //cout << "Se leyo m: " << m << endl;
  while( m-- > 0 ){
    int t;
    int data[55]; size_t dataSize = 0;
    char line[55]; size_t lineSize = 0;

    t = readInt(); //cout << "Se leyo t: " << t << endl;
    lineSize = readLine(line); //cout << "Se leyo la linea: " << line << endl;
    
    for(size_t index = 0; index < lineSize; index++){
      char c = line[index];
      switch(c){
      case '0':
	data[dataSize++] = 0;
	break;
      case '1':
	data[dataSize++] = 1;
	break;
      }
    }
    
    while( t-- > 0 ){
      for(size_t index = 0; index < dataSize; index++){
	pData.push_back(data[index]);
      }
    }
    
    //cout << pData << endl;
  }
}

char readQueryType(){
  int c;

  c = getc_unlocked(stdin);
  while( c != 'F' && c != 'E' && c != 'I' && c != 'S' ) c = getc_unlocked(stdin);

  return (char)c;
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
