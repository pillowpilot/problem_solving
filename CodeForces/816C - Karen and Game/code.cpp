#include <bits/stdc++.h>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void print(vvi m){
  return ;
  rep(i, 0, m.size()-1){
    rep(j, 0, m[i].size()-1){
      cout << setw(2) << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vi rowmoves(vvi& b){
  int n = b.size();
  int m = b[0].size();
  
  vi ansrow;
  rep(i, 0, n-1){
    int mine = 1<<30;
    rep(j, 0, m-1){
      mine = min(mine, b[i][j]);
    }
    rep(j, 0, m-1){
      b[i][j] -= mine;
    }
    rep(k, 1, mine){
      ansrow.push_back(i);
    }
  }
  
  return ansrow;
}

vi colmoves(vvi& b){
  int n = b.size();
  int m = b[0].size();
  
  vi anscol;
  rep(j, 0, m-1){
    int mine = 1<<30;
    rep(i, 0, n-1){
      mine = min(mine, b[i][j]);
    }
    rep(i, 0, n-1){
      b[i][j] -= mine;
    }
    rep(k, 1, mine){
      anscol.push_back(j);
    }
  }
  return anscol;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vvi b(n, vi(m, 0));
  vvi b2(n, vi(m, 0));

  rep(i, 0, n-1){
    rep(j, 0, m-1){
      int x;
      cin >> x;
      b[i][j] = x;
      b2[i][j] = x;
    }
  }
  print(b);

  vi ans1row = rowmoves(b);
  print(b);
  vi ans1col = colmoves(b);  
  print(b);

  vi ans2col = colmoves(b2);
  print(b2);
  vi ans2row = rowmoves(b2);
  print(b2);


  bool allzeros1 = true;
  rep(i, 0, n-1){
    rep(j, 0, m-1){
      if( b[i][j] != 0 )
	allzeros1 = false;
    }
  }

  bool allzeros2 = true;
  rep(i, 0, n-1){
    rep(j, 0, m-1){
      if( b2[i][j] != 0 )
	allzeros2 = false;
    }
  }  

  if( !allzeros1 && !allzeros2 )
    cout << -1 << endl;
  else{
    int k1 = ans1row.size() + ans1col.size();
    int k2 = ans2row.size() + ans2col.size();
    if( k1 < k2 && allzeros1 ){
      cout << k1 << endl;
      for(int i = 0; i < ans1row.size(); i++){
	cout << "row " << ans1row[i]+1 << "\n";
      }
      for(int i = 0; i < ans1col.size(); i++){
	cout << "col " << ans1col[i]+1 << "\n";
      }
    }else{
      cout << k2 << endl;
      for(int i = 0; i < ans2row.size(); i++){
	cout << "row " << ans2row[i]+1 << "\n";
      }
      for(int i = 0; i < ans2col.size(); i++){
	cout << "col " << ans2col[i]+1 << "\n";
      }
    }
  }
  
  return 0;
}

// AC
/*
  Notice that operations are conmutative (row x row y = row y row x) (same for col)
  and (row x col y = col y row x). So we can "separate" all row operations from the col ops.
  Something like
  k
  row a
  row b
  ...
  col a
  col b

  or

  k
  col a
  ...
  row b

  Check both strategies and print the best one.
 */
