#include <cstdio>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> v3i;
typedef vector<v3i> v4i;

vvi forbiddents;

struct par{
  vi point;
  int distance;
  par(vi point, int distance):point(point), distance(distance){}
  void shiftUp(int index){
    point[index] = (point[index] == 9)?0:point[index]+1;
  }
  void shiftDown(int index){
    point[index] = (point[index] == 0)?9:point[index]-1;
  }
  bool operator<(const par& a) const{
    return distance > a.distance;
  }
  bool operator!=(const par& a) const{
    return point != a.point;
  }
};

typedef priority_queue<par> pq;

int dijstra(vi start, vi target){
  v4i distances = v4i(10, v3i(10, vvi(10, vi(10, numeric_limits<int>::max()))));
  v4i marks     = v4i(10, v3i(10, vvi(10, vi(10, 0))));
  pq q;

  distances[start[0]][start[1]][start[2]][start[3]] = 0;
  marks    [start[0]][start[1]][start[2]][start[3]] = 1;
  q.push( par(start, 0) );
  while( q.top() != par(target, 0) ){
    par p = q.top();
    q.pop();
    marks[p.point[0]][p.point[1]][p.point[2]][p.point[3]] = 1;
    
    for( int i = 0; i < 4; i++ ){
      par n = p;
      n.distance++;
      n.shiftUp(i);

      if( marks[n.point[0]][n.point[1]][n.point[2]][n.point[3]] == 0 ){
	q.push(n);
	if( distances[n.point[0]][n.point[1]][n.point[2]][n.point[3]] > p.distance + 1 ){
	  distances[n.point[0]][n.point[1]][n.point[2]][n.point[3]] = p.distance + 1;
	}
      }
      
      n.shiftDown(i);
      n.shiftDown(i);
      
      if( marks[n.point[0]][n.point[1]][n.point[2]][n.point[3]] == 0 ){
	q.push(n);
	if( distances[n.point[0]][n.point[1]][n.point[2]][n.point[3]] > p.distance + 1 ){
	  distances[n.point[0]][n.point[1]][n.point[2]][n.point[3]] = p.distance + 1;
	}
      }
    }
  }

  return distances[target[0]][target[1]][target[2]][target[3]];
  
}

void readConfig(vi&);
int main(){
  int css;

  scanf("%d ", &css);
  while( css-- > 0 ){
    int n;
    vi target, start;

    forbiddents = vvi();
    forbiddents.reserve(10555);

    readConfig(start);
    readConfig(target);
    scanf("%d ", &n);
    while( n-- > 0 ){
      vi forbi;
      readConfig(forbi);
      forbiddents.push_back(forbi);
    }

    int r = dijstra(start, target);
    printf("%d\n", r);
  }
  return 0;
}

void readConfig(vi& v){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  v = vi();
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
}
