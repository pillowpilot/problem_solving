#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;

vb bs;

int main(){
  int n, m;
  cin >> n >> m;
  bs = vb(m, false);
  while(n-- > 0){
    int i;
    cin >> i;
    while(i-->0){
      int j;
      cin >> j;
      bs[j-1] = true;
    }
  }

  //  for(bool item: bs)cout << item << endl;
  
  int i = 0;
  while( i < bs.size() && bs[i] == true )i++;
  if( i == bs.size() ) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}

// AC
