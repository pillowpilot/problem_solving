#include <cstdio>
#include <vector>

#define N 10101

using namespace std;

struct Data{
  int a2, a5, a10, a2a, a5a, a10a, data;
  Data(){
    a2 = a5 = a10 = a2a = a5a = a10a = data = 0;
  }
};

vector<Data> v;

void precalc(){
  v[2].a2 = v[2].a2a = 1;
  v[5].a5 = v[5].a5a = 1;
  v[10].a10 = v[10].a10a = 1;
  for( int i = 1; i < N; i++ ){
    if( i % 2 == 0 && v[i].a2 == 0){
      v[i] = v[i/2] + 1;
    }
    if( i % 5 == 0 && v[i].a5 == 0 ){
      v[i] = v[i/5] + 1;
    }
    if( i % 10 == 0 && v[i].a10 == 0 ){
      v[i] = v[i/10] + 1;
    }
  }
  for( int i = 1; i < N; i++ ){
    v[i].a2a  = v[i-1].a2a + v[i].a2;
    v[i].a5a  = v[i-1].a5a + v[i].a5;
    v[i].a10a = v[i-1].a10a + v[i].a10;
    v[i].data = v[i].a2a + v[i].a5a + v[i].a10a;
  }
}

int main(){

  v(N);
  precalc();
  
  
  return 0;
}

// Unfinished
