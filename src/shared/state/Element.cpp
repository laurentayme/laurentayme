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

Element::Element(size_t type){
    position =0; // Initialisation du pointeur à l'adresse nulle
    position = new Position();
    idType=type; //Initialisation du type d'Element
}

Element::~Element(){
    delete position;
    position=0; // Pointeur remis à l'adresse nulle
}

Position const Element::getPosition(){
    return(*position);
}

size_t const Element::getTypeId(){
    return(idType);
}

void Element::setPosition(Position& futur_position){
    *position=futur_position;
}

void Element::setTypeId(size_t ty){
    idType=ty;
}

void const Element::affiche_Position(){
    std::cout<<"Coordonnées actuelles: ("<<position->getX()<<","<<position->getY()<<")"<<std::endl;
}



