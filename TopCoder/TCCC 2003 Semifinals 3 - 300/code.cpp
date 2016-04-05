#include <iostream>
#include <vector>

using namespace std;

class ZigZag{
public:
  int longestZigZag(vector<int> sequence){
    int maxLen = 1;
    vector<int> lengths = vector<int>(sequence.size(), 1);
    vector<bool> marks = vector<bool>(sequence.size(), false);
    
    for( int i = 1; i < sequence.size(); i++ ){
      for( int j = i - 1; j >= 0; j-- ){
	if( j > 0 ){
	  if( marks[j] == true  && sequence[i] > sequence[j] && lengths[j] + 1 > lengths[i] ){
	    marks[i] = false;
	    lengths[i] = lengths[j] + 1;
	  }
	  if( marks[j] == false && sequence[i] < sequence[j] && lengths[j] + 1 > lengths[i] ){
	    marks[i] = true;
	    lengths[i] = lengths[j] + 1;
	  }
	}else{
	  if( lengths[j] + 1 > lengths[i] ) lengths[i] = lengths[j] + 1;
	}
      }
    }

    for( int i = 0; i < lengths.size(); i++ ) maxLen = (maxLen < lengths[i])?lengths[i]:maxLen;

    return maxLen;
  }
};

int main(){
  ZigZag a;

  cout << a.longestZigZag({1, 7, 4, 9, 2, 5}) << endl; //6
  cout << a.longestZigZag({1, 17, 5, 10, 13, 15, 10, 5, 16, 8}) << endl; //7
  cout << a.longestZigZag({44}) << endl; //1
  cout << a.longestZigZag({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl; //2
  return 0;
}
