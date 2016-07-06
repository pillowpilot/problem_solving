#include <iostream>
#include <string>

using namespace std;

int main(){
  int n, days;

  cin >> n >> days;

  string sch[days];
  for(int i = 0; i < days; i++){
    cin >> sch[i];
  }

  int wins[days] = {0};
  for(int i = 0; i < days; i++){

    int sum = 0;
    for(int j = 0; j < n; j++){
      sum += (sch[i][j] == '1')?1:0;
    }

    if( sum != n )
      wins[i] = 1;
    
  }

  for(int i = 1; i < days; i++){
    if( wins[i] == 1 )
      wins[i] = wins[i-1] + 1;
  }

  int max = 0;
  for(int i = 0; i < days; i++){
    if( wins[i] > max )
      max = wins[i];
  }

  cout << max << endl;
  return 0;
}

// AC
