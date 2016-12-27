#include <iostream>

using namespace std;

void f(){
  int n = 100000;

  cout << n+1 << '\n';
  while( n-- )
    cout << "+ " << n << '\n';

  cout << "? " << "101010";
}

void g(){
  int n = 5000;

  cout << 100000 << '\n';
  while( n-- )
    cout << "+ " << n << '\n';

  for(int i = 0; i <  100000; i++)
    cout << "? " << 1010 << '\n';

}

int main(){
  g();
}
