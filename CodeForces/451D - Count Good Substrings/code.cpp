#include <bits/stdc++.h>
#define forall(it, m) for(auto it=m.begin(); it != m.end(); ++it)
#define rep(i, a, b) for(int i=a;i<b; i++)
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  ll aeven = 0;
  ll aodd = 0;
  ll beven = 0;
  ll bodd = 0;

  ll anseven = 0;
  ll ansodd = 0;
  rep(i, 0, s.size()){
    char c = s[i];

    if( c == 'a' ){
      if( i % 2 == 0 ){// even position
	ansodd += aeven + 1; // odd length with all previous even positions plus substr of length 1 (letter itself)
	anseven += aodd; // even length with all previous odd positions
      }else{ // odd position
	ansodd += aodd + 1;
	anseven += aeven;
      }
    }else{ // same for b
      if( i % 2 == 0 ){
	ansodd += beven + 1;
	anseven += bodd;
      }else{
	ansodd += bodd + 1;
	anseven += beven;
      }
    }

    // keep counters updated
    if( c == 'a' ){
      if( i % 2 == 0 ) aeven++;
      else aodd++;
    }else{
      if( i % 2 == 0 ) beven++;
      else bodd++;
    }	
  }

  cout << anseven << " " << ansodd << "\n";

  return 0;
}

// AC
/*
  Tricky. Read editorial and see AC submission.
  Notice that every substr s[i..j] is good iff s[i] == s[j].
  Therefore a trivial O(n^2) appears, however n <= 1e5 and timelimit is 2s.
  
  For s[j] = a, notice that it can be paired with all s[i] = a where i <= j.
  Discriminate such that the length is even or odd. In other words, 
  if j is even, then to build all even length good substr we have to pair it with
  i <= j where i is odd. Because len = j-i+1 is even only if i is odd.
  if j is odd, then pair it with all i <=j where i is even.
  
  For s[j] = b is analogous.
 */
