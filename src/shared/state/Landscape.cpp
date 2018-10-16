//
//  Landscape.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"

using namespace state;

Landscape::Landscape(){
    obstacle=true;
    wall=false;
}

bool const Landscape::isWall(){
    return(wall);
}

bool const Landscape::isObstacle(){
    return(obstacle);
}
