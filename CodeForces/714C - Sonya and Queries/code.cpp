#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef map<ull, int> mui;

string ns;

bool matches(ull n, string p){
  ns = to_string(n);

  string delta;
  delta.reserve(50);
  for(int i = 0; i < 20 - ns.size(); i++){
    delta.push_back('0');
  }
  ns.insert(0, delta);

  //cout << ">> " << p << endl;
  //cout << ">> " << s << endl;

  int m = 0;
  for(int i = 0; i < p.size(); i++){
    int d = ns[i] - '0';
    if( p[i] == '0' && d % 2 == 0 )
      m++;
    else if( p[i] == '1' && d % 2 != 0 )
      m++;
  }

  return m == p.size();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  mui set;
  ns.reserve(50);
  
  while( n-- ){
    char op;
    cin >> op;

    if( op != '?' ){
      ull x;
      cin >> x;
      if( op == '+' )
	set[x]++;
      else{
	set[x]--;
	if( set[x] == 0 )
	  set.erase(x);
      }
    }else{
      string s;
      s.reserve(50);
      cin >> s;

      string delta;
      delta.reserve(50);
      for(int i = 0; i < 20 - s.size(); i++){
	delta.push_back('0');
      }
      s.insert(0, delta);

      //cout << s << endl;

      int c = 0;
      auto iter = set.begin();
      while( iter != set.end() ){
	if( matches(iter->first, s) )
	  c += iter->second;
	iter++;
      }

      cout << c << '\n';
    }
      
  }
  
  return 0;
}
