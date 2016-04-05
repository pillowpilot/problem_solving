#include <iostream>

using namespace std;

/*
  Si se busca linealmente divisores de n desde 2, entonces el primero será un primo.
Demostración por contradicción:
Supongamos que el primer divisor encontrado d no es primo, entonces d=ab para un
par de enteros positivos a, b. Entonces a es menor a d y divisor suyo. Luego es
divisor de n, por ello es un divisor de n menor a d. Pero d fue el primer divisor
encontrado (el menor). QED.
 */
long long findFirstPrime(long long n){
  long long p = 2;
  while( n % p != 0 )
    p++;
  return p;
}

int main(){
  long long n = 600851475143, p, maxp = 1;
  //n = 13195;
  do{
    p = findFirstPrime(n);
    n = n / p;
    //cout << p << " ";
    if( maxp < p )
      maxp = p;
  }while(n != 1);

  cout << maxp << endl;
  
  return 0;
}

// AC
