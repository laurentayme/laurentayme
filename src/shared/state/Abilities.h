// Generated by dia2code
#ifndef STATE__ABILITIES__H
#define STATE__ABILITIES__H

#include <string>

namespace state {

  /// class Abilities - 
  class Abilities {
    // Attributes
  private:
    std::string name_ability;
    int degats_ability;
    int classOwner_ability;
    // Operations
  public:
    Abilities (std::string const name, int const degats, int const owner);
     ~Abilities ();
    std::string const getName ();
    int const getDegats ();
    int const getClassOwner ();
    void const afficheStats ();
    // Setters and Getters
  };

};

#endif
