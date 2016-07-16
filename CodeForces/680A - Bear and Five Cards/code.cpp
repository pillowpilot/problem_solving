#include <iostream>

using namespace std;

int main(){
  int t[5];
  int s=0;
  
  for(int i = 0; i < 5; i++){
    cin >> t[i];
    s += t[i];
  }

  int ms=s;
  for(int i = 0; i < 5; i++){
    int cti = 1;
    for(int j = i+1; j < 5; j++){
      if( t[j] == t[i] )
	cti++;
    }
    if( (cti==2 || cti==3) && ms > s - t[i]*cti )
      ms=s-t[i]*cti;
    
  }

  cout << ms << endl;

   
  return 0;
}

// AC
