#include <iostream>

using namespace std;

/*
  Geometry problem.
  Notice that the only way to a turn to be dangerous 
  is when you turn left (because the lake is always at your right).
  Then it's an straighfoward use of cross product between your current
  track and the next one.

  Because we transpose the vectors to (0, 0), Cx and Cy are always 0.
  And we only need the sign of the z (check the right-hand rule).
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int cnt = 0;
  int n, a, b, c, d, e, f;
  cin >> n;
  cin >> a >> b;
  cin >> c >> d;

  n-=2;
  while( n-->0 ){
    cin >> e >> f;
    int Ax = c-a, Ay = d-b, Az=0;
    int Bx = e-c, By = f-d, Bz=0;

    int Cx = Ay*Bz - Az*By; // 0
    int Cy = Az*Bx - Ax*Bz; // 0
    int Cz = Ax*By - Ay*Bx; 

    if( Cz > 0 ){
      cnt++;
    }

    a=c; b=d;
    c=e; d=f;
  }

  cout << cnt << endl;
  
  return 0;
}

// AC
