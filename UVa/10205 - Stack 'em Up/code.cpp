#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string mapIntToName(int n){
  string value, suit;
  if(n > 0 && n < 53){
    n--;
    //Set Suit
    switch(n/13){
    case 0: suit = "Clubs"; break;
    case 1: suit = "Diamonds"; break;
    case 2: suit = "Hearts"; break;
    case 3: suit = "Spades"; break;
    default: suit = "Bad Suit!"; break;
    }
    //Set Value
    if(n % 13 > 8){
      switch(n % 13){
      case 9: value = "Jack"; break;
      case 10: value = "Queen"; break;
      case 11: value = "King"; break;
      case 12: value = "Ace"; break;
      default: value = "Bad Value!"; break;
      }
    }else{
      value = to_string(n % 13 + 2);
    }
    return value + " of " + suit;
  }else{
    return "Bad ID!";
  }
}

void shuffle(vector<int> &cards, const vector<int> &shuffle){
  vector<int> cardsTmp(52);
  for(int i = 0; i < cards.size(); i++){
    cardsTmp[i] = cards[i];
  }

  //"Within each set of 52 integers, i in position j means that the shuffle moves the ith card in the deck to position j."
  for(int i = 0; i < shuffle.size(); i++){
    cards[i] = cardsTmp[shuffle[i] - 1];
  }
}

void readShuffle(vector<int> &shuffle){
  for(int i = 0; i < 52; i++){
    scanf("%d ", &shuffle[i]);
  }
}

void printVector(const vector<int> &v){
  vector<int>::const_iterator iter = v.begin();
  while(iter != v.end()){
    printf("%d ", *iter);
    iter++;
  }
  printf("\n");
}

void initCards(vector<int> &cards){
  for(int i = 0; i < cards.size(); i++){
    cards[i] = i + 1;
  }
}

int main(){
  int cases, shufflesAmount, shuffleID = 0;
  string line;
  vector<int> cards(52);
  vector< vector<int> > shuffles;

  scanf("%d ", &cases); //Leer casos
  while(cases-- > 0){
    scanf("%d ", &shufflesAmount); //Leer cantidad de shuffles a aprender
    //printf("ShufflesAmount=%d\n", shufflesAmount);

    shuffles.resize(shufflesAmount, vector<int> (52)); //Redimensionar vector de vector<int>
    for(shuffleID = 0; shuffleID < shufflesAmount; shuffleID++){
      readShuffle(shuffles[shuffleID]);
    }
    
    //Inicializa el mazo y mientras lee los shuffle a realizar, los realiza. O(52k) k:= shuffles a realizar
    initCards(cards);
    do{
      getline(cin, line);
      if(line != ""){
	shuffleID = stoi(line);
	//printf("Shuffle: <%d>\n", shuffleID);
	shuffle(cards, shuffles[shuffleID - 1]);
	//printVector(cards);
      }
    }while(line != "");

    
    //Imprime el estado final del mazo
    vector<int>::iterator iter = cards.begin();
    while(iter != cards.end()){
      printf("%s\n", mapIntToName(*iter).c_str());
      iter++;
    }
    //Es "cases > 0" porque anteriormente ya se decremento "cases"
    //Por lo tanto, si esta en el ultimo caso "cases = 0"
    if(cases > 0){
      printf("\n");
    }
  }
  
  return 0;
}
