#include <cstdio>
#include <vector>
#include <list>
#include <limits>
#include <cmath>

using namespace std;

typedef long unsigned int uint;
typedef struct {
  uint id;
  int c, f;
} edata;

typedef struct {
  uint skill;
  list< edata > adj;
} vdata;
typedef vector< vdata > vv;

vv vs;

void printGraph(){
  vv::const_iterator iter = vs.begin();
  while( iter != vs.end() ){
    printf("[%lu, %lu] ->", iter - vs.begin(), iter->skill);
    list<edata>::const_iterator iiter = iter->adj.begin();
    while(iiter != iter->adj.end()){
      printf("(%lu, %d, %d) ", iiter->id, iiter->c, iiter->f);
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

void initGraph(){
  vdata vd;
  vs.reserve(205); //n, m <= 100

  vd = {numeric_limits<uint>::max(), list<edata>()};
  vs.push_back(vd);
  vd = {numeric_limits<uint>::max(), list<edata>()};
  vs.push_back(vd);
}

void addBoy(uint skill){
  vdata vd = {skill, list<edata>()};
  edata ed = {vs.size(), 1, 0};
  vs.push_back(vd);
  vs[0].adj.push_back(ed);
}

void addGirl(uint skill){
  vdata vd;
  edata ed;
  
  vd = {skill, list<edata>()};
  ed = {1, 1, 0};             //Edge to sink
  vd.adj.push_back(ed);
  vs.push_back(vd);

  list<edata>::iterator boy = vs[0].adj.begin();
  while( boy != vs[0].adj.end() ){
    uint dist = abs( skill - vs[boy->id].skill );
    printf("Dist(%lu, %lu): %lu.\n", vs.size()-1, boy->id, dist);
    if( dist < 2 ){
      ed = {vs.size() - 1, 1, 0};
      vs[boy->id].adj.push_back(ed);
    }
    boy++;
  }
}

int main(){
  uint m;

  initGraph();
  scanf("%lu", &m);
  while( m-- > 0 ){
    uint s;
    scanf("%lu", &s);
    addBoy(s);
  }
  
  printGraph();

  scanf("%lu", &m);
  while( m-- > 0 ){
    uint s;
    scanf("%lu", &s);
    addGirl(s);
  }

  printGraph();
  
  return 0;
}
