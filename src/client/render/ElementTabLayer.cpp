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

void ElementTabLayer::initSurface(){
    
    std::vector<state::Element*> list= tab.getElementList();
    
    surface->initQuads(list.size());
    surface->loadTexture(tileset->getImageFile());
 
    //Boucle sur l'ensemble des éléments d'un ElementTab
    for(int i=0; i<list.size(); i++){
        state::Element& e=*list[i];
        const Tile& t=tileset->getTile(e);
	TileSet& tileSet2= *tileset;
     	surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2);
        surface->setSpriteTexture(i,t);
    }
}
