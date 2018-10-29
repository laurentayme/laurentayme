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
    
    for(int i=0;i<2;i++){
        Tile t(149*4+(149-86)/2,86*6,86,86);
        landscape.push_back(t);
    }
    
    Tile t1(149*4+(149-61)/2,(86*7)+146,61,146);
    wall.push_back(t1);
            
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

int const MapTileSet::getCellWidth(state::Element& elmt) const{
    if (elmt.isObstacle()==true){
        if(elmt.isWall()==true){
            return(61);
        }
        else{//Landscape
            return(86/1.26);
        }
        
    }
    else{//Space
        return(149/1.25);
    }
                
}


int const MapTileSet::getCellHeight(state::Element& elmt) const{
    if (elmt.isObstacle()==true){
        if(elmt.isWall()==true){
            return(146);
        }
        else{//Landscape
            return(86/1.26);
        }
    }
    else{//Space
        return(75/1.25);
    }
}


       
