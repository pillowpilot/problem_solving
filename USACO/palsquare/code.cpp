/*
  ID: carlos.16
  PROG: palsquare
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

string toBase(int n, int b){
  string ans;

  do{
    int x = n%b;
    char c;
    if( x >= 10 ){
      c = 'A' + (x - 10);
    }else{
      c = x + '0';
    }
    ans.push_back(c);
    n /= b;
  }while(n!=0);

  reverse(all(ans));
  return ans;
}

bool isPalim(const string s){
  string sr(s);
  reverse(all(sr));
  return sr == s;
}

int main(){
  ifstream input("palsquare.in");
  ofstream output("palsquare.out");
  
  /*rep(i, 0, 30){
    cout << i << " = " << toBase(i, 16) << endl;
  }*/

  int b;
  input >> b;

  rep(i, 1, 300){
    string n = toBase(i, b);
    string nn = toBase(i*i, b);
    //cout << ">> " <<  n << ' ' << nn << endl;
    if( isPalim(nn) ){
      //cout << n << ' ' << nn << endl;
      output << n << ' ' << nn << endl;
    }
  }
  return 0;
}

// AC
