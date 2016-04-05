#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi heights;

void init(){
  heights.reserve(50505);
}


int main(){
  int n, q;
  
  init();
  scanf("%d", &n);
  while( n-- > 0 ){
    int h;
    scanf("%d", &h);
    heights.push_back(h);
  }

  scanf("%d", &q);
  while( q-- > 0 ){
    vi::const_iterator low, hi;
    int query;

    scanf("%d", &query);
    low = lower_bound(heights.begin(), heights.end(), query);
    hi = upper_bound(heights.begin(), heights.end(), query);

    if( low == heights.begin() ){
      printf("X ");
    }else{
      printf("%d ", *prev(low));
    }
    if( hi == heights.end() ){
      printf("X");
    }else{
      printf("%d", *hi);
    }
    printf("\n");
  }
  return 0;
}
