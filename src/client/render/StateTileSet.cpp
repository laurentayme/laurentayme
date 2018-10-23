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

int const StateTileSet::getCellWidth(const state::Element& e) const{
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

int const StateTileSet::getCellHeight(const state::Element& e) const{
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