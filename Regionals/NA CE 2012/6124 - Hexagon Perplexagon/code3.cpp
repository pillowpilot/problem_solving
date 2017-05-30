#include <iostream>
#include <vector>
#include <set>

#define rep(i, a, b) for(__typeof(a) i=a; i <=b; i++)
#define repi(i, a, b) for(__typeof(a) i=a; i >=b; i--)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back

using namespace std;

typedef vector<int> vi;

void print(const vi& v){
  rep(i, 0, v.size()-2){
    cout << v[i] << " ";
  }
  cout << v[v.size()-1] << endl;
}

struct piece{
  int r;
  vi v;
  piece(): v(6), r(0)
  { }
  piece(const vi& v): v(v), r(0)
  { }

  int d(int e, int pos){
    int dist = 0;
    while( v[pos] != e ){
      pos = (pos+1)%v.size();
      dist++;
    }
    return dist;
  }

  void rotate(int r){
    this->r = r;
  }

  void align(int e, int pos){
    this->rotate(this->d(e, pos));
  }

  int get(int pos){
    return v[(pos+r)%v.size()];
  }

  void print(ostream& os=cout){
    os << "[";
    rep(i, 0, v.size()-2){
      os << this->get(i) << " ";
    }
    os << this->get(v.size()-1);
    os << "]";
    os << " " << r << endl;
  }
};

vector<piece> m(7);
vi ans(7);
vector<bool> used(7);
bool bt(int n){
  if( n == 7 ){
    return m[ans[6]].get(1) == m[ans[1]].get(4);
  }else{
    rep(i, 0, ans.size()-1){
      if( !used[i] ){
	used[i] = true;
	ans[n] = i;

	if( n == 0 ){
	  m[ans[0]].align(1, 0);
	  if( bt(n+1) ) return true;
	}else if( n == 1 ){
	  m[ans[n]].align(m[ans[0]].get(0), 3);
	  if( bt(n+1) ) return true;
	}else if( n == 2 ){
	  m[ans[n]].align(m[ans[0]].get(1), 4);
	  if( m[ans[n]].get(5) == m[ans[n-1]].get(2) && bt(n+1) ) return true;
	}else if( n == 3 ){
	  m[ans[n]].align(m[ans[0]].get(2), 5);
	  if( m[ans[n]].get(0) == m[ans[n-1]].get(3) && bt(n+1) ) return true;
	}else if( n == 4 ){
	  m[ans[n]].align(m[ans[0]].get(3), 0);
	  if( m[ans[n]].get(1) == m[ans[n-1]].get(4) && bt(n+1) ) return true;
	}else if( n == 5 ){
	  m[ans[n]].align(m[ans[0]].get(4), 1);
	  if( m[ans[n]].get(2) == m[ans[n-1]].get(5) && bt(n+1) ) return true;
	}else if( n == 6 ){
	  m[ans[n]].align(m[ans[0]].get(5), 2);
	  if( m[ans[n]].get(3) == m[ans[n-1]].get(0) && bt(n+1) ) return true;
	}
	
	used[i] = false;
      }
    }
    return false;
  }
}

int main(){
  int n;
  cin >> n;
  rep(cs, 1, n){
    m.clear();
    rep(i, 1, 7){
      vi v;
      rep(j, 1, 6){
	int e;
	cin >> e;
	v.pb(e);
      }
      piece p(v);
      m.pb(p);
    }

    rep(i, 0, 6){
      used[i] = false;
    }

    bool found = bt(0);

    cout << "Case " << cs << ": ";
    if(found){
      rep(i, 0, ans.size()-2){
	cout << ans[i] << " ";
      }
      cout << ans[ans.size()-1] << "\n";
    }else
      cout << "No solution\n";
  }
}

// AC

/*
  BT checking on the fly.
  The query amount is ~13000 so 
  check every permutation rotating will TLE (with next_permutation, heap's alg, etc.), 
  bting and wait to check the exterior edges until the final call will TLE
 */
