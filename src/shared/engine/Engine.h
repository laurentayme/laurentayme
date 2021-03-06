// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <map>
#include <memory>
#include <mutex>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Command;
  class Engine_Observable;
}

#include "Command.h"
#include "Engine_Observable.h"

namespace engine {

  /// class Engine - 
  class Engine : public engine::Engine_Observable {
    // Associations
    // Attributes
  private:
    state::State* currentState;
    std::map<int,std::unique_ptr<Command>> currentCommands;
    mutable std::mutex commands_mutex;
  protected:
    bool enableRecord     = false;
    Json::Value record;
    bool stop     = false;
    // Operations
  public:
    Engine ();
    ~Engine ();
    void setState (state::State* state);
    const state::State* getState () const;
    void addPassiveCommands ();
    void addCommand (int priority, Command* cmd);
    void addCommand (int priority, std::unique_ptr<Command> cmd);
    int getNbCommands () const;
    void update ();
    void setEnableRecord (bool rec);
    // Setters and Getters
    bool getEnableRecord() const;
    const Json::Value& getRecord() const;
    void setRecord(const Json::Value& record);
    bool getStop() const;
    void setStop(bool stop);
  };

};

#endif
