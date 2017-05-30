/*
  ID: carlos.16
  PROG: numtri
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

#define rep(i, a, b) for(__typeof(a)i=a;i<=b;i++)
#define repi(i, a, b) for(__typeof(a)i=a;i>=b;i--)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
  ifstream input("numtri.in");
  ofstream output("numtri.out");

  int n;
  input >> n;

  vvi m(n, vi(n));
  rep(i, 0, n-1){
    rep(j, 0, i){
      int e;
      input >> e;
      m[i][j] = e;
    }
  }

  repi(i, n-2, 0){
    rep(j, 0, i){
      int x = m[i+1][j];
      int y = m[i+1][j+1];
      m[i][j] += max(x, y);
    }
  }

  cout << m[0][0] << endl;
  output << m[0][0] << endl;
  
  return 0;
}

// AC
/*
  ~0.12s for n=1000
  Lets treat this triangle as a tree. We could reduce the tree to a single node by reducing the leaves.
  Another approach could be expand the root to the leaves and find the max. With this method we could get 
  the k-th path.
  Both takes O(n^2).
 */
