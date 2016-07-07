#include <iostream>

using namespace std;

int main(){
  long long n, m;

  cin >> n >> m;

  // Count digits for each part
  int d1 = 1, d2 = 1;
  for(long long i = 7; i < n; i*=7)
    d1++;
  for(long long i = 7; i < m; i*=7)
    d2++;

  // If has available more digits than 7, then is impossible a unrepeated-digit number
  if( d1+d2 > 7 )
    cout << 0 << endl;
  else{
    int cnt=0;
    // Test then all!
    for(long long i=0; i<n; i++){
      for(long long j=0; j<m; j++){
	int used[7]={0};

	long long a=i, b=j, c=0;
	while( a != 0){ // Build the digits and count then
	  used[a%7]++;
	  a = a/7;
	  c++;
	}
	// If there are unused spaces, then fill then with zeros.
	if( c < d1 ) used[0]+=d1-c;

	c=0;
	while( b != 0){
	  used[b%7]++;
	  b = b/7;
	  c++;
	}
	if(c<d2) used[0]+=d2-c;

	bool isDifferent=true;
	for(int k=0;k<7;k++)
	  if(used[k] > 1){
	    // If there is a digits used more than once, !isDifferent
	    isDifferent=false;
	    break;
	  }

	cnt += isDifferent?1:0;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

// AC
