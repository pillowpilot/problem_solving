#include <cstdio>
#include <vector>

using namespace std;

typedef struct {
  bool visited;
  int x, y, id;
} vertex;

bool cmpVertex(const vertex &a, int x, int y){
  return (a.x == x && a.y == y);
}

void addVertex(vector< vertex > &v, int x, int y){
  vertex d;
  d.x = x;
  d.y = y;
  d.id = v.size();
  v.push_back(d);
}

void addEdge(const vector< vertex > &data, vector< vector< bool > > &im, int a, int b, int x, int y){
  vertex A, B;
  vector< vertex >::const_iterator iter;
  iter = data.begin();
  while(iter != data.end()){
    if( cmpVertex( *iter, a, b) ) A = *iter;
    if( cmpVertex( *iter, x, y) ) B = *iter;
    iter++;
  }
  
  im[ A.id ][ B.id ] = true;
  im[ B.id ][ A.id ] = true;
}

bool isValid(const vector< vector< bool > > &m, int x, int y){
  return ( 0 <= x && 0 <= y && x < m.size() && y < m[x].size() );
}

void check(const vector< vertex > &data, vector< vector< bool > > &im, const vector< vector< bool > > &map, int i, int j, int a, int b){
  if( isValid(map, a, b) && map[a][b] ) addEdge(data, im, i, j, a, b);
}

void visitFrom(vector< vertex > &data, const vector< vector< bool > > &im, int vertexId){
  data[vertexId].visited = true;
  for(int i = 0; i < data.size(); i++){
    if(im[vertexId][i] && !data[i].visited){
      visitFrom(data, im, i);
    }
  }
}

int main(){
  char status;
  int m, n, deposits;
  vector< vector< bool > > map, im;
  vector< vertex > data;
  
  map.reserve(100*100);
  im.reserve(100*100);
  data.reserve(100);

  scanf("%d %d", &m, &n);
  while(m != 0){
    //Limpiando estructuras
    deposits = 0;
    data.clear();
    map.resize(m);
    fill(map.begin(), map.end(), vector< bool > (n, false));
    //Leyendo (y memorizando) entrada y creando vertices
    scanf("%*c");
    for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
	scanf("%c", &status);
	if(status == '@'){
	  map[i][j] = true;
	  addVertex(data, i, j);
	}
      }
      scanf("%*c");
    }
    //Dimensionando e inicializando Matriz de Incidencia
    im.resize( data.size() );
    fill(im.begin(), im.end(), vector< bool > (data.size(), false));
    //Cargando Matriz de Incidencia
    for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
	if( map[i][j] ){
	  check(data, im, map, i, j, i - 1, j    );
	  check(data, im, map, i, j, i - 1, j - 1);
	  check(data, im, map, i, j, i    , j - 1);
	  check(data, im, map, i, j, i + 1, j - 1);
	  check(data, im, map, i, j, i + 1, j    );
	  check(data, im, map, i, j, i + 1, j + 1);
	  check(data, im, map, i, j, i    , j + 1);
	  check(data, im, map, i, j, i - 1, j + 1);
	}
      }
    }
    //Contando componentes
    for(int v = 0; v < data.size(); v++){
      if(!data[v].visited){
	deposits++;
	visitFrom(data, im, v);
      }
    }

    /*
    vector< vertex >::const_iterator iter = data.begin();
    while(iter != data.end()){
      printf("[%d](%d, %d) ", iter->id, iter->x, iter->y);
      iter++;
    }
    printf("\n");

    for(int i = 0; i < im.size(); i++){
      for(int j = 0; j < im[i].size(); j++){
	printf("%d", (im[i][j])?1:0 );
      }
      printf("\n");
    }*/

    printf("%d\n", deposits);

    scanf("%d %d", &m, &n);
  }

  return 0;
}
