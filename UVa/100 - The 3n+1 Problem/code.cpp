#include <stdio.h>
#include <map>
#include <stack>

using namespace std;

long lookForLengthIterative(long n, map<long, long> &lengths){
  long length;
  stack<long> pendings;
  map<long, long>::iterator iter = lengths.find(n);

  if(iter == lengths.end()){
    while(iter == lengths.end()){
      pendings.push(n);
      n = (n % 2 == 0)?n>>1:3*n+1;
      iter = lengths.find(n);
    }
    length = iter->second;
    while(!pendings.empty()){
      n = pendings.top();
      length++;
      lengths[n] = length;
      pendings.pop();
    }
    return length;
  }else{
    return iter->second;
  }
}

long lookForLength(long n, map<long, long> &lengths){
  map<long, long>::iterator iter = lengths.find(n);
  if(iter == lengths.end()){
    long lengthSoFar;
    if(n % 2 == 0){
      lengthSoFar = lookForLength(n / 2, lengths);
    }else{
      lengthSoFar = lookForLength(3 * n + 1, lengths);
    }
    lengths[n] = lengthSoFar + 1;
    return lengthSoFar + 1;
  }else{
    return iter->second;
  }      
}

int main(){
  long i1, j1, i, j, maxN, maxLength, currentLength;
  map<long, long> lengths;
  lengths[1] = 1;

  while(scanf("%ld %ld\n", &i1, &j1) == 2){

    if(i1 < j1){
      i = i1;
      j = j1;
    }else{
      i = j1;
      j = i1;
    }

    maxLength = 0;
    for(long n = i; n <= j; n++){
      currentLength = lookForLengthIterative(n, lengths);
      if(maxLength < currentLength){
	maxN = n;
	maxLength = currentLength;
      }
    }
    printf("%ld %ld %ld\n", i1, j1, maxLength);
  }

  return 0;
}
