// Generated by dia2code
#ifndef STATE__OBSTACLE__H
#define STATE__OBSTACLE__H


namespace state {
  class StaticElement;
}

#include "StaticElement.h"

namespace state {

  /// class Obstacle - 
  class Obstacle : public state::StaticElement {
    // Attributes
  protected:
    bool wall;
    // Operations
  public:
    Obstacle ();
    ~Obstacle ();
    // Setters and Getters
    bool getWall() const;
    void setWall(bool wall);
  };

};

#endif
