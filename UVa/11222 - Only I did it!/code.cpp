#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef bitset<11222> bs;
typedef vector<bs> vb;

vb fs; //FriendS
vi ss; //ScoreS

void readProblems(){
  int S;
  scanf("%d ", &S);
  while( S-- > 0 ){
    int a;
    scanf("%d ", &a);
    fs[0].set(a);
  }
  scanf("%d ", &S);
  while( S-- > 0 ){
    int a;
    scanf("%d ", &a);
    fs[1].set(a);
  }
  scanf("%d ", &S);
  while( S-- > 0 ){
    int a;
    scanf("%d ", &a);
    fs[2].set(a);
  }
}

void solve(){
  for( int i = 0; i < fs[0].size(); i++ ){
    bool a, b, c;
    a = fs[0].test(i);
    b = fs[1].test(i);
    c = fs[2].test(i);
    // Only triples w/ one true allowed, for later print
    if( a == true && b == false && c == false )ss[0]++;
    else if( a == false && b == true && c == false ) ss[1]++;
    else if( a == false && b == false && c == true ) ss [2]++;
    else{
      fs[0].reset(i);
      fs[1].reset(i);
      fs[2].reset(i);
    }
    //
  }
}

int max(){
  int a = ss[0];
  a = max(ss[1], a);
  a = max(ss[2], a);
  return a;
}

void printFriend(int fid){
  bs& f = fs[fid];
  printf("%d %d", fid + 1, max());
  for( int i = 0; i < f.size() - 1; i++ ){ 
    if( f.test(i) ){
      printf(" %d", i);
    }
  }
}

void init(){
  fs = vb(3); //All bits in bitset to zero
  ss = vi(3); //All scores to zero
}

int main(){
  int T;
  
  scanf("%d ", &T);
  for( int Case = 1; Case <= T; Case++ ){
    init();
    readProblems();
    solve();
    printf("Case #%d:\n", Case);
    for( int i = 0; i < ss.size(); i++ ){
      if( ss[i] == max() ){
	printFriend(i);
	printf("\n");
      }
    }
  }
  printf("\n");
  return 0;
}
