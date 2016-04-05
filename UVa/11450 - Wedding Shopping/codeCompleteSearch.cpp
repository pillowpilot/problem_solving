#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <limits>

using namespace std;

int price(int moneyLeft, vector< vector<int> >::const_iterator garment, const vector< vector<int> > &gPrices){
  int maxPrice;
  list<int> options;
  
  if(moneyLeft < 0){
    //Si el costo de los productos seleccionados supera la cantidad de dinero disponible,
    //entonces se retorna -inf para asegurar la eliminacion de este subconjunto
    maxPrice = numeric_limits<int>::min();
  }else if(garment == gPrices.end()){
    //Si se llego al nivel mas bajo y la cantidad de dinero fue suficiente,
    //entonces es una solucion valida y se retorna cero para no variar la suma
    maxPrice = 0;
  }else{
    //Recorrer los productos del nivel actual
    vector<int>::const_iterator garmentPrice = garment->begin();
    while(garmentPrice != garment->end()){
      options.push_back( price( moneyLeft - *garmentPrice, garment + 1, gPrices) + *garmentPrice );
      garmentPrice++;
    }
    //Encontrar el mayor
    list<int>::const_iterator iter = options.begin();
    maxPrice = *iter;
    while(iter != options.end()){
      if(maxPrice < *iter){
	maxPrice = *iter;
      }
      iter++;
    }
  }
  return maxPrice;
}
    

int price(int moneyLeft, int garmentId, const vector< vector<int> > &gPrices){
  vector<int> options(20, numeric_limits<int>::min());
  int max, garment = 0;

  if(moneyLeft < 0){
    return numeric_limits<int>::min();
  }else if(gPrices[garmentId][0] == -1){
    return 0;
  }else{
    while(gPrices[garmentId][garment] != -1){
      //for(int i = 0; i < garmentId; i++) printf("-");
      //printf("%d\n", gPrices[garmentId][garment]);
      options[garment] = price( moneyLeft - gPrices[garmentId][garment], garmentId + 1, gPrices) + gPrices[garmentId][garment];
      garment++;
    }
  }
  
  vector<int>::const_iterator iter = options.begin();
  max = *iter;
  while(iter != options.end()){
    if(max < *iter){
      max = *iter;
    }
    iter++;
  }
  return max;
}


int main(){
  int cases, money, garment, a;
  vector< vector<int> > gPrices(20);
  
  
  cin >> cases;
  while(cases-- > 0){
    gPrices.clear();

    cin >> money >> garment;
    while(garment-- > 0){
      cin >> a;
      gPrices.push_back( vector<int>(a) );
      
      vector<int>::iterator iter = gPrices.back().begin();
      while(iter != gPrices.back().end()){
	cin >> *iter;
	iter++;
      }
    }

    a = price(money, gPrices.begin(), gPrices);
    if(a < 0){
      cout << "no solution" << endl;
    }else{
      cout << a << endl;
    }
  }
  
  return 0;
}
