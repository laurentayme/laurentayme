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
            Tile t(i*181,j*306,181,306);
            iop.push_back(t);
            sadida.push_back(t);
        }
        
    }
}

CharacterTileSet::~CharacterTileSet(){
}

std::string const CharacterTileSet::getImageFile(){
    return("/home/vincent/cloneplt/laurentayme/res/Character_Tileset.png");
}

const Tile& CharacterTileSet::getTile(const state::Element& e) {
    //Cas d'un Character
    if (e.getTypeId()==1){ 
        // Cas d'un Iop
        if (e.getClass()=="Iop"){
                Tile& s=iop[0];
                
                if(e.getDirection()==1){ //North
                    s=iop[3];
                    return(s);
                }
                
                else if(e.getDirection()==2){ //East
                    s=iop[4];
                    return(s);
                }
                    
                    
                else if(e.getDirection()==3){ //South
                    s=iop[0];
                    return(s);
                }
                
                else if(e.getDirection()==4){ //South
                    s=iop[8];
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

int const CharacterTileSet::getCellWidth(const state::Element& e) const{
    // Cas d'un Character
    if (e.getTypeId()==1){ 
        // Cas d'un Iop
        if(e.getClass()=="Iop"){
            return(181);
        }
        else if (e.getClass()=="Sadida"){
            return(181);
        }
    }
    else{
        throw "Ceci est un StaticElement !";
    }
}

int const CharacterTileSet::getCellHeight(const state::Element& e) const{
    // Cas d'un Character
    if (e.getTypeId()==1){ 
        // Cas d'un Iop
        if(e.getClass()=="Iop"){
            return(306);
        }
        else if (e.getClass()=="Sadida"){
            return(306);
        }
    }
    else{
        throw "Ceci est un StaticElement !";
    }
}
