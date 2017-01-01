#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

const string filename("p059_cipher.txt");

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";
  if( v.size() != 0){
    typename vector<T>::const_iterator iter = begin(v);
    os << *iter;
    iter++;
    while( iter != end(v) ){
      os << ", " << *iter;
      iter++;
    }
  }
  os << "]";
  return os;
}

string readData(ifstream& f){
  stringstream ss;
  char c;
  while( f >> c )
    if(c != ',')
      ss << (char)(c);
    else
      ss << ' ';

  ostringstream oss;
  int a;
  while( ss >> a )
    oss << (char)(a);
  
  return oss.str();
}

string decode(const string msg, const string pass){
  ostringstream oss;
  for(int i = 0; i < msg.size(); i++){
    oss << (char)((int)(msg[i]) ^ (int)(pass[i%3]));
  }
  return oss.str();
}

int main(){
  ifstream f(filename);
  if( f.is_open() ){
    string data;
    data = readData(f);
    //cout << data << endl;

    vector<string> dic{"the", "be", "to", "of", "and"};
    //vector<string> dic{"beginning"};

    string msg;
    int c = 0;
    for(char i = 'a'; i <= 'z'; i++){
      for(char j = 'a'; j <= 'z'; j++){
	for(char k = 'a'; k <= 'z'; k++){
	  string pass("   ");
	  pass[0] = i;
	  pass[1] = j;
	  pass[2] = k;

	  string temp;
	  temp = decode(data, pass);

	  int l = 0;
	  while( temp.find(dic[l]) != string::npos )
	    l++;

	  if( l == dic.size() ){
	    c++;
	    msg = temp;
	    //cout << temp << endl;
	  }
	} 	
      }      
    }

    if( c == 1 ){
      cout << msg << endl;
      int sum = 0;
      for(char c: msg)
	sum += (int)c;
      cout << sum << endl;
    }
  }
  return 0;
}
  
// ans = 107359
/*
  26^3 is approx 17e3 and the msg is not so large (is really short in fact), so brute force.
  dic is composed with the 5 most popular words in english
 */
