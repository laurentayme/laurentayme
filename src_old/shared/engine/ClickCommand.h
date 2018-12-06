// Generated by dia2code
#ifndef ENGINE__CLICKCOMMAND__H
#define ENGINE__CLICKCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Engine;
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class ClickCommand - 
  class ClickCommand : public engine::Command {
    // Attributes
  private:
    int x_mouse;
    int y_mouse;
    // Operations
  public:
    ClickCommand (int x, int y);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    void execute (state::State& state, engine::Engine& engine);
    // Setters and Getters
  };

};

#endif