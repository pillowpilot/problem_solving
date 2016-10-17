#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";
  if( v.size() != 0 ){
    typename vector<T>::const_iterator iter = begin(v);
    os << *iter;
    iter++;
    while( iter != end(v) ){
      os << ", " << *iter;
      iter++;
    } 
  }
  return os << "]";
}

vector<int> solution;
string s;
vector<int> counters(10);
bool found(false), startFrom9(false);

bool isValid(int n){
  return counters[n] < 2;
}

void bt(int i){
  if( i == s.size() ){
    found = true;
    return ;
  }
  
  int n = (startFrom9)?9:s[i]-'0';
  while( n >= 0 && !found ){
    if( isValid(n) ){
      solution.push_back(n);
      counters[n]++;
      bt(i+1);
    }else{
      startFrom9 = true;
    }
    n--;
  }
  if( !found ){
    startFrom9 = true;
    int n = solution.back();
    counters[n]--;
    solution.pop_back();
  }
}

int main(){
  while( cin >> s ){
    solution.clear();
    for(int i = 0; i < 10; i++)
      counters[i] = 0;
    found = false;
    startFrom9 = false;

    bt(0);
    {
      int i = 0;
      while( i < solution.size() && solution[i] == 0 )
	i++;
      while( i < solution.size() ){
	cout << solution[i];
	i++;
      }
      cout << endl;
    }
  }
  return 0;
}

// AC
