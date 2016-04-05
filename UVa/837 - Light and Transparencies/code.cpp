#include <stdio.h>
#include <vector>

using namespace std;

typedef struct{
  pair<double, double> a;
  pair<double, double> b;
  double coef;
} segment;

void normalizeSegment(segment &s){
  if(s.a.first > s.b.first){
    pair<double, double> tmp = s.a;
    s.a = s.b;
    s.b = tmp;
  }
}
  

void readSegment(vector<segment> &segments){
  segment s;

  scanf("%lf %lf %lf %lf %lf \n", &s.a.first, &s.a.second, &s.b.first, &s.b.second, &s.coef);
  normalizeSegment(s);

  segments.push_back(s); // Mejorar rendimiento?
}

int main(){
  int cases, segAmount;
  vector <segment> segments;

  scanf("%d \n\n", &cases); //Leer #casos
  while(cases-- > 0){
    scanf("%d \n", &segAmount); //Leer #segmentos
    segments.clear();
    segments.resize(segAmount);

    while(segAmount-- > 0){
      readSegment(segments);
    }

    vector<segment>::iterator iter = segments.begin();
    for(;iter != segments.end(); iter++){
      printf("Segmento: (%lf, %lf) (%lf, %lf) con %lf\n", iter->a.first, iter->a.second, iter->b.first, iter->b.second, iter->coef);
    }
    scanf("%*c");
  }
    
  return 0;
}
