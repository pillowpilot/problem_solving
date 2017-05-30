/*
  ID: carlos.16
  PROG: dualpal
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
    if( x >= 10 )
      c = 'A' + (x-10);
    else
      c = '0' + x;
    ans.push_back(c);
    n /= b;
  }while(n!=0);

  reverse(all(ans));
  return ans;
}

bool isPalim(const string& s){
  string sr(s);
  reverse(all(sr));
  return sr == s;
}

bool isAns(int n){
  int c = 0;
  rep(i, 2, 10){
    string ni = toBase(n, i);
    if( isPalim(ni) )
      c++;
  }
  return c >= 2;
}

int main(){
  ifstream input("dualpal.in");
  ofstream output("dualpal.out");

  int n, s;
  input >> n >> s;

  int a = s+1;
  while( n ){
    if( isAns(a) ){
      //cout << a << endl;
      output << a << endl;
      n--;
    }
    a++;
  }
  return 0;
}

// AC
