#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string a, d, b, l;

  cin >> l;

  int i = 0;
  while( l[i] != '.' ){
    a.push_back(l[i]);
    i++;
  }

  i++;
  while( l[i] != 'e' ){
    d.push_back(l[i]);
    i++;
  }

  i++;
  while( i < l.size() ){
    b.push_back(l[i]);
    i++;
  }

  //cout << ">" << a << endl;
  //cout << ">" << d << endl;
  //cout << ">" << b << endl;

  if( stoi(a) == 0 ){ // Then b=0
    if( d.size() == 1 && d[0] == '0' )
      cout << 0 << '\n';
    else{
      cout << 0 << '.' << d << '\n';
    }
  }else{

    for(int i = 0; i < 111; i++){
      d.push_back('0');
    }

    int bi = stoi(b);
    for(int i = 0; i < bi; i++){
      a.push_back( d[i] );
    }

    i = 0;
    while( i < a.size() && a[i] == '0' )
      i++;
    if( i == a.size() ){
      cout << '0';
    }else{
      while( i < a.size() )
	cout << a[i++];
    }

    if( d[bi] != '0' ){
      cout << '.' << d[bi];
    
      i = bi+1;
      while( d[i] != '0' )
	cout << d[i++];
    }
    cout << '\n';
  }
  
  return 0;
}
