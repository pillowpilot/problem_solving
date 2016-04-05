#include <cstdio>
#include <vector>
#include <algorithm>

#define rep(c, a, b) for(int c = a; c < b; c++)

using namespace std;

typedef vector<int> vi;

vi s;

void solve(){
  bool endline = false;

  rep(a, 0, s.size()){
    rep(b, a + 1, s.size()){
      rep(c, b + 1, s.size()){
	rep(d, c + 1, s.size()){
	  rep(e, d + 1, s.size()){
	    rep(f, e + 1, s.size()){
	      if( endline == true ) printf("\n");
	      printf("%d %d %d %d %d %d", s[a], s[b], s[c], s[d], s[e], s[f]);
	      endline = true;
	    }
	  }
	}
      }
    }
  }
}

int main(){
  int k;

  s.reserve(50);
  
  scanf("%d", &k);
  while( k != 0 ){

    s.clear();
    while( k-- > 0 ){
      int a;
      scanf("%d", &a);
      s.push_back(a);
    }
    sort(s.begin(), s.end());
    
    solve();

    scanf("%d", &k);
    if( k != 0 ) printf("\n\n");
  }
  return 0;
}
