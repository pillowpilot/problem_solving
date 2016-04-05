#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

void loadMapping(map<char, char> &mapping){
  // Se asume que los caracteres mas a la derecha no aparecen en las cadenas
  // Por lo tanto, '=', '/', ''' y '/' no tienen reemplazo.
  string x = "QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.`1234567890- ";
  string y = "WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./1234567890-= ";
  
  //printf("%lu %lu\n", x.length(), y.length());

  for(int i = 0; i < x.size(); i++){
    mapping[y[i]] = x[i];
  }
}

void correct(const string &original, string &corrected, const map<char, char> &mapping){
  for(int i = 0; i < original.length(); i++){
    map<char, char>::const_iterator f = mapping.find(original[i]);
    if(f != mapping.end()){
      corrected[i] = f->second;
    }
  }
}

int main(){
  string original, corrected;
  map<char, char> mapping;
  
  loadMapping(mapping);

  /*map<char, char>::const_iterator iter = mapping.begin();
  while(iter != mapping.end()){
    printf("<%c> : <%c>\n", iter->first, iter->second);
    iter++;
  }
  */
  
  do{
    getline(cin, original);
    if(original != ""){
      corrected = original; //Se reserva todo el espacio necesario
      correct(original, corrected, mapping);
      printf("%s\n", corrected.c_str());
    }
  }while(original != "");
  return 0;
}
