#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef struct{
  int imID;
  bool visited;
} vertex;

void printMatrix(const vector< vector<int> > &m){
  vector< vector<int> >::const_iterator iter = m.begin();
  while(iter != m.end()){
    vector<int>::const_iterator iiter = iter->begin();
    while(iiter != iter->end()){
      printf("%3d ", *iiter);
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

void warshall(vector< vector<int> > &m){
  bool convergence = false;
  while(!convergence){
    convergence = true;
    for(int i = 0; i < m.size(); i++){
      for(int j = 0; j < m[i].size(); j++){
	for(int k = 0; k < m.size(); k++){
	  if( m[i][j] == 0 && m[i][k] == 1 && m[k][j] == 1){
	    m[i][j] = 1;
	    convergence = false;
	  }
	}
      }
    }
  }
}

void visit(const vector< vector<int> > &im, vector<bool> &visited, int s){
  for(int n = 0; n < im[s].size(); n++){
    if(im[s][n] == 1 && im[n][s] == 1){
      visited[n] = true;
    }
  }
}

int countGroups(const vector< vector<int> > &im, vector<bool> &visited){
  int groups = 0;
  int source = 0;
  while(source < visited.size()){
    if(visited[source] == false){
      groups++;
      visit(im, visited, source);
      visited[source] = true;
    }
    source++;
  }
  return groups;
}

int main(){
  int p, t, e;
  char a[21], b[21];
  string c, d;
  map<string, vertex> names;
  vector<bool> visited;
  vector< vector<int> > im;
  
  scanf("%d %d ", &p, &t);
  while(p != 0){
    e = 0;
    names.clear();
    im.resize(p);
    visited.resize(p);
    fill(im.begin(), im.end(), vector<int>(p, 0));
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < im.size(); i++) im[i][i] = 1; //Everyone trust himself/herself
    
    while(p-- > 0){
      scanf("%20[^,], %20[^\n]\n", a, b);
      c = string(a) + ", " + string(b);
      names[c] = {e++, false};
      //printf("Leido: %s\n", c.data());
    }

    int x, y;
    while(t-- > 0){
      scanf("%20[^,], %20[^\n]\n", a, b);
      c = string(a) + ", " + string(b);
      x = names[c].imID;
      
      scanf("%20[^,], %20[^\n]\n", a, b);
      d = string(a) + ", " + string(b);
      y = names[d].imID;

      //printf("Relacion entre %s y %s\n", c.data(), d.data());
      im[x][y] = 1;
    }

    warshall(im);
    //printMatrix(im);

    int groups = countGroups(im, visited);

    //printf("Encontrados: ");
    printf("%d\n", groups);

    scanf("%d %d ", &p, &t);
  }
  return 0;
}
