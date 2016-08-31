#include <iostream>
#include <algorithm>

using namespace std;

int sub(const int pandigital[10], int index){
  int n = 0;
  for(int i = index; i < index + 3; i++)
    n = n*10 + pandigital[i];

  return n;
}

bool check(const int pandigital[10], const int divisors[]){
  int c = 0;
  for(int i = 1; i < 8; i++){
    int s = sub(pandigital, i);
    
    if( s % divisors[i-1] == 0)
      c++;
  }

  return c == 7;
}

void printArray(const int a[], int l){
  for(int i = 0; i < l; i++)
    cout << a[i] << ' ';
  cout << '\n';
}

long long toInt(const int a[]){
  long long n = 0;
  for(int i = 0; i < 10; i++)
    n = n*10 + a[i];
  return n;
}

int main(){
  int pandigital[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  //int pandigital[] = {1, 4, 0, 6, 3, 5, 7, 2, 8, 9};
  int divisors[] = {2, 3, 5, 7, 11, 13, 17};

  int counter = 0;
  long long sum = 0;
  do{
    if( check(pandigital, divisors) ){
      counter++;
      sum += toInt(pandigital);
      printArray(pandigital, 10);
      cout << toInt(pandigital) << endl;
    }
  }while(next_permutation(pandigital, pandigital+10));
  
  cout << counter << endl;
  cout << sum << endl;
  return 0;
}

// AC ans=16695334890
