#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi seq;
vi target;

void push(){
  for( int i = 0; i < seq.size(); i++ ){
    seq[i] += (i % 2 == 0)? +1: -1;
    if( seq[i] == -1 ) seq[i] = seq.size() - 1;
    seq[i] %= seq.size();
  }
}

bool equals(const vi& a, const vi& b){
  if( a.size() != b.size() ) return false;

  vi::const_iterator iterA = a.begin();
  vi::const_iterator iterB = b.begin();
  while( iterA != a.end() && iterB != b.end() && *iterA == *iterB ){
    iterA++;
    iterB++;
  }

  return (iterA == a.end());
}

void print(const vi& v){
  vi::const_iterator iter = v.begin();
  while( iter != v.end() ){
    printf("%d ", *iter);
    iter++;
  }
}

bool solve(){
  bool solvable = false;

  for( int i = 0; i < seq.size() && !solvable; i++ ){
    //print(seq);
    //printf("\n");
    if( equals( seq, target ) ) solvable = true;
    push();
  }

  return solvable;
}

void init(int n){
  seq = vi(n);
  target = vi();
  for( int i = 0 ; i < n; i++ ) seq[i] = i;
}

int main(){
  int n;

  scanf("%d", &n);
  init(n);
  while( n-- > 0 ){
    int a;
    scanf("%d", &a);
    target.push_back(a);
  }

  printf("%s", (solve())?"Yes":"No");

  return 0;
}
