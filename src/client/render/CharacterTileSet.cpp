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

std::string const CharacterTileSet::getImageFile(const state::Element& e){
    //Vérification Character
    if (e.getTypeId()==1){
        //Cas d'un Iop
        if (e.getClass()=="Iop"){ 
            return("/home/valentin/laurentayme/res/Iop_Tileset.png");
        }
        // Cas d'un Sadida
        else if (e.getClass()=="Sadida"){
            return("/home/valentin/laurentayme/res/Sadida_Tileset.png");
        }
    }
    // Cas d'un StaticElement
    else{
        throw "This is not a Character !"; 
    }
}

const Tile& CharacterTileSet::getTile(const state::Element& e,int i) {
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