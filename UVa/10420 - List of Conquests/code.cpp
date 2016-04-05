#include <cstdio>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> msi;

msi data;
msi memo;

int main(){
  int n;

  data = msi();
  memo = msi();

  while( scanf("%d ", &n) == 1 ){
    data.clear();
    memo.clear();
    
    while( n-- > 0 ){
      char c[81];
      char l[81];
      scanf("%s ", c);
      scanf("%[^\n] ", l);

      string country(c), lover(l);
      // printf(">>%s<<\n>>%s<<\n", country.data(), lover.data());
      
      if( memo.find( lover ) == memo.end() ){
	msi::iterator iter = data.find( country );
	
	if( iter != data.end() ) iter->second++;
	else data[country] = 1;
	
	memo[lover] = 1;
      }
    }

    msi::const_iterator iter = data.begin();
    while( iter != data.end() ){
      printf("%s %d\n", (iter->first).data(), iter->second);
      iter++;
    }
  }
  return 0;
}

// AC
