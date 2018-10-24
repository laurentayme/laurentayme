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
    return(3508);
}

int const StateTileSet::getCellHeight(const state::Element& e) const{
    return(2479);
}

std::string const StateTileSet::getImageFile(){
    return("/home/valentin/laurentayme/res/State_Tileset.png");
}

