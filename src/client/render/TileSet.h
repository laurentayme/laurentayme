// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H

#include <string>

namespace render {
  class Tile;
}

#include "Tile.h"

namespace render {

  /// class TileSet - 
  class TileSet {
    // Associations
    // Operations
  public:
    TileSet ();
    virtual ~TileSet ();
    virtual int const getCellWidth () = 0;
    virtual int const getCellHeight () = 0;
    virtual std::string const getImageFile () = 0;
    const Tile& getTile (const state::Element& e);
    const Tile& getCharTile (char c);
    // Setters and Getters
  };

};

#endif