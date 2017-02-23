#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortingSubsets{
public:
  int getMinimalSize(vector<int> v){
    vector<int> u = v;
    sort(begin(u), end(u));

    int ans = 0;
    for(int i = 0; i < v.size(); i++){
      if( u[i] != v[i] )
	ans++;
    }

    return ans;
  }
};

int main(){
  SortingSubsets x;
  cout << x.getMinimalSize({1, 2, 3, 4}) << endl;
  cout << x.getMinimalSize({4, 4, 4, 3, 3, 3}) << endl;
  cout << x.getMinimalSize({11, 11, 49, 7, 11, 11, 7, 7, 11, 49, 11}) << endl;
  
  return 0;
}

// AC
