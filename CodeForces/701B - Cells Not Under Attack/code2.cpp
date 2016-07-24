#include <iostream>

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n, m;
  cin >> n >> m;

  ll nat = 0;
  ll x[n] = {0};
  ll y[n] = {0};
  ll difx = 0;
  ll dify = 0;
  ll area = (ll)(n)*n;
  while( m-->0){
    int a, b;
    cin >> b >> a;
    a--; b--;

    ll na = 0;
    if( x[a] == 0 && y[b] == 0 )
      na = n-1-difx-dify+n;
    else if( x[a] == 0 )
      na = n -dify;
    else if( y[b] == 0 )
      na = n -difx;

    if( x[a] == 0 ){
      x[a] = 1;
      difx++;
    }
    if( y[b] == 0 ){
      y[b] = 1;
      dify++;
    }
    //cout << ">> " << na << endl;
    nat+=na;
    cout << area - nat << ' ';
  }
  cout << endl;
  return 0;
}

// AC
