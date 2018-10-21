// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>

namespace render {
  class Surface;
  class TileSet;
}

#include "Surface.h"
#include "TileSet.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    std::unique_ptr<Surface> surface;
    std::shared_ptr<TileSet> tileset;
    // Operations
  public:
    Layer ();
    virtual ~Layer ();
    const Surface* const getSurface ();
    void setSurface (Surface* surface);
    virtual void initSurface () = 0;
    // Setters and Getters
    const std::shared_ptr<TileSet>& getTileset() const;
    void setTileset(const std::shared_ptr<TileSet>& tileset);
  };

};

#endif
