// Generated by dia2code
#ifndef ENGINE__MOVECHARACTERCOMMAND__H
#define ENGINE__MOVECHARACTERCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class MoveCharacterCommand - 
  class MoveCharacterCommand : public engine::Command {
    // Attributes
  protected:
    int character;
    // Operations
  public:
    MoveCharacterCommand (int character);
    CommandTypeId  getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    int getCharacter() const;
    void setCharacter(int character);
  };

};

#endif
