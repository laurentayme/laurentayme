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

Element::Element(size_t idtype){
    if(idtype==0 || idtype==1){
        position =0; // Initialisation du pointeur à l'adresse nulle
        position = new Position();
        idType=idtype; //Initialisation du type d'Element
    }
    else{
        throw "Type d'Element Incorrect ! (0=StaticElement / 1=Character)";
    }
    
}

Element::~Element(){
    delete position;
    position=0; // Pointeur remis à l'adresse nulle
}

Position const Element::getPosition() const{
    return(*position);
}

size_t const Element::getTypeId() const {
    return(idType);
}

void Element::setPosition(Position& futur_position){
    *position=futur_position;
}

void Element::setTypeId(size_t ty){
    if(ty==0 || ty==1){
        idType=ty;
    }
    else{
        throw "Type d'Element Incorrect ! (0=StaticElement / 1=Character)";
    }
}

void const Element::affiche_Position(){
    std::cout<<"Coordonnées actuelles: ("<<position->getX()<<","<<position->getY()<<")"<<std::endl;
}



