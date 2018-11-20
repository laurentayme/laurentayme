// Generated by dia2code
#ifndef ENGINE__WHITESURBRILLANCECOMMAND__H
#define ENGINE__WHITESURBRILLANCECOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class WhiteSurbrillanceCommand - 
  class WhiteSurbrillanceCommand : public engine::Command {
    // Attributes
  protected:
    float x;
    float y;
    // Operations
  public:
    WhiteSurbrillanceCommand (float x, float y);
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
  };

};

#endif
