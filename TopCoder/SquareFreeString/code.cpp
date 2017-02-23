#include <iostream>
#include <string>

using namespace std;

class SquareFreeString{
public:
  bool isSquare(const string& s, int a, int b){

    if( (b-a+1)%2 == 1 )
      return false;
    
    int i = 0;
    while( i < (b-a+1)/2 && s[a+i] == s[a+(b-a+1)/2+i]){
      i++;
    }

    if( i < (b-a+1)/2 )
      return false;
    else
      return true;
  }
  string isSquareFree(string s){
    for(int i = 0; i < s.size(); i++){
      for(int j = i+1; j < s.size(); j++){
	
	if( isSquare(s, i, j) )
	  return "not square-free";
	
      }
    }
    return "square-free";
  }
};

int main(){
  SquareFreeString x;
  cout << x.isSquareFree("abc") << endl;
  cout << x.isSquareFree("bobo") << endl;
  cout << x.isSquareFree("apple") << endl;
  cout << x.isSquareFree("qwertyuiopasdfghjklzxcvbnm") << endl;
  return 0;
}

// AC
