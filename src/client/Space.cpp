//
//  Space.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Space::Space(size_t space){
    if (space>=0 && space <=4){
        spaceType=space;
        obstacle=false;
    }
    else{
        throw "Type de Space Incorrect ! (1=Empty, 2=Start, 3=Trap et 4=RedSpace)";
    }
}

size_t const Space::getSpaceType() const{
    return(spaceType);
}

bool const Space::isObstacle() const{
    return(obstacle);
}

void Space::affiche_Classe(){
    std::cout<<"Je suis un Space."<<std::endl;
}

bool const Space::isWall() const {
    return(false);
}

std::string const Space::getClass() const{
    return("None");
}

size_t const Space::getDirection() const{
    return(0);
}

int Space::getWallType() const{
    return 0;
}

int Space::getLandscapeType() const{
    return(-1);
}

void Space::setDirection (size_t direction){
	std::cout<<"Un espace n'a pas de direction"<<std::endl;
}

std::vector<Abilities*> Space::getAbilitiesList() const {
    std::vector<Abilities*> list;
	return(list);
}

size_t Space::getPV() const{
	return(1);
}

size_t Space::getPA() const{
	return(1);
}

size_t Space::getPM() const{
	return(1);
}
