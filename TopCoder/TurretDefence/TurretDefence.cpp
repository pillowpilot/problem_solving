#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;

class TurretDefense{
public:
  int firstMiss(vi xs, vi ys, vi times){
    int cx, cy, t;
    cx = cy = t = 0;

    for(int i = 0; i < xs.size(); i++){
      t += abs(cx-xs[i]) + abs(cy-ys[i]);
      cx = xs[i];
      cy = ys[i];

      if(times[i] < t)
	return i;
      else
	t = times[i];
    }

    return -1;
  }
};

int main(){
  TurretDefense t;
  cout << t.firstMiss({3, 5, 6}, {7, 5, 6}, {11, 15, 16}) << endl;
  cout << t.firstMiss({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32}) << endl;
  cout << t.firstMiss({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,31}) << endl;
  
  return 0;
}

// AC
