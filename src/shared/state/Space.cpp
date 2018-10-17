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
    spaceType=space;
    obstacle=false;
}

size_t const Space::getSpaceType(){
    return(spaceType);
}

bool const Space::isObstacle(){
    return(obstacle);
}

void Space::affiche_Classe(){
    std::cout<<"Je suis un Space."<<std::endl;
}
