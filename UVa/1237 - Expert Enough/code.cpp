#include <iostream>
#include <vector>
#include <string>

#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

struct carmaker{
  pair<int, int> p;
  string name;
  carmaker(int l, int h, string n)
  {
    p = make_pair(l, h);
    name = n;
  }
  carmaker(const carmaker& o){
    p = o.p;
    name = o.name;
  }
  bool operator<(const carmaker& o){
    return p.first < o.p.first || (p.first==o.p.first && p.second < o.p.second);
  }
  void print() const {
    cout << name << " [" << p.first << ", " << p.second << "]" << endl;
  }
};

typedef vector<carmaker> vcm;

bool inRange(const carmaker x, int p){
  bool ans = x.p.first <= p && p <= x.p.second;
  /*if( ans )
    cout << p << " is in " << x.p.first << " " << x.p.second << endl;
  else
  cout << p << " is NOT in " << x.p.first << " " << x.p.second << endl;*/
  return ans;
}

int main(){
  int t;
  cin >> t;
  rep(cs, 1, t){
    int d;
    cin >> d;

    vcm data;
    rep(i, 1, d){
      string name;
      int l, h;
      cin >> name >> l >> h;
      carmaker x(l, h, name);
      data.push_back(x);
    }

    int q;
    cin >> q;
    rep(j, 1, q){
      int p;
      cin >> p;

      int c = 0;
      int ansi;
      int i = 0;
      while( i < data.size() && c < 2){
	if( inRange(data[i], p) ){
	  ansi = i;
	  c++;
	}
	i++;
      }

      if( c == 1 ){
	cout << data[ansi].name << "\n";
      }else
	cout << "UNDETERMINED\n";
    }

    if( cs != t ) cout << endl;
  }
  
  return 0;
}

// AC
/*
  Seems like BS can not be applied. Just BT it.
 */
