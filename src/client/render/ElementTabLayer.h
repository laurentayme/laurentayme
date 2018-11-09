// Generated by dia2code
#ifndef RENDER__ELEMENTTABLAYER__H
#define RENDER__ELEMENTTABLAYER__H


namespace state {
  class ElementTab;
};
namespace render {
  class Layer;
};
namespace state {
  class Observer;
}

#include "Layer.h"
#include "state/Observer.h"
#include "state/ElementTab.h"

namespace render {

  /// class ElementTabLayer - 
  class ElementTabLayer : public render::Layer, public state::Observer {
    // Associations
    // Attributes
  private:
    state::ElementTab& tab;
    // Operations
  public:
    ElementTabLayer (state::ElementTab& tab);
    void initSurface ();
    void stateChanged (const state::Event& event);
    state::ElementTab& getTab () const;
    // Setters and Getters
  };

};

#endif
