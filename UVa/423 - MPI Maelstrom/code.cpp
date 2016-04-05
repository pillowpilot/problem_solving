#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi matrix;
vi distances;
vi mark;

void dijkstra(){
  ios_base::sync_with_stdio(0);
  
  distances[0] = 0;
  mark[0] = 1;

  for( int i = 0; i < distances.size(); i++ ){
    int v = 0, d = numeric_limits<int>::max();
    for( int j = 0; j < distances.size(); j++ ){
      if( mark[j] == 0 && distances[j] < d ){
	v = j;
	d = distances[j];
      }
    }
    
    for( int j = 0; j < matrix[v].size(); j++ ){
      if( matrix[v][j] != numeric_limits<int>::max() && distances[j] > distances[v] + matrix[v][j] ){
	distances[j] = distances[v] + matrix[v][j];
      }
    }

    mark[v] = 1;
  }
}

int main(){
  int n;

  cin >> n;
  matrix = vvi(n, vi(n, numeric_limits<int>::max()));
  distances = vi(n, numeric_limits<int>::max());
  mark = vi(n, 0);

  for( int i = 1; i < n; i++ ){
    for( int j = 0; j < i; j++ ){
      string s;
      cin >> s;
      if( s != "x" ){
	int cost;
	cost = atoi(s.data());
	matrix[i][j] = cost;
	matrix[j][i] = cost;
      }
    }
  }
  for( int i = 0; i < n; i++ ){
    matrix[i][i] = 0;
  }

  dijkstra();

  int c = distances[0];
  for( int i = 0; i < distances.size(); i++ ){
    if( c < distances[i] ){
      c = distances[i];
    }
  }

  cout << c << endl;

  return 0;
}

// AC
