//
//  Wall.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Wall::Wall(){
    obstacle=true;
    wall=true;
    wallType=1;
}

bool const Wall::isWall() const {
    return(true);
}

bool const Wall::isObstacle() const {
    return(true);
}

void Wall::affiche_Classe(){
    std::cout<<"Je suis un Wall."<<std::endl;
}

std::string const Wall::getClass() const{
    return("None");
}

size_t const Wall::getDirection() const{
    return(0);
}


size_t const Wall::getSpaceType() const {
	return 0;
}

int Wall::getWallType() const{
    return wallType;
}

void Wall::setWallType(int wall_type) {
    if(wall_type==1 || wall_type==2){
        wallType=wall_type;
    }
    else{
        throw "Incorrect Wall Type !";
    }
    
}

int Wall::getLandscapeType() const{
    return(-1);
}


void Wall::setDirection(size_t direction){
	std::cout<<"Un mur n'a pas de direction"<<std::endl;
}


std::vector<Abilities*> Wall::getAbilitiesList() const {
    std::vector<Abilities*> list;
	return(list);
}

size_t Wall::getPV() const{
	return(1);
}

size_t Wall::getPA() const{
	return(1);
}

size_t Wall::getPM() const{
	return(1);
}

