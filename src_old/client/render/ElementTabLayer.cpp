#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

using namespace render;


ElementTabLayer::ElementTabLayer (state::ElementTab& tab) : tab(tab) {
    std::vector<state::Element*> list = tab.getElementList();
    if (list[0]->getTypeId()==0){
        tileset.reset(new MapTileSet);
    }
    else if (list[0]->getTypeId()==1){
        tileset.reset(new CharacterTileSet);
    }

    else if (list[0]->getTypeId()>=2){
        tileset.reset(new StateTileSet);
    }

}

void ElementTabLayer::initSurface(){

    std::vector<state::Element*> list= tab.getElementList();

    surface->initQuads(list.size());
    surface->loadTexture(tileset->getImageFile());

    //Boucle sur l'ensemble des éléments d'un ElementTab
    for(size_t i=0; i<list.size(); i++){
        state::Element& e=*list[i];
        const Tile& t=tileset->getTile(e);
	      TileSet& tileSet2= *tileset;

        surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
        surface->setSpriteTexture(i,t,tab);

    }
}

void ElementTabLayer::stateChanged(const state::Event& event){
    std::vector<state::Element*> list= tab.getElementList();
    //Boucle sur l'ensemble des éléments d'un ElementTab
    for(size_t i=0; i<list.size(); i++){
        state::Element& e=*list[i];
        
        const Tile& t=tileset->getTile(e);
        TileSet& tileSet2= *tileset;

        //std::cout<<"1st Step !"<<std::endl;
        //Cas des Character//
        if(e.getTypeId()==1){
            //std::cout<<"2nd Step !"<<std::endl;
            if(e.getStatut()!=3){
               surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
               surface->setSpriteTexture(i,t,tab); 
            }
            
        }
        

        else{
            surface->setSpriteLocation(i,e.getPosition().getX(),e.getPosition().getY(),tileSet2,tab);
            surface->setSpriteTexture(i,t,tab);
        }
        
        
        



    }
}

state::ElementTab& ElementTabLayer::getTab() const{
    return(tab);
}
