#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Gperm{
public:
  int countfee(vector <int> x, vector <int> y){
    int gr[50];
    fill(gr, gr+50, 0);
    
    for(int i = 0;i <x.size(); i++){
      gr[ x[i] ]++;
      gr[ y[i] ]++;
    }

    vector<pair<int, int>> g;
    for(int i = 0 ;i < 50; i++){
      g.push_back( make_pair(gr[i], i) );
    }
    sort(g.begin(), g.end());

    bool p[50];
    fill(p, p+50, false);

    int fee = 0;
    for(int i = 0 ;i < g.size(); i++){
      int fee_inc = 0;
      int vert = g[i].second;
      cout << " paintd " << vert << " with " << g[i].first << endl;
      p[ vert ] = true;
      for(int j = 0; j < x.size(); j++){
	if( x[j] == vert && p[ y[j] ] == true ){
	  fee_inc++;
	}else if( y[j] == vert && p[ x[j] ] == true ){
	  fee_inc++;
	}
      }
      cout << " incr " << fee_inc << endl;
      fee *= 2;
      fee += fee_inc;
    }

    return fee;
  }
};

int main(){
  Gperm g;
  cout << g.countfee(vector<int>{0}, vector<int>{1}) << endl;
  cout << g.countfee(vector<int>{0, 1}, vector<int>{1, 2}) << endl;
  cout << g.countfee(vector<int>{4, 7, 7}, vector<int>{7, 4, 4}) << endl;
  cout << g.countfee(vector<int>{0, 0, 1}, vector<int>{1, 2, 2}) << endl;
  cout << g.countfee(vector<int>{7,8,9}, vector<int>{4,5,6}) << endl;
  cout << g.countfee(vector<int>{45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28},
		     vector<int>{45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27}) << endl;
  
  
}
