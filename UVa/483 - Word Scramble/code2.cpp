#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void reverseWord(string &word){
  char t;
  string::iterator iterA = word.begin();
  string::iterator iterB = word.end() - 1;
  
  while(iterA < iterB){
    t = *iterA;
    *iterA = *iterB;
    *iterB = t;
    iterA++;
    iterB--;
  }
}

int main(){
  char c;
  stringstream ss;
  string line, word;
  
  while(getline(cin, line)){
    ss.clear(); //Resets flags (EOF flag enables when completely reads the first line)
    ss.str( line );
    /*
      Al parecer aparecen secuencias de espacios. Por lo tanto, 
      ss >> word;
      cout << word << " ";
      conduce a Presentation Error.
     */
    while(ss.read(&c, 1)){ 
      if( c != ' ' ){
	ss.seekg(-1, ios_base::cur);
	ss >> word;
	reverseWord(word);
	cout << word;
      }else{
	cout << c;
      }
    }
    cout << endl;
  }
  return 0;
}
