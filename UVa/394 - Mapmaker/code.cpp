#include <vector>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

void readDefinition(map<string, vector<long> > &vectors){
  char nameTmp[128];
  long baseAddr, elementSize;
  int dimentions;
  string name;
  vector< pair<long, long> > bounds;
  vector<long> constants;
  
  scanf("%128s %ld %ld %d", nameTmp, &baseAddr, &elementSize, &dimentions);

  bounds.resize(dimentions);
  for(int i = 0; i < dimentions; i++){
    long lower, upper;
    scanf("%ld %ld", &lower, &upper);
    bounds[i] = make_pair(lower, upper);
  }
  scanf("%*c");

  constants.resize(dimentions+1);
  constants[dimentions] = elementSize;
  for(int i = dimentions - 1; i > 0; i--){
    constants[i] = constants[i+1]*( bounds[i].second - bounds[i].first + 1);
  }
  for(int i = 1; i <= dimentions; i++){
    constants[0] += constants[i]*bounds[i-1].first;
  }
  constants[0] = baseAddr - constants[0];

  name = nameTmp;
  vectors[name] = constants;

  /*
  printf("%s, %ld, %ld, %d : ", name.c_str(), baseAddr, elementSize, dimentions);
  for(int i = 0; i < dimentions; i++){
    printf("(%ld, %ld) ", bounds[i].first, bounds[i].second);
  }
  printf("\n");
  for(int i = 0; i < dimentions + 1; i++){
    printf("%ld ", constants[i]);
  }
  printf("\n");
  */
}

void processReference(map< string, vector<long> > &vectors){
  char nameTmp[128];
  long index, physicalAddr;
  string name;
  vector<long> indexes, constants;
  
  scanf("%128s[", nameTmp);
  name = nameTmp;
  map< string, vector<long> >::iterator iter = vectors.find(name);
  constants = iter->second;
  indexes.resize(constants.size() - 1);

  for(int i = 0; i < constants.size() - 1; i++){
    scanf("%ld, ", &index);
    indexes[i] = index;
  }

  physicalAddr = constants[0];
  for(int i = 1; i < constants.size(); i++){
    physicalAddr += indexes[i-1]*constants[i];
  }
  
  printf("%s[", nameTmp);
  for(int i = 0; i < indexes.size() - 1; i++){
    printf("%ld, ", indexes[i]);
  }
  printf("%ld] = %ld\n", indexes[indexes.size() - 1], physicalAddr);
}

int main(){
  int definitions, references;
  map<string, vector<long> > vectors;

  scanf("%d %d", &definitions, &references);
  while(definitions > 0){
    readDefinition(vectors);
    definitions--;
  }
  while(references > 0){
    processReference(vectors);
    references--;
  }
}
  
    
