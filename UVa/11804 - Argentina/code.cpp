#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

#define rep(c, a, b) for(int c = a; c < b; c++)

using namespace std;

typedef struct{
  string name;
  int atk, def;
} player;

bool sortByName(const player& a, const player& b){
    return a.name < b.name;
}

typedef vector<player> vp;

vp ps;

bitset<10> solve(){
  bitset<10> atks;
  int maxAtk, maxDef;
  maxAtk = -1000;

  rep(a, 0, ps.size()){
    rep(b, a+1, ps.size()){
      rep(c, b+1, ps.size()){
	rep(d, c+1, ps.size()){
	  rep(e, d+1, ps.size()){
	    int atk = ps[a].atk + ps[b].atk + ps[c].atk + ps[d].atk + ps[e].atk;
	    int def = 0;
	    rep(x, 0, ps.size()){
	      if( x != a && x != b && x != c && x != d && x != e ){
		def += ps[x].def;
	      }
	    }
	    if( atk > maxAtk || (atk == max && def > maxDef) ){
	      atks.reset();
	      atks.set(a); atks.set(b); atks.set(c); atks.set(d); atks.set(e);
	      maxAtk = atk;
	      maxDef = def;
	    }
	  }
	}
      }
    }
  }
  return atks;
}

void present( const bitset<10>& atks, int caseId ){
  int c = 0, i = 0;
  printf("Case %d:\n(", caseId);
  while( c < 4 ){
    while( atks[i] == false ) i++;
    printf("%s ,", ps[i].name.data());
    c++; i++;
  }
  while( atks[i] == false ) i++;
  printf("%s)\n(", ps[i].name.data());

  c = 0; i = 0;
  while( c < 4 ){
    while( atks[i] == true ) i++;
    printf("%s ,", ps[i].name.data());
    c++; i++;
  }
  while( atks[i] == true ) i++;
  printf("%s)\n", ps[i].name.data());
  
}

void print();
int main(){
  int cases;

  ps.reserve(15);

  cin >> cases;
  rep(caseId, 0, cases){
    ps.clear();
    rep(i, 0, 10){
      player p;
      cin >> p.name >> p.atk >> p.def;
      ps.push_back(p);
    }
    sort( ps.begin(), ps.end(), sortByName );
    print();

    bitset<10> atks = solve();
    present(atks, caseId);

    //    printf("\n");
  }
  return 0;
}

void print(){
  vp::const_iterator iter = ps.begin();
  while( iter != ps.end() ){
    printf("%s %d %d\n", iter->name.data(), iter->atk, iter->def);
    iter++;
  }
}
