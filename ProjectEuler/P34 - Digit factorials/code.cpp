#include <iostream>

using namespace std;

inline bool isSolution(int i){
  int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  int sum = 0, t = i;
  while( i != 0 ){
    sum += f[ i % 10 ];
    i /= 10;
  }
  return sum == t;
}

int main(){
  const int limit = 1854721;

  long long sum = 0;
  for(int i = 0; i < limit; i++){
    if( isSolution(i) ){
      sum += i;
      cout << ">> " << i << "\n";
    }
  }
  cout << "Sum: " << sum << endl;
  cout << "Solution: " << sum - 1 - 2 << endl;
  return 0;
}

/*
  Finding upper limit...
  If D is a solution with n digits, then 10^{n-1} <= D <= 9!*n.
  But for n >= 8, this does not hold!.

  Lemma A: 10^{n} / (n+1) >= 10^{n-1} / n for all n > 0
  n > 1/9 > 0
  9n > 1
  10n > n + 1
  10n*10^{n-1} > (n+1)*10^{n-1}
  10^n*n > 10^{n-1}*(n+1)
  10^n / (n+1) > 10^{n-1} / n 
  QED.

  Proof by induction: 10^{n-1} > 9!*n for all 8 <= n
  Base Case: 
  n = 8. 10^7 > 9!*8. True
  Recursive Step: 
  Given than 10^{n-1} > 9!n we have 10^{n-1} / n > 9!.
  n > 8
  n > 1/9
  10^n / (n+1) > 10^{n-1} / n By Lemma A
  10^n / (n+1) > 10^{n-1} / n > 9! 
  10^n / (n+1) > 9!
  10^{(n+1)-1} > 9!(n+1)
  QED
 */

/*
  Upper limit can be reduced to 1,854,721.
  If n is a natural number of d digits that is a factorion, then 10d − 1 ≤ n ≤ 9!d. This fails to hold for d ≥ 8 thus n has at most 7 digits, and the first upper bound is 9,999,999. But the maximum sum of factorials of digits for a 7 digit number is 9!*7 = 2,540,160 establishing the second upper bound. Going further, 9!6 is 2,177,280, and the only 7 digit number not larger than 2,540,160 containing six 9's is 1,999,999, which is not a factorion by inspection. The next highest sum would be given by 1,999,998, yielding a third upper bound of 1,854,721.
 */

// AC
