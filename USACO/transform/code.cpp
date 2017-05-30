/*
  ID: carlos.16
  PROG: transform
  LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define rep(i, a, b) for(__typeof(a) i=a; i <=b; i++)
#define debug(x) cout << #x << " = " << x << endl;

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print(const vvi& m){
  int n = m.size();
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      cout << m[i][j];
    }
    cout << endl;
  }
}

vvi rotate(const vvi& o){
  int n = o.size();
  vvi r(n, vi(n, 0));

  rep(i, 0, n-1){
    rep(j, 0, n-1){
      r[j][n-1-i] = o[i][j];
    }
  }

  return r;
}

vvi reflect(const vvi& o){
  int n = o.size();
  vvi r(n, vi(n, 0));
  
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      r[i][n-1-j] = o[i][j];
    }
  }
  return r;
}

bool compare(const vvi& a, const vvi& b){
  int n = a.size();
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      if( a[i][j] != b[i][j] )
	return false;
    }
  }
  return true;
}

void read(ifstream& input, vvi& m){
  int n = m.size();
  rep(i, 0, n-1){
    string line;
    input >> line;
    rep(j, 0, n-1){
      m[i][j] = (line[j]=='@')?1:0;
    }
  }
}

int main(){
  ifstream input("transform.in");
  ofstream output("transform.out");

  int n;
  input >> n;
  vvi s(n, vi(n, 0));
  read(input, s);
  vvi t(n, vi(n, 0));
  read(input, t);

  vvi rot90 = rotate(s);
  vvi rot180 = rotate(rot90);
  vvi rot270 = rotate(rot180);
  vvi refl = reflect(s);
  vvi refl90 = rotate(refl);
  vvi refl180 = rotate(refl90);
  vvi refl270 = rotate(refl180);

  int ans;
  if( compare(t, rot90) ) ans = 1;
  else if( compare(t, rot180) ) ans = 2;
  else if( compare(t, rot270) ) ans = 3;
  else if( compare(t, refl) ) ans = 4;
  else if( compare(t, refl90) ) ans = 5;
  else if( compare(t, refl180) ) ans = 5;
  else if( compare(t, refl270) ) ans = 5;
  else if( compare(t, s) ) ans = 6;
  else ans = 7;
  
  //cout << ans << endl;
  output << ans << endl;

  return 0;
}

// AC
/*
  Check operations with a matrix where every element is unique
 */
