#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool cover(ll city_pos, ll towers[], ll k, int a, int b){
  if( a > b )
    return false;
  
  int tower = a+(b-a)/2;
  
  if( city_pos < towers[tower] - k){
    return cover(city_pos, towers, k, a, tower-1);
  }else if( towers[tower] + k < city_pos ){
    return cover(city_pos, towers, k, tower+1, b);
  }else{
    return true;
  }
}
  

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n, m;
  cin >> n >> m;

  ll cities[n];
  ll towers[m];

  for(int i = 0 ; i < n; i++){
    cin >> cities[i];
  }
  //sort(cities, cities+n);
  
  for(int i = 0; i < m; i++){
    cin >> towers[i];
  }
  //sort(towers, towers+m);

  ll mink = 0;
  ll maxk = (ll) 2e9+1;
  while( mink != maxk ){
    ll k = mink + (maxk-mink)/2;

    bool finalc=true; // unnecesary...  just for tests...
    bool c;
    for(int i = 0; i < n; i++){
      c=cover(cities[i], towers, k, 0, m-1);
      if( !c ){
	finalc = c;
      }
    }

    if( finalc ){
      maxk = k;
    }else{
      mink = k+1;
    }
    
  }

  cout << mink << endl;  
  return 0;
}

// AC
