// Generated by dia2code
#ifndef AI__POINTCOMPAREWEIGHT__H
#define AI__POINTCOMPAREWEIGHT__H


namespace ai {
  class Point;
}

#include "Point.h"

namespace ai {

  /// class PointCompareWeight - 
  class PointCompareWeight {
    // Operations
  public:
    bool operator() (const Point& a, const Point& b);
    // Setters and Getters
  };

};

#endif