#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int getLenght(int d){
  vi rs;
  rs.reserve(1000);

  int r = 1;
  for(int i=0; i < 1000; i++){
    rs.push_back(r);
    r *= 10;
    r = r % d;
    if( r == 0 )
      return 0;
  }

  int p = rs[rs.size()-1];
  int i = rs.size()-2;
  while( rs[i] != p ){
    i--;
  }
  return rs.size()-2-i + 1;
}

int main(){

  int limit = 1000;
  int ans;
  int ansc = -1;
  for(int i = 2; i <= limit; i++){
    int l = getLenght(i);
    if( ansc < l ){
      ans = i;
      ansc = l;
    }
  }

  cout << ans << ":" << ansc << endl;
  
  return 0;
}

// AC ans=983

/*
  Just analize the division algorithm.
  if remainder == 0, then no repeating digits.
  if we get a repeat remainder, then the "distance" between those two remainders is the length.
  For example, 1/6 : 1 4 4 4 4 4 4 ... distance 1
  For example, 1/7 : 1 3 2 6 4 5 1 ... distance 6
  In general, ... a b c D e f g h i ... D e f g h i ... where all remainders before D do not repeat after D.
 */
