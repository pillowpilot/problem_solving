#include <iostream>
#include <string>
#include <sstream>

#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;

inline ll f(ll D, ll d){
  return (10*D) % d;
}

inline ll g(ll D, ll d){
  return (10*D-f(D, d))/d;
}

int main(){
  ll D, d, q;
  ll t, h;
  
  while( cin >> D >> d ){
    ostringstream oss;

    t = h = D % d;
    do{
      t = f(t, d);
      h = f(f(h, d), d);
    }while( t != h );

    int u = 0;
    h = D % d;
    while( t != h ){
      t = f(t, d);
      h = f(h, d);
      u++;
    }
    //debug(u);

    int l = 1;
    h = f(t, d);
    while( t != h ){
      h = f(h, d);
      l++;
    }
    //debug(l);

    oss << D/d << ".";
    
    h = D % d;
    rep(i, 1, u){
      oss << g(h, d);
      h = f(h, d);
    }
    oss << "(";

    rep(i, 1, l){
      oss << g(h, d);
      h = f(h, d);
    }
    oss << ")";

    cout << D << "/" << d << " = ";
    int places = 50;
    if( u + l <= places ){
      cout << oss.str() << endl;
    }else{
      int dotindex = oss.str().find(".");
      cout << oss.str().substr(0, places+2+dotindex) << "...)" << endl;
    }
    cout << "   " << l << " = number of digits in repeating cycle" << endl << endl;
  }
  
  return 0;
}

// AC

/*
  Cycle-finding over the remainder but printing the quotient.
  Count 50 places from the decimal point.
 */
