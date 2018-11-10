// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H


namespace state {
  class ElementTab;
  class Observable;
}

#include "Observable.h"
#include "ElementTab.h"

namespace state {

  /// class State - 
  class State : public state::Observable {
    // Associations
    // Attributes
  public:
    ElementTab* landscape;
  private:
    ElementTab* carte;
    ElementTab* characters;
    ElementTab* menu;
    ElementTab* red_map;
    ElementTab* landscape;
    // Operations
  public:
    ElementTab* getMap () const;
    ElementTab* getCharacters () const;
    ElementTab* getMenu () const;
    void setMap (ElementTab* map);
    void setCharacters (ElementTab* characters);
    void setMenu (ElementTab* menu);
    ElementTab* getRedMap () const;
    void setRedMap (ElementTab* red_map);
    ElementTab* getLandscape () const;
    void setLandscape (ElementTab* landscape);
    // Setters and Getters
  };

};

#endif