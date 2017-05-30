#include <iostream>
#include <cstdio>
#include <vector>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)
#define repi(i, a, b) for(__typeof(a) i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi m;
vi ans;

void print(const vi& v){
  rep(i, 0, v.size()-1){
    //cout << v[i] << " ";
    printf("%d ", v[i]);
  }
  //cout << endl;
  printf("\n");
}

inline void rot(int h){
  int last = m[h][m[h].size()-1];
  for(int i = m[h].size()-2; i >= 0; i--){
    m[h][i+1] = m[h][i];
  }
  m[h][0] = last;
}

bool check(){
  /*while( m[ans[0]][0] != 1 )
    rot(ans[0]);

  while( m[ans[1]][3] != m[ans[0]][0] ) rot(ans[1]);
  while( m[ans[2]][4] != m[ans[0]][1] ) rot(ans[2]);
  while( m[ans[3]][5] != m[ans[0]][2] ) rot(ans[3]);
  while( m[ans[4]][0] != m[ans[0]][3] ) rot(ans[4]);
  while( m[ans[5]][1] != m[ans[0]][4] ) rot(ans[5]);
  while( m[ans[6]][2] != m[ans[0]][5] ) rot(ans[6]);*/

  /*rep(i, 0, 6){
    printf("%d : ", ans[i]);
    print(m[ans[i]]);
    }*/

  //center
  /*printf("%d ", m[ans[1]][3]);
  printf("%d ", m[ans[0]][0]);
  
  printf("%d ", m[ans[2]][4]);
  printf("%d ", m[ans[0]][1]);

  printf("%d ", m[ans[3]][5]);
  printf("%d ", m[ans[0]][2]);

  printf("%d ", m[ans[4]][0]);
  printf("%d ", m[ans[0]][3]);

  printf("%d ", m[ans[5]][1]);
  printf("%d ", m[ans[0]][4]);

  printf("%d ", m[ans[6]][2]);
  printf("%d ", m[ans[0]][5]);*/
  
  if( m[ans[1]][3] != m[ans[0]][0] ) return false;
  if( m[ans[2]][4] != m[ans[0]][1] ) return false;
  if( m[ans[3]][5] != m[ans[0]][2] ) return false;
  if( m[ans[4]][0] != m[ans[0]][3] ) return false;
  if( m[ans[5]][1] != m[ans[0]][4] ) return false;
  if( m[ans[6]][2] != m[ans[0]][5] ) return false;

  // laterals
  if( m[ans[1]][2] != m[ans[2]][5] ) return false;
  if( m[ans[2]][3] != m[ans[3]][0] ) return false;
  if( m[ans[3]][4] != m[ans[4]][1] ) return false;
  if( m[ans[4]][5] != m[ans[5]][2] ) return false;
  if( m[ans[5]][0] != m[ans[6]][3] ) return false;
  if( m[ans[6]][1] != m[ans[1]][4] ) return false;

  return true;
}

bool heaps(int n){
  if( n == 1 ){
    return check();
  }else{
    rep(i, 0, n-1){
      bool r = heaps(n-1);
      if( r ) return true;
      
      if( n%2 == 1 )
	swap(ans[0], ans[n-1]);
      else
	swap(ans[i], ans[n-1]);
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int n;
  //cin >> n;
  scanf("%d", &n);
  rep(cs, 1, n){
    m.clear();
    rep(i, 1, 7){
      vi piece;
      rep(j, 1, 6){
	int e;
	//cin >> e;
	scanf("%d", &e);
	piece.pb(e);
      }
      m.pb(piece);	
    }

    ans.clear();
    rep(i, 0, 6){
      ans.pb(i);
    }
    
    bool found;
    found = heaps(ans.size());
    
    //cout << "Case " << cs << ": ";
    printf("Case %d: ", cs);
    if( found ){
      int rots = 0;
      while( m[ans[0]][0] != 1 ){
	rot(ans[0]);
	int last = ans[6];
	for(int i = 5; i >= 1; i--){
	  ans[i+1] = ans[i];
	}
	ans[1] = last;
	rots++;
      }

      printf("%d ", ans[0]);
      printf("%d ", ans[1]);
      printf("%d ", ans[2]);
      printf("%d ", ans[3]);
      printf("%d ", ans[4]);
      printf("%d ", ans[5]);
      printf("%d\n", ans[6]);      
      //cout << endl;
      printf("\n");
    }else{
      //cout << "No solution" << endl;
      printf("No solution\n");
    }
  }
}

// TLE
