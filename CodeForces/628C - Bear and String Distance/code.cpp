#include <cstdio>

using namespace std;

int d(char a, char b){
  return (a < b)?b-a:a-b;
}

int main(){
  char s[100099], t[100099];
  int n, k;

  scanf("%d %d %s", &n, &k, s);

  int i = 0;
  while( i < n && k > 0 ){
    char maxc = s[i];
    for(char c = 'a'; c <= 'z'; c++){
      //printf(">> %c vs %c (%d)\n", s[i], c, d(s[i], c));
      if( d(maxc, s[i]) < d(c, s[i]) && k >= d(c, s[i]) )
	maxc = c;
    }
    
    t[i] = maxc;
    k -= d(s[i], maxc);
    i++;
    //printf(">> %c %d\n", maxc, k);
  }
  while( i < n ){
    t[i] = s[i];
    i++;
  }
  t[i] = '\0';

  if( k == 0 ){
    printf("%s\n", t);
  }else{
    printf("-1\n");
  }
  
  return 0;
}

// AC
