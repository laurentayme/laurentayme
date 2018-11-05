// Generated by dia2code
#ifndef STATE__WALL__H
#define STATE__WALL__H

#include <stdlib.h>
#include <string>

namespace state {
  class Obstacle;
}

#include "Obstacle.h"

namespace state {

  /// class Wall - 
  class Wall : public state::Obstacle {
    // Attributes
  protected:
    size_t wallType;
    // Operations
  public:
    Wall ();
    bool const isWall () const;
    bool const isObstacle () const;
    void affiche_Classe ();
    std::string const getClass () const;
    size_t const getDirection () const;
    void setDirection (size_t direction);
    size_t const getSpaceType () const;
    int getWallType () const;
    void setWallType (int wall);
    int getLandscapeType () const;
    // Setters and Getters
  };

};

#endif
