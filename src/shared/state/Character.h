// Generated by dia2code
#ifndef STATE__CHARACTER__H
#define STATE__CHARACTER__H

#include <string>
#include <stdlib.h>
#include <vector>

namespace state {
  class Equipment;
  class Abilities;
  class Element;
}

#include "Element.h"
#include "Equipment.h"
#include "Abilities.h"

namespace state {

  /// class Character - 
  class Character : public state::Element {
    // Associations
    // Attributes
  private:
    std::string characterClass;
    size_t pv;
    size_t pm;
    size_t pa;
    std::vector<Equipment*> equipment_List;
    std::vector<Abilities*> abilities_List;
    int statut;
    size_t direction;
    bool  player;
    // Operations
  public:
    Character (std::string characterClass);
     ~Character ();
    std::string const getClass ();
    int const getPV ();
    void setPV (int pv);
    int const getPA ();
    void setPA (int pa);
    int const getPM ();
    void setPM (int pm);
    std::vector<Equipment*> const getEquipmentList ();
    void addEquipment (std::string nom, std::string emplacement, int degats);
    void addEquipment (Equipment* equipment);
    void removeEquipment (Equipment* equipment);
    bool const isEquipped (Equipment* equipment_ptr);
    int const getStatut ();
    void setStatut (int act_statut);
    std::vector<Abilities*> const getAbilitiesList ();
    int const getDirection ();
    void setDirection (int direction);
    bool const isPlayer ();
    void const affiche_Classe ();
    void const affiche_Stats ();
    void const affiche_EquipmentList ();
    void const affiche_AbilitiesList ();
    void afficheStatut ();
    // Setters and Getters
  };

};

#endif
