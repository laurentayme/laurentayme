/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

using namespace ai;

Point::Point(int x, int y, int w){
    this->x=x;
    this->y=y;
    this->weight=w;
}

Point Point::transform(int d){
    if (d==1){//North
        x-=1;
    }
    else if(d==3){//South
        x+=1;
    }
    
    else if(d==2){//East
        y+=1;
    }
    
    else if(d==4){//West
        y-=1;
    }
    
}

int Point::getWeight() const {
    return(weight);
}

int Point::getX() const {
    return(x);
}

int Point::getY() const {
    return(y);
}

void Point::setWeight(int w) {
    this->weight=w;
}

void Point::setX(int x){
    this->x=x;
}

void Point::setY(int y){
    this->y=y;
}