#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

string input;
vi counters;
vc solution;

int f(int m){
  m--;
  while( m >= 0 && counters[m] >= 2 )m--;
  return m;
}

int main(){
  bool flag = false;
  while( cin >> input ){
    if(flag) cout << endl;
    flag = true;
    counters = vi(10, 0);
    solution = vc();
    int i = 0;
    while( i < input.size() && counters[input[i]-'0'] < 2 ){
      counters[input[i]-'0']++;
      solution.push_back( input[i] );
      i++;
    }
    if( i < input.size() ){
      int x;
      while( i < input.size() && (x=f(input[i]-'0')) == -1 ){ // Find start point
	counters[ solution.back()-'0' ]--;
	solution.pop_back();
	i--;
      }
      solution.push_back(x+'0');
      while( i < input.size()-1 ){ // Greedy fill
	x = f(10);
	solution.push_back(x+'0');
	counters[x]++;
	i++;
      }
    }
    i = 0;
    while( solution[i] == '0') i++;
    while( i < solution.size() ) cout << solution[i++];
  }
  
  return 0;
}
