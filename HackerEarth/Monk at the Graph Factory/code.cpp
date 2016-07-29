#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int s = 0;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    s+=d;
  }

  if( s == (n-1)*2 )
    cout << "Yes" << endl;
  else
    cout << "No" << endl; // Cycles or forest
  return 0;
}

// AC
