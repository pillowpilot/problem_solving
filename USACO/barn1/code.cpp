/*
  ID: carlos.16
  PROG: barn1
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

template <class T>
void print(const vector<T> v){
  cout << "[";
  if( !v.empty() ){
    typename vector<T>::const_iterator iter = v.begin();
    cout << *iter;
    iter++;
    while( iter != v.end() ){
      cout << ", " << *iter;
      iter++;
    }
  }
  cout << "]" << endl;
}

int main(){
  ifstream input("barn1.in");
  ofstream output("barn1.out");

  int m, s, c;
  input >> m >> s >> c;
  /*debug(m);
  debug(s);
  debug(c);*/

  vector<bool> stalls(s, false);
  rep(i, 1, c){
    int id;
    input >> id;
    id--;
    stalls[id] = true;
  }

  vector<int> used, free;

  int i = 0;
  while( i < s && !stalls[i] )
    i++;
  while( 0 > s && !stalls[s-1] )
    s--;
  
  while( i < s ){
    int l = 0;
    if( stalls[i] ){
      while( i < s && stalls[i] ){
	l++;
	i++;
      }
      used.push_back(l);
    }else{
      while( i < s && !stalls[i] ){
	l++;
	i++;
      }
      free.push_back(l);
    }
  }
  sort(all(used));
  sort(all(free));

  /*print(stalls);
  print(used);
  print(free);*/

  int ans;
  ans = 0;
  rep(i, 0, used.size()-1){
    ans += used[i];
  }
  /*debug(ans);
    debug(used.size());*/
  if( used.size() > m ){
    int diff = used.size() - m;
    //debug(diff);
    rep(i, 0, diff-1){
      ans += free[i];
    }
  }

  //cout << ans << endl;
  output << ans << endl;
  
  return 0;
}

// AC
/*
  Greedy by sorting. Divide the stalls in "segments" if their used or not.
  Classify in two set (one of the used stalls...)
  And sort every set.
  ___**___*_*****
  Will generate used=[1, 2, 5] and [1, 3, 3].

  If the max amount m is higher than the amount of used segments. ans = sum over used segments.
  Else ans = sum over used segments and some of the first unused segments. Add those until 
  the amount of segments to buy are equal to m.
  (Every summand from the unused implies one buy less)

  Ignore the run of stalls from the start and from the end.

  M = 2
  ___**___*_*****__
  ___(**)___(*)_(*****)__ cover only the used stalls
  ___(**)___(*_*****)__ cover the SHORTEST (greedy factor) run of stalls

  Another approach (greedy as well) may be start with one board that covers all used stalls except those
  unused from the sides (if any). Then divide it excluding those stalls that corresponds to the longest
  run of stalls (inside the board). Keep dividing until M or is no possible (when there is no unused stalls
  inside the boards).

  M = 2
  ___**___*_*****__
  ___(**___*_*****)__ one long board
  ___(**)___(*_*****)__ divide by the LONGEST (greedy factor) run of stalls

 */
