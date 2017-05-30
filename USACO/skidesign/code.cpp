/*
  ID: carlos.16
  PROG: skidesign
  LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>

#define rep(i, a, b) for(__typeof(a) i=a; i <= b; i++)

using namespace std;

int n, m = 100;
vector<int> elev;

int evalcost(int i){
  int cost = 0;
  rep(j, 0, n-1){
    if( elev[j] < i )
      cost += (i-elev[j])*(i-elev[j]);
    else if( i + 17 < elev[j] )
      cost += (elev[j]-i-17)*(elev[j]-i-17);
  }
  return cost;
}

int ternary(){
  int low = 0, high = m;
  while( low < high ){
    int mid = (low+high)/2;
    int a = evalcost(mid);
    int b = evalcost(mid+1);
    if( a < b )
      high = mid;
    else 
      low = mid+1;
  }
  return evalcost(low);
}

int bruteforce(){
  int ans = 1e6;
  rep(i, 0, m-17){
    int cost = evalcost(i);
    //cout << cost << endl;
    ans = min(ans, cost);
  }
  return ans;
}

int main(){
  ifstream input("skidesign.in");
  ofstream output("skidesign.out");

  input >> n;
  rep(i, 0, n-1){
    int e;
    input >> e;
    elev.push_back(e);
  }

  int ans;
  //ans = bruteforce();
  //cout << ans << endl;
  
  ans = ternary();
  //cout << ans << endl;
  
  output << ans << endl;
  
  return 0;
}

// AC
/*
  Brute force it backwards. Fix an interval of size 17 and calculate the cost of transform the heights
  into that segment.
  Notice that this is only possible because the elevation range is SMALL (<=100). 
  AC
  Also notice that the function cost(interval) is convex, so the ternary search is possible and this 
  approach is O(N lg M)
  AC
 */
