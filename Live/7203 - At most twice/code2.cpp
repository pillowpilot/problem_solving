#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
vector<int> counters(10);
vector<int> solution;
bool solutionFound, startFrom9;

void bt(int i){
  if( i == s.size() ){
    solutionFound = true;
    return;
  }

  int n = (startFrom9)?9:s[i]-'0';
  while( 0 <= n && !solutionFound ){
    if( counters[n] < 2 ){
      solution.push_back(n);
      counters[n]++;
      bt(i+1);
    }else{
      startFrom9 = true;
    }
    n--;
  }
  if( !solutionFound ){
    int n = solution.back();
    counters[n]--;
    solution.pop_back();
  }
}

int main(){
  while( cin >> s ){
    solution.clear();
    fill(begin(counters), end(counters), 0);
    solutionFound = startFrom9 = false;

    bt(0);
    int i = 0;
    while( solution[i] == 0 ) i++;
    while( i < solution.size() ) cout << solution[i++];
    cout << endl;
  }
}

// Untested, but very likely to be an AC.
