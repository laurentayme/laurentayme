//
//  Element.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 10/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Element::Element(){
        position =0; // Initialisation du pointeur à l'adresse nulle
        position = new Position();
    
}

Element::~Element(){
    delete position;
    position=0; // Pointeur remis à l'adresse nulle
}

Position Element::getPosition() const{
    return(*position);
}

size_t Element::getTypeId() const {
    return(idType);
}

void Element::setPosition(Position& futur_position){
    *position=futur_position;
}

void Element::setTypeId(size_t ty){
    if(ty==0 || ty==1 || ty==2){
        idType=ty;
    }
    else{
        throw "Type d'Element Incorrect ! (0=StaticElement / 1=Character /2=Menu)";
    }
}

void const Element::affiche_Position(){
    std::cout<<"Coordonnées actuelles: ("<<position->getX()<<","<<position->getY()<<")"<<std::endl;
}

void Element::setLoc(float x, float y){
    loc_x=x;
    loc_y=y;
    
}

float Element::getLoc_x() const{
    return(loc_x);
}

float Element::getLoc_y() const{
    return(loc_y);
}



