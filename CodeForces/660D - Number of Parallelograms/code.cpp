#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

bool find(int n, int x[], int y[], ull a, ull b){
  int i = 0;
  while( i < n && x[i] != a && y[i] != b )
    i++;

  return !(i==n);
}

int main(){
  int n, cnt=0;
  scanf("%d", &n);

  int x[n], y[n];

  for(int i = 0; i < n; i++){
    scanf("%d %d", x+i, y+i);
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
	ull ax = x[j] - x[i];
	ull ay = y[j] - y[i];

	ull bx = x[k] - x[i];
	ull by = y[k] - y[i];

	ull cp = ax*by - ay*bx;
	ull a = ax*ax + ay*ay;
	ull b = bx*bx + by*by;

	if( i != j && j != k && i != k && cp*cp == a*b ){
	  ull cx = x[i] + (ax + bx);
	  ull cy = y[i] + (ay + by);

	  int l = 0;
	  while( l < n && x[l] != cx && y[l] != cy )
	    l++;

	  if(l <  n ){
	    cnt++;
	    //cout << i << ' ' << j << ' '<< k << ' ' << l << endl;
	  }
	}
	
      }
    }
  }

  cout << cnt / 32 << endl;
  
  return 0;
}

// WA (Parallelograms not rectangles..!!)
