//
//  Space.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

Space::Space(size_t space){
    if (space>=0 && space <=7){
        spaceType=space;
        obstacle=false;
        idType=0;
    }
    else{
        throw "Type de Space Incorrect ! (1=Empty, 2=Start, 3=Trap, 4=RedSpace, "
                "5=WhiteSpace, 6=TurnSpace et 7=BlueSpace)";
    }
}

size_t Space::getSpaceType() const{
    return(spaceType);
}

bool Space::isObstacle() const{
    return(obstacle);
}

void Space::affiche_Classe(){
    std::cout<<"Je suis un Space."<<std::endl;
}

bool Space::isWall() const {
    return(false);
}

std::string Space::getClass() const{
    return("None");
}

size_t Space::getDirection() const{
    return(0);
}

int Space::getWallType() const{
    return 0;
}

int Space::getLandscapeType() const{
    return(-1);
}

void Space::setDirection (size_t direction){
	std::cout<<"Un espace n'a pas de direction"<<std::endl;
}

std::vector<Abilities*> Space::getAbilitiesList() {
    std::vector<Abilities*> list;
	return(list);
}

size_t Space::getPV() const{
	return(1);
}

size_t Space::getPA() const{
	return(1);
}

size_t Space::getPM() const{
	return(1);
}

void Space::setPM(int pm){
}

void Space::setPA(int pa){
}

void Space::setPV(int pv){
}

size_t Space::getTypeId() const{
    return(idType);
}

int Space::getStatut() const{
    return(3);
}

void Space::setStatut(int statut){
}


size_t Space::getTeam() const {
	return(0);
}

void Space::setTeam(size_t team) {
}
