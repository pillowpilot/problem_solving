/*
  ID: carlos.16
  PROG: ride
  LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;

int f(const string s){
  int ans = 1;
  for(int i = 0; i < s.size(); i++){
    ans = (ans*(s[i]-'A'+1))%47;
  }
  return ans;
}

int main(){
  ifstream input("ride.in");
  ofstream output("ride.out");

  string c, g;
  input >> c >> g;

  int a = f(c);
  int b = f(g);

  if( a == b )
    output << "GO" << endl;
  else
    output << "STAY" << endl;
  
  return 0;
}

// AC
