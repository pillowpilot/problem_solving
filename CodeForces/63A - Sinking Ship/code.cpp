#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct package {
  int p;
  string name;
};

bool comparator(const package& a, const package& b){
  return a.p < b.p;
}

int main(){
  int n;
  vector<package> v;
  cin >> n;
  while( n-- ){
    string name, type;
    cin >> name >> type;
    int c;
    if( type == "rat" ) c = 0;
    if( type == "woman" ) c = 1;
    if( type == "child" ) c = 1;
    if( type == "man" ) c = 2;
    if( type == "captain" ) c = 3;

    v.push_back({c, name});
  }
  stable_sort(v.begin(), v.end(), comparator);
  for(package s: v){
    cout << s.name << endl;
  }
  return 0;
}

// AC
