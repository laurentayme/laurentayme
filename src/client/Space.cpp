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
    if (space>=1 && space <=3){
        spaceType=space;
        obstacle=false;
    }
    else{
        throw "Type de Space Incorrect ! (1=Empty, 2=Start et 3=Trap)";
    }
}

size_t const Space::getSpaceType(){
    return(spaceType);
}

bool const Space::isObstacle() const{
    return(obstacle);
}

void Space::affiche_Classe(){
    std::cout<<"Je suis un Space."<<std::endl;
}
