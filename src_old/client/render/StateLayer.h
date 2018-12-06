// Generated by dia2code
#ifndef RENDER__STATELAYER__H
#define RENDER__STATELAYER__H


namespace state {
  class State;
};
namespace sf {
  class Text;
  class Font;
};
namespace render {
  class Layer;
};
namespace state {
  class Observer;
}

#include "Layer.h"
#include "state/Observer.h"
#include "state/State.h"

namespace render {

  /// class StateLayer - 
  class StateLayer : public sf::Font, public sf::Text, public render::Layer, public state::Observer {
    // Associations
    // Attributes
  private:
    const state::State& state;
    Text textpv;
    Text textpa;
    Text textpm;
    Font font;
    Text textpv_sram;
    Text textwin;
    Font font2;
    // Operations
  public:
    StateLayer (const state::State& state);
    void initSurface ();
    void stateChanged (const state::Event& event);
    Text getTextpv () const;
    Text getTextpa () const;
    Text getTextpm () const;
    Font getFont () const;
    Text getTextpvSram () const;
    Text getTextwin () const;
    Font getFont2 () const;
    // Setters and Getters
  };

};

#endif