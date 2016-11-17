#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> vll;
typedef vector<vll> vvll;

vvll triangle;
vvll memo;

void readFile(const string& filename){
  ifstream file(filename);
  if( file.is_open() ){

    triangle.resize(15);
    for(int i = 0; i < 15; i++){
      vll& v = triangle[i];
      for(int j = 0; j < i+1; j++){
	int a;
	file >> a;
	v.push_back(a);
      }
    }
    
    file.close();
  }
}

void printTriangle(){
  for(int i = 0; i < triangle.size(); i++){
    for(int j = 0; j < triangle[i].size(); j++){
      cout << triangle[i][j] << ' ';
    }
    cout << endl;
  }
}

ll dp(int row, int column){
  assert( 0 <= row); assert( 0 <= column);
  assert( row < memo.size() ); assert( column < memo[row].size() );
  
  if( memo[row][column] != -1 ) return memo[row][column];
  
  if( row == triangle.size() - 1){
    return triangle[row][column];
  }else{
    ll a = dp(row + 1, column);
    ll b = dp(row + 1, column + 1);
    ll ans = max(a, b) + triangle[row][column];
    memo[row][column] = ans;
    return ans;
  }
}

int main(){
  const string filename = "input";
  readFile(filename);
  printTriangle();

  memo.resize( triangle.size() );
  fill(begin(memo), end(memo), vll(triangle.size(), -1));

  ll ans = dp(0, 0);

  cout << ans << endl;
  
  return 0;
}

// AC ans = 1074

/*
  simple dp
  decision: shall I go to [row+1, col] or [row+1, col+1].
 */
