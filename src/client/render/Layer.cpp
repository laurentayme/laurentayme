#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>

using namespace render;

Layer::Layer(){
    surface.reset(new Surface);
    
}

Layer::~Layer(){

}

std::unique_ptr<Surface> const& Layer::getSurface(){
    //Surface surf = *surface;
    //const Surface* const s=&surf;
    return(surface);
}

void Layer::setSurface(Surface* surface){
    //this->surface.reset(*surface);
}
