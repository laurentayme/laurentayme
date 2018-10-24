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
            Tile t(149*i,86*j,149,86);
            space.push_back(t);
        }
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            Tile t(149*i,86*j,149,86);
            landscape.push_back(t);
            wall.push_back(t);
        }
    }
}

MapTileSet::~MapTileSet(){
}

std::string const MapTileSet::getImageFile(){
    return("/home/valentin/laurentayme/res/Map_Tileset.png");
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
        else{
            Tile& s=space[0];
            return(s);
        }
    }
    // Cas d'un Character
    else{
        throw "This is not a StaticElement !"; 
    }
}

int const MapTileSet::getCellWidth(const state::Element& e) const{
    // Cas d'un Character
    if (e.getTypeId()==0){ 
        // Cas d'un Iop
        if(e.isObstacle()==true){ // Cas d'un Landscape ou Wall
            return(149);
        }
        else { //Cas d'un Space
                return(149);
            }
            
    }
    else{
        throw "Ceci est un Character !";
    }
}

int const MapTileSet::getCellHeight(const state::Element& e) const{
    // Cas d'un Character
    if (e.getTypeId()==0){ 
        // Cas d'un Iop
        if(e.isObstacle()==true){ // Cas d'un Landscape ou Wall
            return(86);
        }
        else { //Cas d'un Space
                return(86);
            }
            
    }
    else{
        throw "Ceci est un Character !";
    }
}

       