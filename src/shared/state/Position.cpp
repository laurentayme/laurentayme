//
//  Position.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 10/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"

using namespace state;

//Constructeur
Position::Position(size_t abs, size_t ord){
    x=abs;
    y=ord;
}

//Affectation position X
void Position::setX(size_t abs){
    x=abs;
}

//Affectation position Y
void Position::setY(size_t ord){
    y=ord;
}

size_t const Position::getX(){
    return(x);
}

size_t const Position::getY(){
    return(y);
}







