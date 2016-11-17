#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi grid;

void readFile(const string& filename){
  ifstream file;
  file.open(filename);

  grid.resize(20);
  for(int i = 0; i < 20; i++){
    vi& line = grid[i];
    for(int j = 0; j < 20; j++){
      int a;
      file >> a;
      line.push_back(a);
    }
  }

  file.close();
}

int main(){
  const string filename = "input";
  readFile(filename);

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      cout << setw(2) << grid[i][j] << ' ';
    }
    cout << endl;
  }

  ull maxp = 0, p, a, b, c, d;
  for(int i = 0; i < 20 - 3; i++){
    for(int j = 0; j < 20 - 3; j++){
      // diagonal to the right
      a = grid[i+0][j+0];
      b = grid[i+1][j+1];
      c = grid[i+2][j+2];
      d = grid[i+3][j+3];

      p = a*b*c*d;
      maxp = max(maxp, p);

      // horizontal
      a = grid[i+0][j+0];
      b = grid[i+0][j+1];
      c = grid[i+0][j+2];
      d = grid[i+0][j+3];

      p = a*b*c*d;
      maxp = max(maxp, p);

      // vertical
      a = grid[i+0][j+0];
      b = grid[i+1][j+0];
      c = grid[i+2][j+0];
      d = grid[i+3][j+0];

      p = a*b*c*d;
      maxp = max(maxp, p);
    }
  }

  // diagonal to the left
  for(int i = 0; i < 20-3; i++){
    for(int j = 3; j < 20; j++){
      a = grid[i+0][j-0];
      b = grid[i+1][j-1];
      c = grid[i+2][j-2];
      d = grid[i+3][j-3];

      p = a*b*c*d;
      maxp = max(maxp, p);
    }
  }

  cout << maxp << endl;
  
  return 0;
}

// AC ans = 70600674
