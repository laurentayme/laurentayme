// Generated by dia2code
#ifndef RENDER__MAPTILESET__H
#define RENDER__MAPTILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class MapTileSet - 
  class MapTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<Tile> wall;
    std::vector<Tile> space;
    std::vector<Tile> landscape;
    // Operations
  public:
    MapTileSet ();
    ~MapTileSet ();
    int const getCellWidth () const;
    std::string const getImageFile ();
    const Tile&  getTile (const state::Element& e);
    int const getCellHeight () const;
    // Setters and Getters
  };

};

#endif
