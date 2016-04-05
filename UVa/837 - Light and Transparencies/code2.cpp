#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Point{
private:
  double location;
  int segmentID;
public:
  Point(double location, int segmentID):location(location), segmentID(segmentID) {}
  double getLocation(){ return location; }
  int getSegmentId(){ return segmentID; }
  bool operator<(const Point& p) const { return location < p.location; }
};

class Segment{
private:
  double transparency;
  bool state;
public:
  Segment(double transparency): transparency(transparency) {}
  Segment(double transparency, bool state):state(state), transparency(transparency) {}
  int getTransparency(){ return transparency; }
  bool getState(){ return state; }
  void setState(bool s){ state = s; }
};

ostream& operator<<

int main(){
  std::ios_base::sync_with_stdio(false);

  std::vector<Point> points = std::vector<Point>();
  std::vector<Segment> segments = std::vector<Segment> ();
  
  int cases;
  std::cin >> cases;
  while( cases-- > 0 ){

    points.clear();
    segments.clear();
    
    int pointsCounter;
    std::cin >> pointsCounter;

    while( pointsCounter-- > 0 ){
      double Ax, Ay, Bx, By, transparency;
      std::cin >> Ax >> Ay >> Bx >> By >> transparency;

      points.push_back( Point(Ax, segments.size()) );
      points.push_back( Point(Bx, segments.size()) );
      segments.push_back( Segment(transparency) );
    }

    std::sort( points.begin(), points.end() );

    // Sweepline
    double totalTransparency = 1;
    for( Point p: points ){
      
      Segment segment = segments[ p.getSegmentId() ];

      if( segment.getState() == false ){
	segment.setState( true );
	totalTransparency *= segment.getTransparency();
      }else{
	segment.setState( false );
	totalTransparency /= segment.getTransparency();
      }

      std::cout << totalTransparency << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
