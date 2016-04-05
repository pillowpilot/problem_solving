#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > solutions;



int main(){
  int cases, money, garment, a;

  scanf("%d", &cases);
  while(cases-- > 0){
    solutions.clear();
    scanf("%d %d", &money, &garment);
    while(garment-- > 0){
      scanf("%d", &a);
      solutions.push_back( vector<int>(a) );

      vector<int>::iterator iter = solutions.back().begin();
      while(iter != solutions.back().end()){
	scanf("%d", &(*iter));
	iter++;
      }
    }

    /*
    vector< vector<int> >::const_iterator iter = solutions.begin();
    vector< int >::const_iterator iiter;
    while(iter != solutions.end()){
      iiter = iter->begin();
      while(iiter != iter->end()){
	printf("%d ", *iiter);
	iiter++;
      }
      printf("\n");
      iter++;
    }
    */
  }

  return 0;
}
