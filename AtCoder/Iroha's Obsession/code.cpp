#include <iostream>

using namespace std;

int dis[10];

bool f(int s){
  while( s != 0 && dis[s%10]==0 )
    s/=10;

  return s==0;
}

int main(){
  int n, k;
  dis[10]={0};
  cin >> n >> k;
  while(k-->0){
    int a;
    cin>>a;
    dis[a]=1;
  }
  int sol = n;
  while(!f(sol)){
    //cout << sol << endl;
    sol++;
  }

  cout << sol << endl;
  return 0;
}

// AC
