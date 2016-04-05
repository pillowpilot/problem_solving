#include <cstdio>
#include <vector>

using namespace std;

int maximumSubarraySum(vector<int>& v){
  int maxSum = 0;
  for(unsigned int i = 1; i < v.size(); i++){
    v[i] = v[i-1] + v[i];
  }
  
  for(unsigned int i = 1; i < v.size(); i++){
    for(unsigned int j = i; j < v.size(); j++){
      maxSum = max(maxSum, v[j] - v[i - 1]);
    }
  }
  return maxSum;
}

void print(vector<int>& v){
  for(auto i = v.begin(); i != v.end(); i++){
    printf("%d ", *i);
  }
  printf("\n");
}

int main(){
  int len, d, ones = 0;
  vector<int> bits;

  scanf("%d ", &len);

  bits.resize(len);
  vector<int>::iterator iter = bits.begin();
  while(iter!=bits.end()){
    scanf("%d ", &d);
    if(d==0){
      *iter = 1;
    }else{
      *iter = -1;
      ones++;
    }
    iter++;
  }
  printf("%d", ones + maximumSubarraySum(bits) );

  return 0;
}
