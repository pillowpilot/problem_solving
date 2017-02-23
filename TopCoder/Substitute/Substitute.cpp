#include <iostream>
#include <string>
#include <map>

using namespace std;

class Substitute
{
public:
  int getValue(string key, string code){
    map<char, int> f;
    for(int i = 0; i < key.size(); i++)
      {
	f[key[i]] = (i + 1) % key.size();
      }

    int ans = 0;
    for(char c: code)
      {
	map<char, int>::iterator iter = f.find(c);
	if( iter != end(f) ){
	  ans *= 10;
	  ans += iter->second;
	}
      }

    return ans;
  }

};

int main(){
  Substitute s;
  cout << s.getValue("TRADINGFEW", "LGXWEV") << endl;
  cout << s.getValue("ABCDEFGHIJ", "XJ") << endl;
  cout << s.getValue("CRYSTALBUM", "MMA") << endl;
  return 0;
}

// AC
