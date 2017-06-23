#include <iostream>
#include <vector>
#include <iomanip>

#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a)i=a;i<=b;i++)
#define repi(i, a, b) for(__typeof(a)i=a;i>=b;i--)

using namespace std;

typedef vector<int> vi;

vi e;
vi low, high;

struct segmenttree{
  int N;
  vi st;
  segmenttree(int n){
    N=1;
    while(N < n)
      N <<= 1;
    st.assign(2*N, 0); //*
  }
  void buildTree(){
    repi(i, N-1, 1){
      st[i] = max(st[2*i], st[2*i+1]);
    }
  }
  void print(){
    return ;
    rep(i, 1, 2*N-1){
      if( i - (i&-i) == 0 )
	cout << "\n";
      cout << st[i] << " ";
    }
    cout << endl;
  }
  int sum(int a, int b)const{
    debug("in segtree");
    debug(a);
    debug(b);
    a+=N; b+=N;
    int s = 0;
    while( a<=b ){
      if(a%2==1) s = max(s, st[a++]); //*
      if(b%2==0) s = max(s, st[b--]); //*
      a>>=1; b>>=1;
    }
    return s;
  }
};

void print(const vi& v){
  return ;
  rep(i, 0, v.size()-1){
    cout << fixed << setw(3) << v[i] << " ";
  }
  cout << endl;
}

void f(){
  low.assign(e.size(), 0);
  high.assign(e.size(), 0);

  int l = 0;
  rep(i, 1, e.size()-1){
    if( e[i-1] != e[i] ){
      rep(j, l, i-1){
	low[j] = l;
	high[j] = i-1;
      }
      l = i;
    }
  }
  rep(j, l, low.size()-1){
    low[j] = l;
    high[j] = low.size()-1;
  }
  rep(i, 0, e.size()-1){
    //cout << fixed << setw(3) << i << " ";
  }
  //cout << endl;
  print(e);
  print(low);
  print(high);
}

void g(segmenttree& st){
  rep(i, 0, e.size()-1){
    st.st[st.N+i] = high[i]-low[i]+1;
  }
  st.buildTree();
  st.print();
}

int solve(const segmenttree& st, int a, int b){
  debug(a);
  debug(b);
  
  if( e[a] == e[b] )
    return b-a+1;

  int l = high[a]-a+1;
  int r = b-low[b]+1;
  int c = st.sum(high[a]+1, low[b]-1);
  debug(l);
  debug(r);
  debug(c);
  return max(l, max(r, c));
}

int main(){
  int n;
  cin >> n;
  while( n != 0 ){
    int q;
    cin >> q;

    e.clear();
    low.clear();
    high.clear();
    rep(i, 0, n-1){
      int x;
      cin >> x;
      e.push_back(x);
    }
    f();

    segmenttree st(n);
    g(st);

    rep(i, 1, q){
      int a, b;
      cin >> a >> b;
      //cout << ">> " << a << ", " << b << endl;
      a--; b--;
      int ans = solve(st, a, b);
      cout << ans << endl;
    }

    cin >> n;
  }
  return 0;
}

// AC
/*
  First implementation of SegTree! AC on the first run! ^_^
  Decompose the original queries in 3 parts. The borders (same numbers but not all numbers) and 
  RMQ solvable with ST or Sparce Table.
  [a, b] -> [a, l] + [l+1, h-1] + [h, b] where [a, l] and [h, b] consists in only one number each 
  and [l+1, h-1] could be empty and could be several numbers.
  -3 -3 [-3 1 1 1 1 6 10 10] 10 10 => [-3]+[1 1 1 1 6]+[10 10]
 */ 
