#include <cstdio>
#include <map>
#include <vector>
#include <list>
#include <limits>

using namespace std;

typedef unsigned int uint;
typedef vector<uint> vu;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef map<uint, uint> muu;

muu mapper;
vvb mi;
vu dist;

void bfs(uint s){
  list<uint> q;
  vb visited(35, false);
  dist = vu(35, numeric_limits<uint>::max());
  
  q.push_back( s );
  visited[s] = true;
  dist[s] = 0;
  while( !q.empty() ){
    uint t = q.front();
    q.pop_front();
    vb::const_iterator iter = mi[t].begin();
    while( iter != mi[t].end() ){
      if( mi[t][*iter] == true && visited[*iter] == false ){
	visited[*iter] = true;
	dist[*iter] = dist[t] + 1;
	q.push_back( *iter );
      }
      iter++;
    }
  }
}

uint count(uint depth){
  vu::const_iterator iter = dist.begin();
  while( iter != dist.end() ){
    printf("%lu con distancia %u\n", iter - dist.begin(), *iter);
    iter++;
  }
}

void print(){
  uint n = mapper.size();
  vvb::const_iterator iter = mi.begin();
  while( iter != mi.end() && iter - mi.begin() < n ){
    printf("%ld: ", iter - mi.begin() );
    vb::const_iterator iiter = iter->begin();
    while( iiter != iter->end() ){
      if( *iiter == true ){
	printf("%ld ", iiter - iter->begin());
      }
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

int main(){
  uint ns;
  scanf("%u", &ns);
  while( ns != 0 ){
    mi = vvb(35, vb(35, false));
    mapper.clear();
    dist = vu(35, numeric_limits<uint>::max());
    uint a, b, nodes = 0;
    while( ns-- > 0 ){
      // Leyendo aristas
      scanf("%u %u", &a, &b);
      if( mapper.find(a) == mapper.end() ) mapper[a] = nodes++;
      if( mapper.find(b) == mapper.end() ) mapper[b] = nodes++;
      mi[mapper[a]][mapper[b]] = mi[mapper[b]][mapper[a]] = true;
    }
    print();
    scanf("%u %u", &a, &b);
    while( !(a == 0 && b == 0) ){
      bfs( mapper[a] );
      count(b);
      scanf("%u %u", &a, &b);
    }
    scanf("%u", &ns);
  }
  return 0;
}
