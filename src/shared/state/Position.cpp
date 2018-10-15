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
Position::Position(int abs, int ord){
    x=abs;
    y=ord;
}

//Affectation position X
void Position::setX(int abs){
    x=abs;
}

//Affectation position Y
void Position::setY(int ord){
    y=ord;
}

int const Position::getX(){
    return(x);
}

int const Position::getY(){
    return(y);
}







