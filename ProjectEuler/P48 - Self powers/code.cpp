#include <iostream>

using namespace std;

const long long M = (long long) 1e10;

long long power(int n){
  long long ans = 1;
  for(int i = 0; i < n; i++){
    ans = (ans * n) % M;
  }
  return ans;
}

int main(){
  int limit = 1000;

  long long ans = 0;
  for(int i = 1; i <= limit; i++){
    ans = (ans + power(i)) % M;
  }
  cout << ans << endl;
  return 0;
}

// AC ans=9110846700
