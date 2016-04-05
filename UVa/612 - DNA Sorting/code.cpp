#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data{
  string s;
  int sortiness;
  Data(){s = ""; sortiness = 0;}
  Data(string s, int sortiness):s(s), sortiness(sortiness){}
  bool operator<(const Data& d) const{
    return sortiness < d.sortiness;
  }
};

typedef vector<Data> vd;

int calif(const string& s){
  int calif = 0;
  for( int i = 0; i < s.size(); i++ ){
    for( int j = i + 1; j < s.size(); j++ ){
      if( s[i] > s[j] ) calif++;
    }
  }
  return calif;
}

int main(){
  bool flag = false;
  int n;

  cin >> n;

  while( n-- > 0 ){
    vector<Data> dataset = vector<Data>();
    int a, b;
    cin >> a >> b;

    while( b-- > 0 ){
      string s;
      cin >> s;
      dataset.push_back( Data(s, calif(s)) );
    }

    stable_sort(dataset.begin(), dataset.end());

    if( flag ) cout << endl;
    flag = true;

    for( int i = 0; i < dataset.size(); i++ ){
      cout << dataset[i].s << endl;
    }
    
  }
  
  
  return 0;
}

// AC
