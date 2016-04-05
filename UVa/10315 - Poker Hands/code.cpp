#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

int ctoi(char c){
  return c - '0';
}

bool readCards(vector<int> &values, vector<int> &suits){
  int index = 0;
  bool keepReading = true;
  char value, suit;

  fill(values.begin(), values.end(), 0);
  fill(suits.begin(), suits.end(), 0);
  //  values.clear(); values.resize(13);
  //  suits.clear(); suits.resize(4);
  while(index++ < 5 && keepReading == true){
    if( scanf(" %c%c ", &value, &suit) != 2 ){
      keepReading =  false;
    }else{
      //printf("%c%c ", value, suit);
      toupper(value); toupper(suit);
      if( isdigit(value) ){
	values[ ctoi(value) - 2 ]++;
      }else{
	switch(value){
	case 'T': values[8]++; break;
	case 'J': values[9]++; break;
	case 'Q': values[10]++; break;
	case 'K': values[11]++; break;
	case 'A': values[12]++; break;
	}
      }
      switch(suit){
      case 'C': suits[0]++; break;
      case 'D': suits[1]++; break;
      case 'H': suits[2]++; break;
      case 'S': suits[3]++; break;
      }
    }
  }
  /*
  printf("\n");
  vector<int>::iterator iter = suits.begin();
  while(iter != suits.end()){
    printf("%d ", *iter++);
  }
  printf("\n");
  */
  return keepReading;
}

int scoreHand(vector<int> &values, vector<int> &suits){
  bool triple, quadruple, allSameSuit, consecutive;
  int pairs = 0, consecutiveOnes = 0, score, a, b, c, d, e;
  triple = quadruple = allSameSuit = consecutive = false;

  //Check for pairs, a triple and a quadruple in values.
  vector<int>::iterator iter = values.begin();
  while(iter != values.end()){
    switch(*iter){
    case 2: pairs++; break;
    case 3: triple = true; break;
    case 4: quadruple = true; break;
    }
    iter++;
  }
  //Check for 5 consecutive ones in values.
  iter = values.begin();
  while(*iter != 0){
    iter++;
  }
  if(*iter == 1){
    while(*iter++ == 1) consecutiveOnes++;
    if(consecutiveOnes == 5) consecutive = true;
  }else{
    consecutive = false;
  }
  //Check for quintuple in suits.
  iter = suits.begin();;
  while(iter != suits.end()){
    if(*iter == 5) allSameSuit = true;
    iter++;
  }
  //Calculate Score
  if(consecutive && allSameSuit){
    //Straight Flush
    a = 12; while(values[a] != 1) a--;
    score = 747400 + a;                                // 747400 < scoreStraightFlush < 747420
  }else if(quadruple){
    //Four of a Kind
    a = 12; while(values[a] != 4) a--;
    b = 12; while(values[b] != 1) b--;
    score = 747200 + a*13 + b;                         // 747200 < scoreFour < 747400
  }else if(triple && pairs == 1){
    //Full house
    a = 12; while(values[a] != 3) a--;
    b = 12; while(values[b] != 2) b--;
    score = 747000 + a*13 + b;                         // 747000 < scoreFullHouse < 747168
  }else if(allSameSuit){
    //Flush
    a = 12; while(values[a] != 1) a--;
    b = a - 1; while(values[b] != 1) b--;
    c = b - 1; while(values[c] != 1) c--;
    d = c - 1; while(values[d] != 1) d--;
    e = d - 1; while(values[e] != 1) e--;
    score = 378020 + a*28651 + b*2197 + c*169 + d*13 + e;   // 378020 < scoreFlush < 746735
  }else if(consecutive){
    //Straight
    a = 12; while(values[a] != 1) a--;
    score = 378000 + a;                                // 378000 < scoreStraight < 378020
  }else if(triple){
    //Three of a Kind
    a = 12; while(values[a] != 3) a--;
    b = 12; while(values[b] != 1) b--;
    c = b - 1; while(values[c] = 1) c--;
    score = 375000 + a*169 + b*13 + c;                 // 375000 < scoreTriple < 377182
  }else if(pairs == 2){
    //Two Pairs
    a = 12; while(values[a] != 2) a--;
    b = a - 1; while(values[b] != 2) b--;
    c = 12; while(values[c] != 1) c--;
    score = 372000 + a*169 + b*13 + c;                 // 372000 < scoreTwoPairs < 374182
  }else if(pairs == 1){
    //Pair
    a = 12; while(values[a] != 2) a--;
    b = 12; while(values[b] != 1) b--;
    c = b - 1; while(values[c] != 1) c--;
    score = 369000 + a*169 + b*13 + c;                 // 369000 < scorePair < 371182
  }else{
    //High Card
    a = 12; while(values[a] != 1) a--;
    b = a - 1; while(values[b] != 1) b--;
    c = b - 1; while(values[c] != 1) c--;
    d = c - 1; while(values[d] != 1) d--;
    e = d - 1; while(values[e] != 1) e--;
    score = 0 + a*28651 + b*2197 + c*169 + d*13 + e;   // 0 < scoreHighCard < 368715
  }
  return score;
}
int main(){
  int scoreB, scoreW;
  vector<int> values(13), suits(4);

  while(readCards(values, suits)){
    scoreB = scoreHand(values, suits);
    //printf("%d\n", scoreB);

    readCards(values, suits);
    scoreW = scoreHand(values, suits);
    //printf("%d\n", scoreW);

    if(scoreW > scoreB){
      printf("White wins.\n");
    }else if(scoreW < scoreB){
      printf("Black wins.\n");
    }else{
      printf("Tie.\n");
    }
  }
  return 0;
}
