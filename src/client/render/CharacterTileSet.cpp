/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>

using namespace render;

CharacterTileSet::CharacterTileSet(){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            Tile t(i*181,j*309,181,309);
            iop.push_back(t);
            sadida.push_back(t);
        }
        
    }
}

CharacterTileSet::~CharacterTileSet(){
}

std::string const CharacterTileSet::getImageFile(){
    return("res/Character_Tileset.png");
}

const Tile& CharacterTileSet::getTile(const state::Element& e) {
    //Cas d'un Character
    if (e.getTypeId()==1){ 
        // Cas d'un Iop
        if (e.getClass()=="Iop"){
                Tile& s=iop[9];
                
                if(e.getDirection()==1){ //North
                    s=iop[9];
                    return(s);
                }
                
                else if(e.getDirection()==2){ //West
                    s=iop[2];
                    return(s);
                }
                    
                    
                else if(e.getDirection()==3){ //South
                    s=iop[0];
                    return(s);
                }
                
                else if(e.getDirection()==4){ //East
                    s=iop[1];
                    return(s);
                }
            }
        }
            // Cas d'un Landscape
    // Cas d'un Character
    else{
        throw "This is not a StaticElement !"; 
    }
}

int const CharacterTileSet::getCellWidth() const{
              return(181/1.75);
}
int const CharacterTileSet::getCellWidth(state::Element& elmt) const{
              return(181/1.75);
}

int const CharacterTileSet::getCellHeight() const{
            return(306/1.75);

}

int const CharacterTileSet::getCellHeight(state::Element& elmt) const{
            return(306/1.75);

}
