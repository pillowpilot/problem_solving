#include <cstdio>
#include <list>
#include <algorithm>
#include <limits>

using namespace std;

int min(int a, int b){
  return ( a < b )?a:b;
}

int cover(int a, int b, int c, int d){
  int t;
  if( d < c ){
    t = d;
    d = c;
    c = t;
  }
  
  if( d <= a || b <= c ){
    return 0;
  }else{
    if( c < a ) return cover(a, b, a, d);
    if( b < d ) return cover(a, b, c, b);
    return d - c;
  }
}

int main(){
  int cases, M, a, b;
  bool printEndOfCase = true;
  list< pair <int, int> > segments, coverSegments, posibleCovers;

  scanf("%d", &cases);
  while(cases-- > 0){
    scanf("%d", &M);
    
    segments.clear();
    scanf("%d %d", &a, &b);
    while( !( a == 0 && b == 0 ) ){
      if(cover(0, M, a, b) > 0){
	//printf("Se cargo: %3d %3d cubriendo %d\n", a, b, cover(0, M, a, b));
	segments.push_back( make_pair(a, b) );
      }
      scanf("%d %d", &a, &b);
    }

    /*
      list< pair< int, int > >::const_iterator iter = segments.begin();
    while( iter != segments.end() ){
      printf("(%3d, %3d) ", iter->first, iter->second);
      iter++;
    }
    printf("\n");
    */

    if( segments.size() > 0 ){

      a = 0; coverSegments.clear();
      list< pair< int, int > >::iterator segment, maxCoverSegment;
      do{
	posibleCovers.clear();

	segment = segments.begin();
	while(segment != segments.end()){
	  if( min(segment->first, segment->second) == a ) posibleCovers.push_back(*segment);
	  segment++;
	}
	
	int maxCover = numeric_limits<int>::min();
	maxCoverSegment = posibleCovers.end();
	segment = posibleCovers.begin();
	while(segment != posibleCovers.end()){
	  b = cover(a, M, segment->first, segment->second);
	  if( maxCover < b ){
	    maxCover = b;
	    maxCoverSegment = segment;
	  }
	  segment++;
	}

	if( maxCoverSegment != posibleCovers.end()){
	  a += maxCover;
	  coverSegments.push_back(*maxCoverSegment);
	}
      }while( a < M && maxCoverSegment != posibleCovers.end());

      if( a < M ){
	printf("0\n");
      }else{
	coverSegments.sort();

	printf("%lu\n", coverSegments.size());
	segment = coverSegments.begin();
	while(segment != coverSegments.end()){
	  printf("%d %d\n", segment->first, segment->second);
	  segment++;
	}
      }

    }else{
      printf("0\n");
    }

    if(printEndOfCase){
      printf("\n");
    }
    if(cases == 1) printEndOfCase = false;
  }
  return 0;
}
