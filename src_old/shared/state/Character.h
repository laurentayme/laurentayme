// Generated by dia2code
#ifndef STATE__CHARACTER__H
#define STATE__CHARACTER__H

#include <string>
#include <stdlib.h>
#include <vector>

namespace state {
  class Equipment;
  class Element;
}

#include "Element.h"
#include "Equipment.h"

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
    size_t statut;
    bool  player;
    size_t team;
    // Operations
  public:
    Character (std::string characterClass);
     ~Character ();
    std::string getClass () const;
    size_t getPV () const;
    void setPV (int pv);
    size_t getPA () const;
    void setPA (int pa);
    size_t getPM () const;
    void setPM (int pm);
    std::vector<Equipment*> const getEquipmentList ();
    void addEquipment (std::string nom, std::string emplacement, size_t degats);
    void addEquipment (Equipment* equipment);
    void removeEquipment (Equipment* equipment);
    bool isEquipped (Equipment* equipment_ptr) const;
    int getStatut () const;
    void setStatut (int act_statut);
    std::vector<Abilities*>  getAbilitiesList ();
    size_t getDirection () const;
    void setDirection (size_t direction);
    bool  isPlayer () const;
    void affiche_Classe ();
    void affiche_Stats () const;
    void affiche_EquipmentList () const;
    virtual void  affiche_AbilitiesList () const;
    void afficheStatut () const;
    bool isObstacle () const;
    bool isWall () const;
    size_t getSpaceType () const;
    int getWallType () const;
    int getLandscapeType () const;
    size_t getTypeId () const;
    size_t getTeam () const;
    void setTeam (size_t team);
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
    const bool & getPlayer() const;
    void setPlayer(const bool & player);
  };

};

#endif