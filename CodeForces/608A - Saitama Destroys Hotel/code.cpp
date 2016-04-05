#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, s;
  cin >> n >> s;
  vector<int> pp(s+1, 0);
  while(n-->0){
    int f, t;
    cin >> f >> t;
    pp[f] = max(pp[f], t);
  }
  int ct = 0;
  for(int i = pp.size() - 1; i > 0; i--){
    if(pp[i] == 0) ct++;
    else{
      if(pp[i] <= ct) ct++;
      else ct = pp[i] + 1;
    }
  }

  cout << ct << endl;
  
  return 0;
}

// AC
