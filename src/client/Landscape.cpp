//
//  Landscape.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Landscape::Landscape(){
    obstacle=true;
    wall=false;
}

bool const Landscape::isWall() const {
    return(wall);
}

bool const Landscape::isObstacle() const {
    return(obstacle);
}

void Landscape::affiche_Classe(){
    std::cout<<"Je suis un Landscape."<<std::endl;
}

std::string const Landscape::getClass() const{
    return("None");
}

size_t const Landscape::getDirection() const{
    return(0);
}

size_t const Landscape::getSpaceType() const {
	return 0;
}

