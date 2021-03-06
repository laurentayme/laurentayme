// Generated by dia2code
#ifndef AI__POINT__H
#define AI__POINT__H


namespace ai {
  class Point;
}

#include "state/Direction.h"

namespace ai {

  /// class Point - 
  class Point {
    // Attributes
  protected:
    int x;
    int y;
    int weight;
    // Operations
  public:
    Point (int x = 0, int y = 0, int w = 0);
    Point transform (int d);
    int getWeight () const;
    int getX () const;
    int getY () const;
    void setWeight (int w);
    void setX (int x);
    void setY (int y);
    // Setters and Getters
  };

};

#endif
