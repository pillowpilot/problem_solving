#include <cstdio>
#include <vector>

using namespace std;

int main(){
  vector<int> vi;
  int n;

  scanf("%d", &n);
  while( n-- > 0 ){
    int a;
    scanf("%d", &a);
    vi.push_back(a);
  }

  vector<int>::const_iterator iter = vi.begin();
  while( iter != vi.end() ){
    int position = 1;

    vector<int>::const_iterator iiter = vi.begin();
    while( iiter != vi.end() ){
      if( *iiter > *iter ) position++;
      iiter++;
    }

    printf("%d ", position);

    iter++;
  }

  return 0;
}
