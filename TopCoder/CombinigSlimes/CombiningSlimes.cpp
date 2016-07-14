#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CombiningSlimes{
public:
  int maxMascots(vector<int> a){
    sort(a.begin(), a.end());
    
    unsigned long long mascots = 0;
    while( a.size() >= 2 ){
      unsigned long long x = a[ a.size() - 1 ];
      unsigned long long y = a[ a.size() - 2 ];

      mascots += x*y;
      a[ a.size() - 2] = x+y;
      a.pop_back();
    }

    return mascots;
  }
};

int main(){
  CombiningSlimes cs;
  cout << cs.maxMascots(vector<int>{3, 4}) << endl;
  cout << cs.maxMascots(vector<int>{2,2,2}) << endl;
  cout << cs.maxMascots(vector<int>{1,2,3}) << endl;
  cout << cs.maxMascots(vector<int>{3,1,2}) << endl;
  cout << cs.maxMascots(vector<int>{7,6,5,3,4,6}) << endl;
  
  return 0;
}
    
// AC
