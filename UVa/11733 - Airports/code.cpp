#include <cstdio>
#include <map> 
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int getParent(vector<int> &ps, int i){
  if( ps[i] == i ) return i;
  else{
    int setID = getParent(ps, ps[i]);
    ps[i] = setID;
    return setID;
  }
}

pair<int, int> kruskal(multimap< int, pair< int, int> > &es, int n){
  int i = 0, setA, setB, roadsCost = 0, comp = n;
  vector<int> parents(n);

  vector<int>::iterator iter = parents.begin();
  while(iter!=parents.end()){
    *iter = i++;
    iter++;
  }
  
  multimap< int, pair< int, int > >::const_iterator e = es.begin();
  while( e != es.end() && comp > 1 ){
    setA = getParent( parents, e->second.first );
    setB = getParent( parents, e->second.second);

    if( setA != setB ){ // Si no se crea un ciclo, entonces agregar la arista
      roadsCost += e->first;
      parents[ setA ] = setB;
      comp--;
    }

    e++;
  }
  
  return pair<int, int>(roadsCost, comp);
}

int main(){
  int tests, n, m, a;
  int x, y, z;
  pair<int, size_t> r;
  multimap< int, pair<int, int> > es;

  scanf("%d ", &tests);
  for(int test = 1; test <= tests; test++){
    es.clear();

    scanf("%d %d %d ", &n, &m, &a);
    while(m-- > 0){
      scanf("%d %d %d ", &x, &y, &z);
      x--; y--;
      // Las aristas con peso mayor al costo de un aeropuerto no disminuyen el costo total.
      // El algoritmo es voraz.
      if( z <= a ) es.insert( pair<int, pair<int, int> >(z, pair<int, int>(x, y)) );
    }
    
    r = kruskal(es, n);
    printf("Case #%d: %lu %lu\n", test, r.first + r.second*a, r.second);
  }
  return 0;
}
