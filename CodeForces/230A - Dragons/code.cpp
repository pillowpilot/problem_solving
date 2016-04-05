#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vp;

vp dd;

int main(){
  int s, n;
  dd = vp();
  scanf("%d %d", &s, &n);
  while( n-- > 0 ){
    int x, y;
    scanf("%d %d", &x, &y);
    dd.push_back(make_pair(x, y));
  }
  sort(dd.begin(), dd.end()); // Defeat the weakest dragon first. Greedy.
  int i = 0;
  while( i < dd.size() && dd[i].first < s ){
    s += dd[i].second;
    i++;
  }
  printf("%s\n", (i == dd.size())?"YES":"NO");
  return 0;
}

// AC
