#include <iostream>

using namespace std;

int seg[] = {6, 2, 5, 5,  4, 5, 6, 3, 7, 6};

int f(int n){
  int c = 0;
  do{
    int a = n % 10;
    c += seg[a];
    n /= 10;
  }while(n>0);

  return c;
}

int main(){
  int a, b;
  unsigned long long c = 0;
  cin >> a >> b;

  for(int i = a; i <= b; i++){
    c += f(i);
  }

  cout << c << endl;
  
  return 0;
}


// AC
