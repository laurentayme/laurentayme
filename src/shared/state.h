#include <vector>
namespace state {

  /// class Position - 
  class Position {
    // Attributes
  public:
    int x;
    int y;
  };

  /// class TypeId - 
  class TypeId {
    // Attributes
  public:
    int obstacle;
    int space;
    int character;
  };

  /// class Element - 
  class Element {
    // Associations
    state::TypeId* unnamed;
    state::Position* unnamed;
    // Attributes
  public:
    Position position;
    TypeId typeid;
    // Operations
  public:
    Element ();
    bool const isStatique ();
    void const getTypeId ();
    void setTypeId (TypeId typeid);
  };

  /// class Direction - 
  class Direction {
    // Attributes
  public:
    int North;
    int East;
    int South;
    int West;
  };

  /// class CharacterClass - 
  class CharacterClass {
    // Attributes
  public:
    int iop;
    int sadida;
    int sram;
    int pandawa;
    int cra;
    int fantome;
  };

  /// class Equipment - 
  class Equipment {
    // Attributes
  public:
    std::string cape;
    std::string casque;
     ;
     ;
     ;
     ;
  };

  /// class CharacterStatut - 
  class CharacterStatut {
    // Attributes
  public:
    int normal;
    int poisoned;
    int dead;
  };

  /// class Abilities - 
  class Abilities {
    // Attributes
  public:
    std::vector<std::string> iopAbilities;
    std::vector<std::string> sadidaAbilities;
    std::vector<std::string> sramAbilities;
    std::vector<std::string> pandawaAbilities;
    std::vector<std::string> craAbilities;
    std::vector<std::string> fantomeAbilities;
  };

  /// class Stats - 
  class Stats {
    // Attributes
  public:
    std::vector<int> iopStats;
    std::vector<int> sadidaStats;
    std::vector<int> sramStats;
    std::vector<int> pandawaStats;
    std::vector<int> craStats;
    std::vector<int> fantomeStats;
  };

  /// class MobileElement - 
  class MobileElement : public Element {
    // Associations
    state::Equipment* unnamed;
    state::Direction* unnamed;
    state::CharacterStatut* unnamed;
    state::Abilities* unnamed;
    state::Stats* unnamed;
    state::CharacterClass* unnamed;
    // Attributes
  public:
    Direction direction;
    std::vector<Stats> stats;
    std::vector<Abilities> abilities;
    std::vector<Equipment> equipment;
    // Operations
  public:
    MobileElement ();
    bool const isPlayer ();
    bool const isStatic ();
    void getCharacterClass (CharacterClass selectedClass);
    void getStats (CharacterClass character, std::vector<Stats> stats);
    void getAbilities (CharacterClass character, std::vector<Abilities> abilities);
    void getEquipment (std::vector<Equipment> equiment);
    void setCharacterClass (CharacterClass characterclass);
  };

  /// class StaticElement - 
  class StaticElement : public Element {
    // Operations
  public:
    bool const isStatic ();
    bool const isObsctacle ();
  };

  /// class Obstacle - 
  class Obstacle : public StaticElement {
    // Operations
  public:
    Obstacle ();
    bool const isObstacle ();
    bool const isWall ();
    void const getTypeId ();
  };

  /// class Wall - 
  class Wall : public Obstacle {
    // Operations
  public:
    Wall ();
    bool const isWall ();
  };

  /// class Landscape - 
  class Landscape : public Obstacle {
    // Operations
  public:
    Landscape ();
    bool const isObstacle ();
    void const getTypeId ();
  };

  /// class SpaceTypeId - 
  class SpaceTypeId {
    // Attributes
  public:
    int Empty;
    int Start;
    int Trap;
  };

  /// class Space - 
  class Space : public StaticElement {
    // Associations
    state::SpaceTypeId* unnamed;
    // Operations
  public:
    Space (SpaceTypeId id);
    bool const isSpace ();
    void const getTypeId (TypeId typeid);
    void const getSpaceTypeId (SpaceTypeId spacetypeid);
    void setSpaceTypeId (SpaceTypeId id);
  };

  /// class ElementTab - 
  class ElementTab {
    // Attributes
  private:
    size_t Width;
    size_t height;
    std::vector<Element> elementList;
    // Operations
  public:
    ElementTab (size_t width, size_t height);
    size_t const getHeight ();
    size_t const getWidth ();
    Element* const getElement (Position position);
    void setElement (Position position, Element* element*);
    void resize (size_t width, size_t height);
    size_t addElement (Element* e);
  };

  /// class State - 
  class State {
    // Associations
    state::ElementTab* unnamed;
    // Attributes
  public:
    int deadcount;
  private:
    ElementTab map;
    ElementTab characters;
    // Operations
  public:
    ElementTab& getGrid ();
    ElementTab getCharacters ();
  };

};

