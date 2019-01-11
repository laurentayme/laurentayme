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
            Tile t(i*400,j*680,370,680);
            iop.push_back(t);

        }
    }

    for(int j=0;j<3;j++){
        Tile t_sram(370*4+90,684*j,317,684);
        sadida.push_back(t_sram);
    }

    Tile t_sram2(370*4+90+317,0,317,684);
    Tile t_sram22(370*4+90+317,684,317,684);
    sadida.push_back(t_sram2);
    sadida.push_back(t_sram22);
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
            
            
                Tile& s=iop[3];

                if(e.getDirection()==1){ //North
                    if(e.getMoving()==1){
                        s=iop[10];
                        return(s);
                    }
                    else{
                        s=iop[9];
                        return(s);
                    }
                    
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
                    if(e.getMoving()==true){
                        s=iop[5];
                       return(s);   
                    }
                    else{
                       s=iop[1];
                       return(s); 
                    }
                    
                }
            }

    	else if (e.getClass()=="Sram"){
        Tile& s=sadida[4];
        	if(e.getDirection()==1){ //North
                    s=sadida[3];
                    return(s);
                }

       		else if(e.getDirection()==2){ //West
                    s=sadida[2];
                    return(s);
                }

                else if(e.getDirection()==3){ //South
                    s=sadida[0];
                    return(s);
                }

                else if(e.getDirection()==4){ //East
                    s=sadida[0];
                    return(s);
                }

    }
    }

    // Cas d'un Landscape
    else{
        throw "This is not a StaticElement !";
    }
}

int const CharacterTileSet::getCellWidth() const{
              return(181/1.75);
}
int const CharacterTileSet::getCellWidth(state::Element& elmt) const{
    if(elmt.getClass()=="Iop"){
        return(160/1.75);
    }
    else if (elmt.getClass()=="Sram"){
        return(135/1.75);
    }

}

int const CharacterTileSet::getCellHeight() const{
            return(306/1.75);

}

int const CharacterTileSet::getCellHeight(state::Element& elmt) const{
            if(elmt.getClass()=="Iop"){
        return(266/1.75);
    }
    else if (elmt.getClass()=="Sram"){
        return(266/1.75);
    }

}
