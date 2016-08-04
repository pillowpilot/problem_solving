#include <iostream>

using namespace std;

bool isValid(int i, int j){
  return (0<=i && 0<=j && i<3 && j<3);
}

int main(){
  int m[3][3];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j< 3; j++){
      m[i][j] = 1;
    }
  }

  int offr[] = {-1, 0, 0, 0, 1};
  int offc[] = {0, -1, 0, 1, 0};
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j< 3; j++){
      int x;
      cin >> x;
      for(int k = 0; k < x; k++){
	for(int l=0; l < 5; l++){
	  if( isValid(i+offr[l], j+offc[l])){
	    m[i+offr[l]][j+offc[l]] = 1 - m[i+offr[l]][j+offc[l]];
	  }
	}
      }
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j< 3; j++){
      cout << m[i][j];
    }
    cout << '\n';
  }  
  
  return 0;
}

// AC
