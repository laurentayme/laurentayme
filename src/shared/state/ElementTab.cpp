//
//  ElementTab.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"

using namespace state;

ElementTab::ElementTab(size_t w, size_t h,std::vector<Element*> elementList){
    width=w;
    height=h;
    this->elementList=elementList;
}

ElementTab::~ElementTab(){
    for(int i=0 ;i<elementList.size();i++){
        delete elementList[i];
        elementList[i]=0;
        
    }
}

size_t const ElementTab::getHeight(){
    return(height);
}

size_t const ElementTab::getWidth(){
    return(width);
}

std::vector<Element*> ElementTab::getElementList(){
    return(elementList);
}

void ElementTab::addElement(Element* elmt){
    elementList.push_back(elmt);
}

Element* const ElementTab::getLocatedElement(Position *loc){
    for(int i=0;i<elementList.size();i++){
        Position actu_pos=elementList[i]->getPosition();
        if(actu_pos.getX()==loc->getX() && actu_pos.getY()==loc->getY()){
            return(elementList[i]);
        }
        
    }
    //Cas où il n'y a aucun élément sur cette position
    return(nullptr);
}

void ElementTab::resize(size_t w, size_t h){
    width=w;
    height=h;
}

void ElementTab::setElement(Position* pos,Element* elmt){
    for(int i=0;i<elementList.size();i++){
        if (elementList[i]==elmt){
            elementList[i]->setPosition(*pos);
        }
    }
}



