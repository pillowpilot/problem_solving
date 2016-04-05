#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void printV(const vector<int> &v){
  vector<int>::const_iterator iter = v.begin();
  while(iter != v.end()){
    printf("%d ", *iter);
    iter++;
  }
  printf("\n");
}

int main(){
  int heads, knights, money;
  int maxDiameter, maxHeight;
  vector<int> hDia, kHei;

  do{
    scanf("%d %d", &heads, &knights);
    if( heads != 0 && knights != 0){
      money = 0; maxDiameter = maxHeight = numeric_limits<int>::min();
      hDia.clear(); kHei.clear();
      hDia.resize(heads); kHei.resize(knights);
      
      vector<int>::iterator iter = hDia.begin();
      while(iter != hDia.end()){
	scanf("%d", &(*iter));
	if(maxDiameter < *iter) maxDiameter = *iter;
	iter++;
      }

      iter = kHei.begin();
      while(iter != kHei.end()){
	scanf("%d", &(*iter));
	if(maxHeight < *iter) maxHeight = *iter;
	iter++;
      }

      if( maxDiameter > maxHeight || heads > knights){
	printf("Loowater is doomed!\n");
      }else{	
	sort(hDia.begin(), hDia.end());
	sort(kHei.begin(), kHei.end());

	//printV(hDia);
	//printV(kHei);

	vector<int>::const_iterator knight = kHei.begin();
	vector<int>::const_iterator head = hDia.begin();
	while(head != hDia.end() && knight != kHei.end()){
	  while(knight != kHei.end() && *knight < *head) knight++;
	  if(*knight >= *head){
	    money += *knight;
	    knight++;
	    head++;
	  }
	}
	
	if(head == hDia.end()){
	  printf("%d\n", money);
	}else{
	  printf("Loowater is doomed!\n");
	}
      }
    }
  }while(heads != 0 && knights != 0);
  
  return 0;
}
