#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> msi;

int main(){
  bool flagTest = false;
  int cases;
  string str;

  cin >> cases;
  getline(cin, str);
  getline(cin, str);
  while( cases-- > 0 ){
    if(flagTest) cout << endl << endl;
    flagTest = true;
    
    msi data;
    int treesCount = 0;
    while( getline(cin, str) && str != "" ){
      treesCount++;
      if( data.find(str) == data.end() ) data[str] = 1;
      else data[str]++;
    }

    bool flag = false;
    auto iter = data.begin();
    while( iter != data.end() ){
      if( flag ) cout << endl;
      flag = true;
      cout << fixed << setprecision(4);
      cout << (iter->first).data() << " " << (double)(iter->second)*100 / treesCount;
      iter++;
    }

  }
  cout << endl;
  
  return 0;
}

// AC
