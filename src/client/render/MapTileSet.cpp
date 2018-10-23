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

/*
int const MapTileSet::getCellHeight() const {
    return(0);
}*/

/*int const MapTileSet::getCellWidth() const {
    return(0);
}*/

std::string const MapTileSet::getImageFile(const state::Element& e){
    //Vérification StaticElement
    if (e.getTypeId()==0){ 
        // Cas d'un Obstacle
        if (e.isObstacle()==true){
            return("/home/valentin/laurentayme/res/Obstacle_Tileset.png");
        }
        // Cas d'un Space
        else{
            return("/home/valentin/laurentayme/res/Space_Tileset.png");
        }
    }
    // Cas d'un Character
    else{
        throw "This is not a StaticElement !"; 
    }
}


const Tile& MapTileSet::getTile(const state::Element& e,int i){
    
    //Cas d'un StaticElement
    if (e.getTypeId()==0){ 
        // Cas d'un Obstacle
        if (e.isObstacle()==true){
            // Cas d'un Mur
            if(e.isWall()==true){
                Tile& s=wall[i];
                return(s);
            }
            // Cas d'un Landscape
            else{
                Tile& s=landscape[i];
                return(s);
            }
        }
        // Cas d'un Space
        else{
            Tile& s=space[i];
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

       