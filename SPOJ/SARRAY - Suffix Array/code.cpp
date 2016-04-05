#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Data{
  int sa, msd, lsd;
  Data(){ sa = msd = lsd = 0;}
  Data(int sa, int msd, int lsd):sa(sa), msd(msd), lsd(lsd) {}
  bool operator<(const Data& d) const{
    if( msd != d.msd ){
      return msd < d.msd;
    }else{
      if( lsd != d.lsd ){
	return lsd < d.lsd;
      }else{
	return false; // If equals, then false.
      }
    }
  }
  bool operator!=(const Data& d) const{
    return this->operator<(d);
  }
};

typedef vector<Data> vd;
typedef vector<int> vi;

vd v;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << '[';

  if( v.size() != 0 ){
    typename vector<T>::const_iterator iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os <<  ", " << *iter;
      iter++;
    }
  }

  os << ']';
}

void constructSA(string s){
  int gap = 1;
  v = vd();
  vi aux = vi(s.size());

  for( int i = 0; i < s.size(); i++ ) v.push_back( Data(i, s[i], ( i != s.size() - 1 )?s[i+1]:-1) );

  sort(v.begin(), v.end());

  while( gap < s.size() ){
    gap *= 2;

    int value = 0;
    for( int i = 0; i < s.size(); i++){
      if( v[i] != v[i+1] ){
	v[i].msd = value;
	value++;
      }else{
	v[i].msd = value;
      }
    }
    
    for( int i = 0; i < s.size(); i++) aux[ v[i].sa ] = i;

    for( int i = 0; i < s.size(); i++){
      int index = v[i].sa + gap;
      if( index >= s.size() ){
	v[i].lsd = -1;
      }else{
	v[i].lsd = v[ aux[index] ].msd;
      }
    }

    sort( v.begin(), v.end() );
    
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  
  string s;
  //s = string("abracadabra0AbRa4Cad14abra");
  cin >> s;

  constructSA(s);

  for( int i = 0; i < v.size(); i++ ){
    cout << v[i].sa << "\n";
  }
  cout << flush;

  return 0;
  
}

// AC 100points
