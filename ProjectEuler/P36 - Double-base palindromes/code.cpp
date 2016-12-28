#include <iostream>
#include <string>

using namespace std;

bool isPalim(const string s){
  int i = 0;
  while( i < s.size() && s[i] == s[s.size() - i - 1] )
    i++;
  return i == s.size();
}

string toBinary(int n){
  if( n == 0 )
    return "0";

  string b;
  while( n > 0 ){
    if( n % 2 == 0 )
      b.push_back('0');
    else
      b.push_back('1');
    n /= 2;
  }
  return b; // actually we need to reverse it
  // but if it is palim it does not matter
}

int main(){
  int limit = (int) 1e6;

  long ans = 0;
  for(int i = 0; i < limit; i++){
    string dec = to_string(i);
    string bin = toBinary(i);
    if( isPalim(dec) && isPalim(bin) )
      ans += i;
  }

  cout << ans << endl;
  return 0;
}

// AC ans=872187
// Straghtfoward
