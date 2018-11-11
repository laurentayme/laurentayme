//
//  Landscape.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Landscape::Landscape(){
    obstacle=true;
    wall=false;
    landscapeType=0;
}

bool const Landscape::isWall() const {
    return(wall);
}

bool const Landscape::isObstacle() const {
    return(obstacle);
}

void Landscape::affiche_Classe(){
    std::cout<<"Je suis un Landscape."<<std::endl;
}

std::string const Landscape::getClass() const{
    return("None");
}

size_t const Landscape::getDirection() const{
    return(0);
}

size_t const Landscape::getSpaceType() const {
	return 0;
}

int Landscape::getWallType() const{
    return 0;
}

int Landscape::getLandscapeType() const{
    return(landscapeType);
}

void Landscape::setLandscapeType(int landscape){
    if(landscape==0 || landscape==1){
        landscapeType=landscape;
    }
    else{
        throw "Incorrect Landscape Type !";
    }
    
}

void Landscape::setDirection(size_t direction){
	std::cout<< "Un paysage n'a pas de direction"<<std::endl;

}


std::vector<Abilities*> Landscape::getAbilitiesList() const {
    std::vector<Abilities*> list;
	return(list);
}

size_t Landscape::getPV() const{
	return(1);
}

size_t Landscape::getPA() const{
	return(1);
}

size_t Landscape::getPM() const{
	return(1);
}

void Landscape::setPM(int pm){
}

void Landscape::setPV(int pv){
}

void Landscape::setPA(int pv){
}
