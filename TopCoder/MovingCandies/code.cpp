#include <iostream>
#include <vector>

using namespace std;

class MovingCandies{
public:
  typedef vector<string> vc;
  typedef vector<int> vi;
  typedef vector<vi> vvi;
  
  //vector<int> of = vector<int>{-1, 0, 1, 0, -1, 0, 1, 0, -1};
  vvi memo = vvi(20, vi(20, -1));
  vvi visited = vvi(20, vi(20, -1));
  vvi parent = vvi(20, vi(20, -1));
  
  int minMoved(vc t){
    if( t[0][0] == '#' )
      memo[0][0] = 0;

    int needed = f(t, t.size()-1, t[t.size()-1].size()-1);

    return needed;
  }

  bool isValid(const vc& t, int x, int y){
    return 0 <= x && 0 <= y && x < t.size() && y < t[x].size();
  }

  int f(const vc& t, int x, int y){
    if(memo[x][y] != -1)
      return memo[x][y];

    int ans = 9999;
    int of[] = {-1, 0, 1, 0, -1, 0, 1, 0};
    for(int i = 0; i < 4; i++){
      int a = x+of[i];
      int b = y+of[i+1];
      if( isValid(t, a, b) && visited[a][b] == -1 ){
	visited[a][b] = 1;
	int c = f(t, a, b) + ( t[a][b] == '#' )?0:1;
	if( c < ans ){
	  ans = c;
	}
      }
    }
    
    memo[x][y] = ans;
    return ans;
  }
};

int main(){
  MovingCandies x;
  cout << x.minMoved({ "#...###", "#...#.#", "##..#.#", ".#....#" }) << endl;
  return 0;
}
