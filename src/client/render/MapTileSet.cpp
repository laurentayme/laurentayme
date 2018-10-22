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


int const MapTileSet::getCellHeight(std::vector<Tile> mapset){
    return(mapset[0].getHeight()*mapset.size());
}

int const MapTileSet::getCellWidth(std::vector<Tile> mapset){
    return(mapset[0].getWidth()*mapset.size());
}

std::string const MapTileSet::getImageFile(std::vector<Tile> mapset){
    
}
/*
const Tile& MapTileSet::getTile(const state::Element& e){
    
    //Cas d'un StaticElement
    if (e.getIdType()==0){ 
        // Cas d'un Obstacle
        if (e.isObstacle()==true){
            // Cas d'un Mur
            if(e.isWall()==true){
                
            }
            // Cas d'un Landscape
            else{
                
            }
        }
        // Cas d'un Space
        else{
            
        }
        
    }
    // Cas d'un Character
    else {
        //Obtention de la classe du personnage
        if (e.getClass()=="Iop"){
            //Obtention de la direction du personnage
            switch(e.getDirection()){
                case(1): //Direction = North    
                    break;
                
                case(2): //Direction ==East
                    break;
                 
                case(3): //Direction ==South
                    break;
                    
                case(4): //Direction ==West
                    break;
                
            }
            
        }
    }
}
*/