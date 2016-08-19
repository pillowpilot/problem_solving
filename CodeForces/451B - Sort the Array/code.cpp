#include <iostream>
#include <algorithm>

using namespace std;

bool check(int a[], int s[], int i, int j){
  int k = 0;
  while( i + k <= j && a[i+k] == s[j-k] ){
    k++;
  }

  return i+k>j;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int a[n];
  int s[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    s[i] = a[i];
  }
  sort(s, s+n);

  int i = 0, j = n-1;
  while( i < n && a[i] == s[i] )
    i++;
  while( j >= 0 && a[j] == s[j] )
    j--;

  //cout << ">> ";
  //cout << i << ' '<< j << endl;
  
  if( i >= j ){
    cout << "yes\n";
    if( i == j )
      cout << i + 1<< ' ' << i + 1<< endl;
    else
      cout << 1 << ' ' << 1 << endl;
  }else{
    if( check(a, s, i, j) )
      cout << "yes\n" << i+1 << ' ' << j+1 << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}

// AC
