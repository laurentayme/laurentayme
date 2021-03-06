// Generated by dia2code
#ifndef AI__AI__H
#define AI__AI__H

#include <vector>

namespace engine {
  class Engine;
};
namespace state {
  class State;
};
namespace engine {
  class Command;
};
namespace state {
  class Observer;
}

#include "state/Observer.h"

namespace ai {

  /// class AI - 
  class AI : public state::Observer {
    // Operations
  public:
    virtual void stateChanged (const state::Event& event) = 0;
    virtual void run (engine::Engine& Engine, int character, state::State& state) = 0;
  protected:
    void listCommands (const state::State& state, int character, std::vector<engine::Command*>& move_list);
    // Setters and Getters
  };

};

#endif
