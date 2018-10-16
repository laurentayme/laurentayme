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

bool const Wall::isWall(){
    return(wall);
}

bool const Wall::isObstacle(){
    return(obstacle);
}

void Wall::affiche_Classe(){
    std::cout<<"Je suis un Wall."<<std::endl;
}






