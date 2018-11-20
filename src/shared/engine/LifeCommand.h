// Generated by dia2code
#ifndef ENGINE__LIFECOMMAND__H
#define ENGINE__LIFECOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class LifeCommand - 
  class LifeCommand : public engine::Command {
    // Attributes
  protected:
    int character;
    int pv;
    // Operations
  public:
    LifeCommand (int character, int pv);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    int getCharacter() const;
    void setCharacter(int character);
    int getPv() const;
    void setPv(int pv);
  };

};

#endif
