#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
typedef vector<int> vi;

int countVocals(const string& s){
  vector<char> v{'a', 'e', 'i', 'o', 'u', 'y'};
  sort(v.begin(), v.end());

  int cv=0;
  for(char c: s){
    if( binary_search(v.begin(), v.end(), c) )
      cv++;
  }
  return cv;
}

int main(){
  int n;
  cin >> n;
  vi p;
  while( n-- ){
    int x; cin >> x;
    p.push_back(x);
  }

  vi preal;
  n = p.size();
  string t;
  getline(cin, t); // ignore a EOL
  while( n-- ){
    string line;
    getline(cin, line);
    //cout << ">>> " << line << endl;
    istringstream iss(line);

    int cv = 0;
    string s;
    while( iss >> s ){
      //cout << ">> " << s << " " << countVocals(s) << endl;
      cv+=countVocals(s);
    }
    preal.push_back(cv);
  }

  /*for(int i: p)
    cout << i << " ";
  cout << endl;

  for(int i: preal)
    cout << i << " ";
    cout << endl;*/

  int i = 0;
  while( i < p.size() && p[i] == preal[i] )
    i++;

  if( i == p.size() )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

// AC
/*
  Every silable is determined by a vocal, so the #separations=#vocals (for all line)
  Check if the real #seperations equals to the problem #separations
  Process the input is anoying
 */
