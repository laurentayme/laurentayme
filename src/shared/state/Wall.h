// Generated by dia2code
#ifndef STATE__WALL__H
#define STATE__WALL__H

#include <string>
#include <stdlib.h>

namespace state {
  class Obstacle;
}

#include "Obstacle.h"

namespace state {

  /// class Wall - 
  class Wall : public state::Obstacle {
    // Operations
  public:
    Wall ();
    bool const isWall () const;
    bool const isObstacle () const;
    void affiche_Classe ();
    std::string const getClass () const;
    size_t const getDirection () const;
    // Setters and Getters
  };

};

#endif
