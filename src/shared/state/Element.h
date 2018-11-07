// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <stdlib.h>
#include <string>
#include <vector>

namespace state {
  class Position;
  class Abilities;
}

#include "Position.h"
#include "Abilities.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    Position* position;
    size_t idType;
    size_t direction;
    // Operations
  public:
    Element (size_t idtype = 0);
    virtual ~Element ();
    size_t const getTypeId () const;
    void setTypeId (size_t idtype);
    Position getPosition () const;
    void setPosition (Position& position);
    void const affiche_Position ();
    virtual void affiche_Classe () = 0;
    virtual bool const isObstacle () const = 0;
    virtual bool const isWall () const = 0;
    virtual std::string const getClass () const = 0;
    virtual size_t const getDirection () const = 0;
    virtual void setDirection (size_t direction) = 0;
    virtual size_t const getSpaceType () const = 0;
    virtual int getWallType () const = 0;
    virtual int getLandscapeType () const = 0;
    virtual std::vector<Abilities*> getAbilitiesList () const = 0;
    // Setters and Getters
    const size_t& getIdType() const;
    void setIdType(const size_t& idType);
  };

};

#endif
