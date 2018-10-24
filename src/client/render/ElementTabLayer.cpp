#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace render;

ElementTabLayer::ElementTabLayer (const state::ElementTab& tab) : tab(tab) {
    std::vector<state::Element*> list =tab.getElementList();
    if (list[0]->getTypeId()==0){
        tileset.reset(new MapTileSet);
    }
    else{
        tileset.reset(new CharacterTileSet);
    }
    
}

void ElementTabLayer::initSurface(int count){
    
    surface->initQuads(count);
    //surface->loadTexture(tileset->getImageFile());
    
    
    
    /*for(int i=0; i<t->size();i++){
        setSpriteLocation();
        setSpriteTexture();
    }*/
}

    

/*ElementTabLayer::~ElementTabLayer(){

}*/
