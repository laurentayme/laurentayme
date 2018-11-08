// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <stdlib.h>
#include <vector>

namespace state {
  class Element;
  class Position;
  class Observable;
}

#include "Observable.h"
#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab : public state::Observable {
    // Associations
    // Attributes
  private:
    /// Largeur de la Map
    size_t width;
    /// Longueur de la Map
    size_t height;
    std::vector<Element*> elementList;
    // Operations
  public:
    ElementTab (int width, int height, std::vector<Element*> elementsList);
    ~ElementTab ();
    size_t const getHeight () const;
    size_t const getWidth () const;
    std::vector<Element*> getElementList () const;
    void addElement (Element* e);
    Element* const getLocatedElement (Position* position);
    void setElement (Position& position, int element);
    void resize (size_t width, size_t height);
    void setElementDirection (int direction, int element);
    void setCharacterPV (int element, int pv);
    void setCharacterPM (int element, int pm);
    void setCharacterPA (int element, int pa);
    // Setters and Getters
  };

};

#endif
