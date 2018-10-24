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





