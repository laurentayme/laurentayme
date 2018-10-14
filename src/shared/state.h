#include<vector>
namespace state {

  /// class Position - 
  class Position {
    // Attributes
  public:
    int x;
    int y;
    // Operations
  public:
    Position ();
  };

  /// class TypeId - 
  class TypeId {
    // Attributes
  public:
    int obstacle;
    int space;
    int character;
    // Operations
  public:
    TypeId ();
    TypeId const getTypeId ();
    void setTypeId ();
  };

  /// class Direction - 
  class Direction {
    // Attributes
  public:
    int North;
    int East;
    int South;
    int West;
    // Operations
  public:
    Direction ();
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
    // Operations
  public:
    CharacterClass ();
  };

  /// class MobileElement - 
  class MobileElement {
    // Attributes
  public:
    int characterClass;
    int characterStatut;
    std::vector<Stats> stats;
    std::vector<Abilities> abilities;
    Direction direction;
    std::vector<Equipment> equipment;
    // Operations
  public:
    MobileElement ();
    bool const isPlayer ();
    void setCharacterClass (CharacterClass characterclass);
    void getCharacterClass (CharacterClass selectedClass);
    void setCharacterStatut (int statut);
    int const getCharacterStatut ();
    void setStats (std::vector<Stats> stats);
    std::vector<Stats> getStats (std::vector<Stats> stats);
    void setAbilities (std::vector<Abilities> abilities);
    void getAbilities (std::vector<Abilities> abilities);
    void setEquipment (std::vector<Equipment> equipment);
    void getEquipment (std::vector<Equipment> equiment);
    void setDirection (int direction);
    int getDirection ();
  };

  /// class Element - 
  class Element {
    // Associations
    state::TypeId* unnamed;
    state::Position* unnamed;
    // Attributes
  public:
    Position position;
    TypeId idType;
    MobileElement mobileElement;
    // Operations
  public:
    Element ();
    int const getTypeId (TypeId idtype);
    void setTypeId (TypeId idtype);
    Position getPosition ();
    void setPosition (Position position);
  };

  /// class StaticElement - 
  class StaticElement : public Element {
    // Operations
  public:
    StaticElement ();
    bool const isObsctacle ();
  };

  /// class Obstacle - 
  class Obstacle : public StaticElement {
    // Operations
  public:
    Obstacle ();
    bool const isWall ();
  };

  /// class Wall - 
  class Wall : public Obstacle {
    // Operations
  public:
    Wall ();
  };

  /// class Landscape - 
  class Landscape : public Obstacle {
    // Operations
  public:
    Landscape ();
  };

  /// class SpaceTypeId - 
  class SpaceTypeId {
    // Attributes
  public:
    int Empty;
    int Start;
    int Trap;
    // Operations
  public:
    SpaceTypeId ();
  };

  /// class Space - 
  class Space : public StaticElement {
    // Associations
    state::SpaceTypeId* unnamed;
    // Operations
  public:
    Space (SpaceTypeId id);
    bool const isSpace ();
    TypeId const getTypeId (TypeId idtype);
    SpaceTypeId const getSpaceTypeId (SpaceTypeId spacetypeid);
    void setSpaceTypeId (SpaceTypeId id);
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
    // Operations
  public:
    Stats ();
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
    // Operations
  public:
    Abilities ();
  };

  /// class CharacterStatut - 
  class CharacterStatut {
    // Attributes
  public:
    int normal;
    int poisoned;
    int dead;
    // Operations
  public:
    CharacterStatut ();
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
    // Operations
  public:
    Equipment ();
  };

  /// class ElementTab - 
  class ElementTab {
    // Attributes
  private:
    /// Largeur de la Map
    size_t Width;
    /// Longueur de la Map
    size_t height;
    std::vector<Element> elementList;
    // Operations
  public:
    ElementTab (size_t width, size_t height, std::vector<Element> elementsList);
    size_t const getHeight ();
    size_t const getWidth ();
    element* const getElement (Position position);
    void setElement (Position position, Element* element_ptr);
    void resize (size_t width, size_t height);
    void addElement (Element* e);
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
    // Operations
  public:
    State ();
    ElementTab& getMap ();
  };

};

