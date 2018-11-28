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
    wallType=1;
    idType=0;
}

bool Wall::isWall() const {
    return(true);
}

bool Wall::isObstacle() const {
    return(true);
}

void Wall::affiche_Classe(){
    std::cout<<"Je suis un Wall."<<std::endl;
}

std::string Wall::getClass() const{
    return("None");
}

size_t Wall::getDirection() const{
    return(0);
}


size_t Wall::getSpaceType() const {
	return 0;
}

int Wall::getWallType() const{
    return wallType;
}

void Wall::setWallType(int wall_type) {
    if(wall_type==1 || wall_type==2){
        wallType=wall_type;
    }
    else{
        throw "Incorrect Wall Type !";
    }
    
}

int Wall::getLandscapeType() const{
    return(-1);
}


void Wall::setDirection(size_t direction){
	std::cout<<"Un mur n'a pas de direction"<<std::endl;
}


std::vector<Abilities*> Wall::getAbilitiesList() {
    std::vector<Abilities*> list;
	return(list);
}

size_t Wall::getPV() const{
	return(1);
}

size_t Wall::getPA() const{
	return(1);
}

size_t Wall::getPM() const{
	return(1);
}

void Wall::setPM(int pm){
}

void Wall::setPA(int pa){
}

void Wall::setPV(int pv){
}

size_t Wall::getTypeId() const{
    return(idType);
}

int Wall::getStatut() const{
    return(3);
}

void Wall::setStatut(int statut){
}


int Wall::getTeam() const {
	return(0);
}

void Wall::setTeam(int teamset) {
}
