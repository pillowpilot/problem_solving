#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define mk make_pair
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i <= b; i++)

using namespace std;

struct box{
  int a, b, c;
  box(): a(0), b(0), c(0) {}
  void read(){
    cin >> a >> b >> c;
  }
  void shift(){
    swap(a, b);
    swap(a, c);
  }
};

vector<box> bx;
vector<bool> used;

bool stackable(const box& a, const box& b){
  return (a.a >= b.a && a.b >= b.b)||
    (a.a >= b.b && a.b >= b.a);
}

bool stackable(int i, int j){
  return stackable(bx[i], bx[j]);
}

int ans;
void bt(int last, int height){
  //debug(height);
  
  ans = max(ans, height);
  rep(i, 0, used.size()-1){
    if( used[i] == false ){
      used[i] = true;
      if( stackable(last, i) ) bt(i, height+1);
      bx[i].shift();
      if( stackable(last, i) ) bt(i, height+1);
      bx[i].shift();
      if( stackable(last, i) ) bt(i, height+1);
      bx[i].shift();
      used[i] = false;
    }
  }
}

int main(){
  int n, cs=1;
  cin >> n;
  while( n != 0 ){
    bx.clear();
    bx.resize(n+1);
    bx[0].a = bx[0].b = bx[0].c = 21;
    rep(i, 1, n){
      bx[i].read();
    }
    used.resize(n+1);
    fill(all(used), false);

    ans = -1; // This line cost me a WA!!!!
    used[0] = true;
    bt(0, 0);

    cout << "Case " << cs << ": " << ans << endl;
    
    cin >> n;
    cs++;
  }
  
  return 0;
}

// AC
/*
  Typical BT.
 */
