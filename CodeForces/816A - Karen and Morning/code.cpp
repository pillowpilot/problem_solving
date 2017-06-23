#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef pair<int, int> pii;

pii next(pii c){
  pii n = c;
  if( n.second == 59 ){
    n.second = 0;
    if( n.first == 23 )
      n.first = 0;
    else
      n.first += 1;
  }else
    n.second += 1;
  return n;
}

string print(pii c){
  stringstream oss;
  oss << setfill('0') << setw(2) << c.first;
  oss << ":";
  oss << setfill('0') << setw(2) << c.second;
  return oss.str();
}

bool isPalim(string s){
  string rs(s);
  reverse(all(s));
  return rs == s;
}

int main(){
  string line;
  cin >> line;
  string h = line.substr(0, 2);
  string m = line.substr(3, 2);

  pii c;
  c.first = stoi(h);
  c.second = stoi(m);

  int ans = 0;
  while( !isPalim(print(c)) ){
    ans++;
    c = next(c);
  }
  cout << ans << endl;
  return 0;
}

// AC
