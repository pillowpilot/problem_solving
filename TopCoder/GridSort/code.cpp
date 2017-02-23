#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

class GridSort{
public:
  string sort(int n, int m, vector<int> v){
    set<int> s;
    for(int i = 0; i < n; i++){
      s.clear();
      for(int j = 0; j < m; j++){
	int a = (v[i*m+j]-1) / m;
	s.insert(a);
      }
      if( s.size() != 1 ){
	return "Impossible";
      }
    }

    for(int j = 0; j < m; j++){
      s.clear();
      for(int i = 0; i < n; i++){
	int a = (v[i*m+j]) % m;
	s.insert(a);
      }
      if( s.size() != 1 ){
	return "Impossible";
      }

    }

    return "Possible";
  }
};

int main(){
  GridSort x;
  cout << x.sort(2, 2, vi{ 1,2, 3,4 }) << endl;
  cout << x.sort(3, 5, vi{ 10,6,8,9,7, 5,1,3,4,2, 15,11,13,14,12 }) << endl;
  cout << x.sort(6, 2, vi{ 11,12, 2,1, 9,10, 7,8, 6,5, 3,4 }) << endl;
  return 0;
}

// AC
