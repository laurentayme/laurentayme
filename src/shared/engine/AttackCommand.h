// Generated by dia2code
#ifndef ENGINE__ATTACKCOMMAND__H
#define ENGINE__ATTACKCOMMAND__H

#include <string>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class AttackCommand - 
  class AttackCommand : public engine::Command {
    // Attributes
  protected:
    int CharacterAttacker;
    int CharacterTarget;
    std::string AbilityUsed;
    int mouse_x;
    int mouse_y;
    // Operations
  public:
    AttackCommand (int CharacterAttacker, int CharacterTarget, std::string AbilityUsed);
    AttackCommand (int CharacterAttacker, int CharacterTarget, int x, int y);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    int getCharacterAttacker() const;
    void setCharacterAttacker(int CharacterAttacker);
    int getCharacterTarget() const;
    void setCharacterTarget(int CharacterTarget);
    const std::string& getAbilityUsed() const;
    void setAbilityUsed(const std::string& AbilityUsed);
    int getMouse_x() const;
    void setMouse_x(int mouse_x);
    int getMouse_y() const;
    void setMouse_y(int mouse_y);
  };

};

#endif
