#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

inline vector<string> readFile(const string& filename){
  ifstream file(filename);
  vector<string> strings;
  
  if( file.is_open() ){
    string data, name;
    file >> data;
    istringstream ss(data);
    while( getline(ss, name, ',') ){
      name = name.substr(1, name.size() - 2);
      strings.push_back( name );
    }
    sort(begin(strings), end(strings));
    
    file.close();
  }else{
    cout << "File not found!" << endl;
  }
  return strings;
}

int main(){
  const string filename = "p022_names.txt";
  vector<string> list = readFile(filename);

  unsigned long long ans = 0;
  for(int index = 0; index < list.size(); index++){
    int name_value = 0;
    for(char c: list[index]){
      int char_value = c - 'A' + 1 ;
      name_value += char_value;
    }
    
    if( list[index] == "COLIN" )
      cout << "COLIN :" << name_value << endl;
    
    name_value *= index+1;
    ans += name_value;
  }
  cout << ans << endl;
  return 0;
}

// AC ans = 871198282
