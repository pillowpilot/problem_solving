#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data{
  int sa, msd, lsd;
  Data(){ sa = msd = lsd = 0; }
  Data(int sa, int msd, int lsd): sa(sa), msd(msd), lsd(lsd) {}
  bool operator<(const Data& d) const{
    if( msd != d.msd ) return msd < d.msd;
    else{
      if( lsd != d.lsd ) return lsd < d.lsd;
      else return false;
    }
  }
  bool operator!=(const Data& d) const{
    return this->operator<(d);
  }
};

typedef vector<Data> vd;
typedef vector<int> vi;

vd v;
vi aux;

void print(){
  for( int i = 0; i < v.size(); i++ ){
    cout << v[i].sa << " ";
  }
  cout << endl;
}

void constructSA(const string& s){
  int gap = 1;
  v = vd();
  aux = vi( s.size() );

  for( int i = 0; i < s.size(); i++ ) v.push_back( Data(i, s[i], (i!=s.size()-1)?s[i+1]:-1) );
  
  sort( v.begin(), v.end() );

  while( gap <= s.size() ){
    gap *= 2;

    // Construct MSD
    int value = 0;
    for( int i = 0; i < s.size()-1; i++ ){
      if( v[i] != v[i+1] ){
	v[i].msd = value;
	value++;
      }else{
	v[i].msd = value;
      }
    }
    v[s.size()-1].msd = value;
    

    // Construct AUX
    for( int i = 0; i < s.size(); i++ ) aux[ v[i].sa ] = i;

    // Construct LSD
    for( int i = 0; i < s.size(); i++ ){
      int index = v[i].sa + gap; // Easy mistake
      if( index >= s.size() ){
	v[i].lsd = -1;
      }else{
	v[i].lsd = v[ aux[index] ].msd;
      }
    }

    // Sort
    sort( v.begin(), v.end() );
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  
  int n;
  string s;

  cin >> n;

  while( n-- > 0 ){
    cin >> s;
    s = s+s;
    constructSA(s);

    int index = 0;
    while( index < v.size() && v[index].sa > s.size() / 2 ) index++;
    cout << v[index].sa + 1;
    
    if( n != 0 ) cout << "\n";
  }
  cout << flush;
  
  return 0;
}

// WA
