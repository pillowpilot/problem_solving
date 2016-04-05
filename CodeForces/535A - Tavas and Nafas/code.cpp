#include <cstdio>
#include <string>
#include <string>

using namespace std;

string f(int i){
  string a[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
		"eighteen", "nineteen"};
  string b[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  if( i < 20 ){
    return a[i];
  }else if(i % 10 == 0){
    return b[i / 10 - 2];
  }else{
    string x = f(i % 10); // Digito Menos Significativo
    i /= 10;
    i *= 10;
    string y = f(i); // Digito Mas Significativo
    return y + "-" + x;
  }
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%s", f(n).data() );

  /*for(int i = 0; i < 100; i++){
    printf("<%s>\n", f(i).data());
  }*/
  return 0;
}
