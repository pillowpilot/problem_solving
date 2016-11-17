#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;

vi toVector(int n){
  vi ans;
  do{
    ans.push_back(n%10);
    n/=10;
  }while(n!=0);
  reverse(begin(ans), end(ans));
  return ans;
}

vi power(const vi& v, int e){
  vi ans;
  for(int a: v){
    ans.push_back( (int) pow(a, e) );
  }
  return ans;
}

int reduce(const vi& v){
  int ans = 0;
  for(int a: v){
    ans += a;
  }
  return ans;
}

int main(){
  int limit = (int) 1e6;
  int exponent = 5;
  
  int ans = 0;
  for(int i = 2; i <= limit; i++){
    int j = reduce( power( toVector(i), exponent ) );
    if( i == j ){
      cout << "DEBUG: " << i << endl;
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}

// AC ans = 443839

/*
  if we try to build a number n with such property from a sum of fifth power and n has 7 digits
  then at most n could be 7 * 9**5 = 413343 and the smallest 7 digits number is 10**6 = 1000000.
  therefore there is no number with 7 digits and such property

  as x * 9**5 << 10**(x-1) for x >= 7 there is no need to check then.
 */
