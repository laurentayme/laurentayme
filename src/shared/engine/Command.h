// Generated by dia2code
#ifndef ENGINE__COMMAND__H
#define ENGINE__COMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Engine;
}

#include "CommandTypeId.h"
#include "state/State.h"

namespace engine {

  /// class Command - 
  class Command {
    // Operations
  public:
    Command ();
    virtual ~Command ();
    virtual CommandTypeId getTypeId () const = 0;
    virtual void execute (state::State& state) = 0;
    virtual void execute (state::State& state, engine::Engine& engine);
    virtual int getVectX () const;
    virtual int getVectY () const;
    // Setters and Getters
  };

};

#endif
