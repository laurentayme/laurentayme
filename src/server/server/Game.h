// Generated by dia2code
#ifndef SERVER__GAME__H
#define SERVER__GAME__H

#include <vector>

namespace server {
  class Player;
}

#include "Player.h"

namespace server {

  /// class Game - 
  class Game {
    // Associations
    // Attributes
  protected:
    std::vector<Player> players;
    // Operations
  public:
    Game ();
    void addPlayer (Player player);
    void setPlayer (int id, Player player);
    Player getPlayer (int id) const;
    void removePlayer (int id);
    std::vector<Player> getPlayers () const;
    // Setters and Getters
    void setPlayers(const std::vector<Player>& players);
  };

};

#endif
