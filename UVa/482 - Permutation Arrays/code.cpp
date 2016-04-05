#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;

vi perm;
vd array;
vd permuted;

void print(){
  vd::const_iterator iter = permuted.begin();
  while( iter != permuted.end() ){
    printf("%lf\n", *iter);
    iter++;
  }
}

void process(){
  permuted.resize( array.size() );
  
  vi::const_iterator iter = perm.begin();
  while( iter != perm.end() ){
    permuted[ *iter ] = array[iter - perm.begin()];
    iter++;
  }
}

void init(){
  perm.clear();
  array.clear();
  permuted.clear();
}

void readNextLine(char** linePtr){
  string lineStr;

  scanf(" ");
  getline( cin, lineStr );
  strcpy(*linePtr, lineStr.data());
}

int main(){
  stringstream ss;
  
  
  cout << ss;
  
  return 0;
}
