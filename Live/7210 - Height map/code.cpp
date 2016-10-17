#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

template <typename P, typename Q>
ostream& operator<<(ostream& os, const pair<P, Q>& p){
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";
  if( v.size() != 0 ){
    typename vector<T>::const_iterator iter = begin(v);
    os << *iter;
    iter++;
    while( iter != end(v) ){
      os << ", " << *iter;
      iter++;
    }
  }
  return os << "]";
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& m){
  for(int i = 0; i < m.size(); i++){
    for(int j = 0; j < m[i].size(); j++)
      os << m[i][j] << ' ';
    if( i != m.size() - 1) os << endl;
  }
  return os;
}

vvll matrix;

ll lateral(){
    ll faces = 0;
    vector<pair<ll, ll>> blocks;
    blocks.reserve(matrix[0].size());
    for(int i = 1; i < matrix.size()-1; i++){
      blocks.clear();
      
      for(int j = 1; j < matrix[0].size()-1; j++){
	ll x = matrix[i-1][j];
	ll y = matrix[i][j];

	if( x < y )
	  blocks.push_back( make_pair(x, y) );
	else
	  blocks.push_back( make_pair(-1, -1) );

      }
      //cout << blocks << endl;
      

      ll lb, ub, coplanarFaces = 0;
      lb = ub = -1;
      for(const auto& p: blocks){
	ll x = p.first;
	ll y = p.second;

	if( x < y ){ // isblock
	  if( lb != -1 ){ // building
	    if( !(y < lb || ub < x) ){ // continuation
	      lb = x; ub = y;
	    }else{
	      lb = x; ub = y; coplanarFaces++;
	    }
	  }else{
	    lb = x; ub = y; coplanarFaces++;
	  }
	}else{ // is not block
	  if( lb != -1 ){ // building
	    lb = x; ub = y;
	  }
	}
      }
      //cout << ">> " << coplanarFaces << endl;
      faces += coplanarFaces;
    }
    return faces;
}

inline void rotate(){
  int r = matrix.size(), c = matrix[0].size();
  vvll rotated(c);
  fill(begin(rotated), end(rotated), vll(r));

  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix[i].size(); j++){
      rotated[ c - j - 1 ][i] = matrix[i][j];
    }
  }
  matrix = rotated;
}

inline bool isValid(const vvll& v, int x, int y){
  return 0 <= x && 0 <= y && x < v.size() && y < v[x].size();
}

void ffhelper(vvll& v, int x, int y, int id){
  int of[] = {1, 0, -1, 0, 1, -1, 0};
  v[x][y] *= -1;
  for(int i = 0; i < 4; i++){
    int a = x+of[i], b = y+of[i+1];
    if( isValid(v, a, b) && v[a][b] == id ){
      ffhelper(v, a, b, id);
    }
  }
}
int floodfill(){
  auto v = matrix;

  int comp = 0;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      if( v[i][j] > 0 ){
	comp++;
	ffhelper(v, i, j, v[i][j]);
      }
    }
  }
  return comp;
}


int main(){
  int r, c;
  while( cin >> r >> c ){
    matrix.clear();
    matrix.resize(r+2);
    fill(begin(matrix), end(matrix), vll(c+2));

    for(int i = 1; i <= r; i++){
      for(int j = 1; j <= c; j++){
	ll h;
	cin >> h;
	matrix[i][j] = h;
      }
    }

    cout << matrix << endl;

    int faces = 1; // down;
    faces += floodfill(); // up;

    for(int i = 0; i < 4; i++){
      faces += lateral();
      rotate();
    }

    cout << faces << endl;

  }
  return 0;
}
