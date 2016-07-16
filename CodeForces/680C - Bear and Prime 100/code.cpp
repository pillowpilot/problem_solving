#include <iostream>
#include <string>

using namespace std;

int p[] = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49, 53};
int n = 20;
int main(){
  ios_base::sync_with_stdio(false);
  
  int t[n];
  for(int i = 0; i < n; i++)
    t[i] = 0;

  int d=0;
  for(int i = 0; i < n && d<2; i++){
    cout << p[i] << endl;
    fflush(stdout);
    string r;
    cin >> r;
    if( r == "yes" ){
      t[i] = 1;
      d++;
    }
  }

  if( d >= 2 )
    cout << "composite" << endl;
  else
    cout << "prime" << endl;

  
  return 0;
}

// AC
