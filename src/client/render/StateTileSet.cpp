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


StateTileSet::StateTileSet(){
    Tile t(0,0,1490,1053);
    state.push_back(t);
   
}

int const StateTileSet::getCellWidth(state::Element& elmt) const{
    return(1490);
}

int const StateTileSet::getCellHeight(state::Element& elmt) const{
    return(1053);
}

std::string const StateTileSet::getImageFile(){
    return("res/State_Tileset.png");
}

StateTileSet::~StateTileSet(){
}

const Tile& StateTileSet::getTile(const state::Element& e){ 
    Tile& s=state[0];
    return(s);
}
