/*
  ID: carlos.16
  PROG: friday
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

#define rep(i, a, b) for(__typeof(a) i=a; i <= b; i++)
#define debug(x) cout << #x << " = " << x << endl;

using namespace std;

bool leap_year(int y){
  if( y%100 == 0 )
    return y%400 == 0;
  return y%4==0;
}

int main(){
  ifstream input("friday.in");
  ofstream output("friday.out");

  vector<int> max_day(12, 31);
  max_day[3] = max_day[5] = max_day[8] = max_day[10] = 30;
  // Apr Jun Sep Nov
  
  int n;
  input >> n;

  vector<int> ans(7);

  int year=1900, month=0, day=1;
  int days_so_far=0;
  while( year <= 1900+n-1 ){
    if( leap_year(year) )
      max_day[1] = 29;
    else
      max_day[1] = 28;

    month = 0;
    while( month < 12 ){
      
      day = 1;
      while( day <= max_day[month] ){
	//cout << day << "/" << month +1<< "/" << year << endl;
	days_so_far++;
	if( day == 13 ){
	  ans[days_so_far%7]++;
	}
	day++;
      }
      
      month++;
    }
    year++;
  }
  output << ans[(0+6)%7];
  rep(i, 1, 6){
    output << " " << ans[(i+6)%7];
  }
  output << endl;
  return 0;
}

// AC
