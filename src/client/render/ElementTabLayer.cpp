#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <memory>

using namespace render;

ElementTabLayer::ElementTabLayer (const state::ElementTab& tab) : tab(tab) {
    std::vector<state::Element*> list = tab.getElementList();
    if (list[0]->getTypeId()==0){
        tileset.reset(new MapTileSet);
    }
    else if (list[0]->getTypeId()==1){
        tileset.reset(new CharacterTileSet);
    }
    
    else if (list[0]->getTypeId()==2){
        tileset.reset(new StateTileSet);
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
        
        //Cas d'un Character
        if(e.getTypeId()==1){
        float abs=(e.getPosition().getX()/t.getWidth())*(149/1.25);
        float ord=(e.getPosition().getY()/t.getHeight())*(149/1.25);
            
        surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
           
        }
        //Cas du décors
        else{
     	surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
        }
        surface->setSpriteTexture(i,t,tab);
        
    }
}
