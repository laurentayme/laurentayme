// Generated by dia2code
#ifndef STATE__LANDSCAPE__H
#define STATE__LANDSCAPE__H

#include <stdlib.h>
#include <string>
#include <vector>

namespace state {
  class Obstacle;
}

#include "Obstacle.h"

namespace state {

  /// class Landscape - 
  class Landscape : public state::Obstacle {
    // Attributes
  protected:
    size_t landscapeType;
    // Operations
  public:
    Landscape ();
    bool isObstacle () const;
    bool isWall () const;
    void affiche_Classe ();
    std::string getClass () const;
    size_t getDirection () const;
    void setDirection (size_t direction);
    size_t getSpaceType () const;
    int getWallType () const;
    int getLandscapeType () const;
    void setLandscapeType (int landscape);
    std::vector<Abilities*> getAbilitiesList ();
    size_t getPV () const;
    size_t getPA () const;
    size_t getPM () const;
    void setPV (int pv);
    void setPM (int pm);
    void setPA (int pa);
    size_t getTypeId () const;
    void setStatut (int statut);
    int getStatut () const;
    size_t getTeam () const;
    void setTeam (size_t team);
    bool isPlayer () const;
    void setPlayer (bool player);
    // Setters and Getters
  };

};

#endif
