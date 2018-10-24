// Generated by dia2code
#ifndef STATE__LANDSCAPE__H
#define STATE__LANDSCAPE__H

#include <string>
#include <stdlib.h>

namespace state {
  class Obstacle;
}

#include "Obstacle.h"

namespace state {

  /// class Landscape - 
  class Landscape : public state::Obstacle {
    // Operations
  public:
    Landscape ();
    bool const isObstacle () const;
    bool const isWall () const;
    void affiche_Classe ();
    std::string const getClass () const;
    size_t const getDirection () const;
    size_t const getSpaceType () const;
    // Setters and Getters
  };

};

#endif
