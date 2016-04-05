#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef vector< ull > vull;

ull maxTask;
int writers;
vull pages;

ull totalSum(){
  ull sum = 0;
  vull::const_iterator iter = pages.begin();
  while( iter != pages.end() ){
    sum += *iter;
    iter++;
  }
  return sum;
}

int assignGreedly(){
  int writersNeeded = 0;

  vull::const_iterator iter = pages.begin();
  while( iter != pages.end() ){
    int sum = 0;
    writersNeeded++;
    printf("To Writer %d:\n", writersNeeded);
    while( iter != pages.end() && sum + *iter <= maxTask ){
      printf("\tBook of %llu pages.\n", *iter);
      sum += *iter;
      iter++;
    }
  }
  
  return writersNeeded;
}

void solve(){
  ull low = 1, high = totalSum();
  while( low <= high ){
    maxTask = low + (high - low)/2;
    printf("[%llu, %llu] (%llu)\n", low, high, maxTask);
    int writersNeeded = assignGreedly();
    if( writersNeeded >= writers ){
      low = maxTask + 1;
    }else{
      high = maxTask;
    }
  }
}

int main(){
  ull cases;
  
  pages.reserve( 550 );
  scanf("%llu", &cases);
  while( cases-- > 0 ){
    int m;

    pages.clear();
    scanf("%d %d", &m, &writers);
    while( m-- > 0 ){
      ull p;
      scanf("%llu", &p);
      pages.push_back( p );
    }

    //Solve
    solve();
  }
}

