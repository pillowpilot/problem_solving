#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

struct Data{
  int msd, lsd, sa, lcp;
  Data(){ msd = lsd = sa = lcp = 0; }
  Data(int msd, int lsd, int sa): msd(msd), lsd(lsd), sa(sa), lcp(0) {}
};

vector<Data> v;

template <typename C>
ostream& operator<<(ostream& os, const vector<C>& v){
  os << '[';

  if( v.size() != 0 ){
    typename vector<C>::const_iterator iter = v.begin();
    os << *iter << " ";
    iter++;
    while( iter != v.end() ){
      os << *iter << " ";
      iter++;
    }
  }
  
  os << ']';
  return os;
}

ostream& operator<<(ostream& os, const Data& d){
  os << d.sa;
  return os;
}

template <typename P, typename Q>
ostream& operator<<(ostream& os, const pair<P, Q>& p){
  return os << '(' << p.first << ", " << p.second << ')';
}

inline bool comparator(const Data& a, const Data& b){
  return (a.msd < b.msd) || (a.msd == b.msd && a.lsd < b.lsd);
}

void salcp(const string& s){
  // Suffix Array Construction
  const int n = s.size();
  int gap = 1;
  vector<int> sainv(n);

  v.clear();
  for(int i = 0; i < n-1; i++){
    v.push_back( Data(s[i] - 'a', s[i+1] - 'a', i) );
  }
  v.push_back( Data(s[n-1] - 'a', -1, n-1) );

  sort( v.begin(), v.end(), comparator);

  while( gap <= n ){
    gap *= 2;

    // SA Inverse
    for(int i = 0; i < n; i++)
      sainv[ v[i].sa ] = i;

    // MSD
    int value = 0;
    for(int i = 0; i < n-1; i++){
      if( comparator(v[i], v[i+1]) == false ){
	v[i].msd = value;
      }else{
	v[i].msd = value;
	value++;
      }
    }
    v[ n-1 ].msd = value;

    // LSD
    for(int i = 0; i < n; i++){
      int index = v[i].sa + gap;
      if( sainv.size() <= index )
	v[i].lsd = -1;
      else
	v[i].lsd = v[ sainv[index] ].msd;
    }

    sort( v.begin(), v.end(), comparator );
  }

  // LCP Array construction
  for(int i = 0; i < sainv.size(); i++)
    sainv[ v[i].sa ] = i;

  int k = 0;
  for(int i = 0; i < sainv.size(); i++){
    if( sainv[i] != v.size() - 1 ){
      int a = i;
      int b = v[ sainv[i]+1 ].sa;

      while( a + k < s.size() && b + k < s.size() && s[a+k] == s[b+k] )
	k++;

      v[sainv[i]].lcp = k;

      k--;
      if(k < 0)
	k = 0;
    }else{
      k = 0;
    }
  }

}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s1, s2, s;

  bool isFirst = true;
  while( cin >> s1 >> s2 ){
    s = s1 + "#" + s2;

    salcp(s);
    
    int maxLCP = 0;
    for(int i = 0; i < v.size(); i++){
      int typei = (v[i].sa < s1.size())?1:2;
      int typei1 = (v[i+1].sa < s1.size())?1:2;

      if( typei != typei1 )
	maxLCP = max(maxLCP, v[i].lcp);
    }

    set<string> ans;
    for(int i = 0; i < v.size(); i++){
      int typei = (v[i].sa < s1.size())?1:2;
      int typei1 = (v[i+1].sa < s1.size())?1:2;

      if( typei != typei1 && v[i].lcp == maxLCP ){
	ans.insert( s.substr( v[i].sa, maxLCP ) );
      }
    }

    if( !isFirst )
      cout << '\n';
    isFirst = false;

    if( maxLCP == 0 )
      cout << "No common sequence.\n";
    else{
      auto iter = ans.begin();
      while( iter != ans.end() ){
	cout << *iter << '\n';
	iter++;
      }
    }
      
  }
  
  return 0;
}

// AC
