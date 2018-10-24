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
