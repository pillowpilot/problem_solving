#include <cstdio>
#include <vector>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi movesPath;
int a, b; // Current position
int x, y; // Destination

void convert(char c, int& n){
  c = tolower(c);
  n = c - 'a' + 1;
}

double distance(const pair<int, int>& a, const pair<int, int>& b){
  return sqrt(pow( a.first - b.first , 2) + pow( a.second - b.second, 2));
}

void printMove(int m){
  string s;

  switch(m){
  case 0:
    s = "LD";
    break;
  case 1:
    s = "L";
    break;
  case 2:
    s = "LU";
    break;
  case 3:
    s = "U";
    break;
  case 4:
    s = "RU";;
    break;
  case 5:
    s = "R";
    break;
  case 6:
    s = "RD";
    break;
  case 7:
    s = "D";
    break;
  default:
    s = "--";
    break;
  }
  printf("%s", s.data());
}

void solve(){
  int movesCount = 0;
  int offset[] = {-1, -1, -1, 0, +1, +1, +1, 0, -1, -1, -1};

  while( !( a == x && b == y) ){
    // Found the move to the closest point to the TARGET
    double md = 6464; // Minimum distance
    int move = 0, mm;
    while( move < 8 ){
      // No need to check positions, infinite board = R^2
      int m = a + offset[move], n = b + offset[move + 2];
      double d = distance( make_pair(x, y), make_pair(m, n) );
      if( d < md ){
	md = d;
	mm = move;
      }
      move++;
    }

    // Record the move and make it
    movesCount++;
    movesPath.push_back( mm );
    a += offset[mm];
    b += offset[mm + 2];
  }

  // Report the solution
  printf("%d\n", movesCount);
  for(int move: movesPath){
    printMove(move);
    printf("\n");
  }
}

void init(){
  movesPath.reserve(64);  
}

int main(){
  char c1, c2;
  
  scanf("%c%d %c%d", &c1, &b, &c2, &y);
  
  convert(c1, a);
  convert(c2, x);
  
  init();
  solve();

  return 0;
}
