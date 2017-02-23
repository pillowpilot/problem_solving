#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;

bool isConstructible(const string& s, const string& t){
  vi counters('z'-'a'+1);
  for(char c: s)
    counters[c-'a']++;
  for(char c: t)
    counters[c-'a']--;

  int i = 0;
  while( i < counters.size() && counters[i] >= 0 )
    i++;

  return i == counters.size();
}

bool isPermutation(const string& s, const string& t){
  vi counters('z'-'a'+1);
  for(char c: s)
    counters[c-'a']++;
  for(char c: t)
    counters[c-'a']--;

  int i = 0;
  while( i < counters.size() && counters[i] == 0 )
    i++;

  return i == counters.size();
}

bool isSubsequence(const string& s, const string& t){
  int i, j;
  i = j = 0;
  while( i < s.size() && j < t.size() ){
    if( s[i] == t[j] )
      i++, j++;
    else
    i++;
  }
  
  return j == t.size();
}

int main(){
  string s, t;
  cin >> s >> t;
  if( isConstructible(s, t) ){
    if( isPermutation(s, t) )
      cout << "array" << endl;
    else if( isSubsequence(s, t) )
      cout << "automaton" << endl;
    else
      cout << "both" << endl;
  }else
    cout << "need tree" << endl;
  
  return 0;
}

// AC
/*
  Same as code.cpp but better complexity O(|s|+|t|+|alphabet|)
  check t isSubsequence of s in linear time with two pointers
  
 */
