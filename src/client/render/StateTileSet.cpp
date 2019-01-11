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
    Tile t(0,0,1996,1412);
    state.push_back(t);
    
    Tile t_StartMenu(0,1753,2305,2178);
    state.push_back(t_StartMenu);
    
    Tile t_StartMenu_1(0,3928,2305,2171);
    state.push_back(t_StartMenu_1);
    
    Tile t_StartMenu_2(0,6093,2305,2168);
    state.push_back(t_StartMenu_2);
    
    Tile t_EndMenu(0,8276,2305,2178);
    state.push_back(t_EndMenu);
   
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

    //Cas d'un Main Menu
    if(e.getTypeId()==3){
        Tile& s=state[1];
        return(s);
    }
    
    else if(e.getTypeId()==4){
        Tile& s=state[2];
        return(s);
    }
    
    else if(e.getTypeId()==5){
        Tile& s=state[3];
        return(s);
    }
    
    else if(e.getTypeId()==6){
        Tile& s=state[4];
        return(s);
    }
    
    //Cas d'un Battle Menu
    else if(e.getTypeId()==2){
       Tile& s=state[0];
       return(s); 
    }
   
}
