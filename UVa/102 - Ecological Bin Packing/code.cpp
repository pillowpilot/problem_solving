#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

int main(){
  int b1, g1, c1, b2, g2, c2, b3, g3, c3;

  while( cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3 ){
    int ansBGC = (b2+b3) + (g1+g3) + (c1+c2);
    int ansBCG = (b2+b3) + (c1+c3) + (g1+g2);
    int ansGBC = (g2+g3) + (b1+b3) + (c1+c2);
    int ansGCB = (g2+g3) + (c1+c3) + (b1+b2);
    int ansCBG = (c2+c3) + (b1+b3) + (g1+g2);
    int ansCGB = (c2+c3) + (g1+g3) + (b1+b2);

    int ans = ansBGC;
    string s = "BGC";
    if( ansGCB <= ans ){
      ans = ansGCB;
      s = "GCB";
    }
    if( ansGBC <= ans ){
      ans = ansGBC;
      s = "GBC";
    }
    if( ansCGB <= ans ){
      ans = ansCGB;
      s = "CGB";
    }
    if( ansCBG <= ans ){
      ans = ansCBG;
      s = "CBG";
    }
    if( ansBGC <= ans ){
      ans = ansBGC;
      s = "BGC";
    }    
    if( ansBCG <= ans ){
      ans = ansBCG;
      s = "BCG";
    }

    cout << s << " " << ans << "\n";
  }
  return 0;
}

// AC
/*
  There is probably a more elegant solution with vector. 
  Check that the string is the lexicographically smaller.
  Scheme: BT all configurations (3!) in O(1). Given the config figure out the cost. Choose the minimum.
 */
