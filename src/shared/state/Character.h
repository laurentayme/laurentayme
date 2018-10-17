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
  protected:
    std::string characterClass;
    size_t pv;
    size_t pm;
    size_t pa;
    std::vector<Equipment*> equipment_List;
    std::vector<Abilities*> abilities_List;
    size_t statut;
    size_t direction;
    bool  player;
    // Operations
  public:
    Character (std::string characterClass);
     ~Character ();
    std::string const getClass ();
    size_t const getPV ();
    void setPV (size_t pv);
    size_t const getPA ();
    void setPA (size_t pa);
    size_t const getPM ();
    void setPM (size_t pm);
    std::vector<Equipment*> const getEquipmentList ();
    void addEquipment (std::string nom, std::string emplacement, size_t degats);
    void addEquipment (Equipment* equipment);
    void removeEquipment (Equipment* equipment);
    bool const isEquipped (Equipment* equipment_ptr);
    size_t const getStatut ();
    std::vector<Abilities*> const getAbilitiesList ();
    size_t const getDirection ();
    void setDirection (size_t direction);
    bool const isPlayer ();
    void affiche_Classe ();
    void const affiche_Stats ();
    void const affiche_EquipmentList ();
    virtual void const affiche_AbilitiesList ();
    // Setters and Getters
    const std::string& getCharacterClass() const;
    void setCharacterClass(const std::string& characterClass);
    const size_t& getPv() const;
    void setPv(const size_t& pv);
    const size_t& getPm() const;
    void setPm(const size_t& pm);
    const size_t& getPa() const;
    void setPa(const size_t& pa);
    const std::vector<Equipment*>& getEquipment_List() const;
    void setEquipment_List(const std::vector<Equipment*>& equipment_List);
    const std::vector<Abilities*>& getAbilities_List() const;
    void setAbilities_List(const std::vector<Abilities*>& abilities_List);
    void setStatut(const size_t& statut);
    const bool & getPlayer() const;
    void setPlayer(const bool & player);
  };

};

#endif