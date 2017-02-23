#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef map<string, string> mss;

mss m;
int main(){
  int n;
  cin >> n;
  while( n-- ){
    string a, b;
    cin >> a >> b;
    auto iter = m.find(a);
    if( iter == m.end() ){
      m[b] = a;
    }else{
      string c = iter->second;
      m.erase(iter);
      m[b] = c;
    }
  }

  cout << m.size() << endl;
  for(auto iter: m){
    cout << iter.second << " " << iter.first << endl;
  }
  return 0;
}

// AC

/*
  Just map new to old, then print each mapping reversed.
 */
