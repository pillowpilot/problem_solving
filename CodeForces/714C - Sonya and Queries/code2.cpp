#include <iostream>
#include <map>

using namespace std;

typedef map<string, int> msi;

int main(){
  int n;
  cin >> n;

  int dc[20] = {0};
  msi set;
  while( n-- > 0 ){
    char op;
    cin >> op;

    string s;
    cin >> s;

    string delta;
    for(int i = 0; i < 20 - s.size(); i++){
      delta.push_back('0');
    }
    s.insert(0, delta);

    if( op == '+' ){
      set[s]++;
	
      for(int i = 0; i < s.size(); i++){
	int d = s[i] - '0';
	if( d % 2 == 0 ){
	  dc[i]++;
	}
      }
      
    }else if( op == '-' ){
      set[s]--;
      	
      for(int i = 0; i < s.size(); i++){
	int d = s[i] - '0';
	if( d % 2 == 0 ){
	  dc[d]--;
	}
      }
      
    }else{

      int even = dc[0];
      for(int i = 0;i < s.size(); i++){
	if( s[i] == '0' ){
	  even = min(even, 
	}
      }
    }

  }
  return 0;
}
