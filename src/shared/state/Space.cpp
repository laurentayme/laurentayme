//
//  Space.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"

using namespace state;

Space::Space(int space){
    spaceType=space;
    obstacle=false;
}

int const Space::getSpaceType(){
    return(spaceType);
}

bool const Space::isObstacle(){
    return(obstacle);
}
