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

MapTileSet::MapTileSet(){
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            Tile t(149*j,86*i,149,86);
            space.push_back(t);
        }
    }
    
    Tile t(149*4.25,86*6,86,86);
    wall.push_back(t);
    
    for(int i=0;i<8;i++){
        for(int j=0;j<9;j++){
            Tile t(149*j,86*i,86,86);
            landscape.push_back(t);
            
        }
    }
}

MapTileSet::~MapTileSet(){
}

std::string const MapTileSet::getImageFile(){
    return("res/Map_Tileset.png");
}


const Tile& MapTileSet::getTile(const state::Element& e){  
    //Cas d'un StaticElement
    if (e.getTypeId()==0){ 
        // Cas d'un Obstacle
        if (e.isObstacle()==true){
            // Cas d'un Mur
            if(e.isWall()==true){
                Tile& s=wall[0];
                return(s);
            }
            // Cas d'un Landscape
            else{
                Tile& s=landscape[0];
                return(s);
            }
        }
        // Cas d'un Space
        else if(e.getSpaceType()==0){	
		Tile& s=space[16];
            return(s);
        }
        
        else if(e.getSpaceType()==1){	
		Tile& s=space[0];
            return(s);
        }
	else if(e.getSpaceType()==2){
		Tile& s=space[9];
	return(s);
	}
   }
    // Cas d'un Character
    else{
        throw "This is not a StaticElement !"; 
    }
}

int const MapTileSet::getCellWidth() const{
                
                return(149/1.25);
            }


int const MapTileSet::getCellHeight() const{
                return(86/1.25);
            }


       
