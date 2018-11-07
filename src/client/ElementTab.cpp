//
//  ElementTab.cpp
//  PLT_Project
//
//  Created by Valentin Laurent on 15/10/2018.
//  Copyright © 2018 Valentin Laurent. All rights reserved.
//

#include <stdio.h>
#include "state.h"
#include <iostream>

using namespace state;

ElementTab::ElementTab(int w, int h,std::vector<Element*> elementList){
	if(w>=0&&h>=0){
		width=w;
		height=h;
    		this->elementList=elementList;
	}
	else{
		throw "Dimensions de la map incorrectes !";
	}

}

ElementTab::~ElementTab(){
    for(size_t i=0 ;i<elementList.size();i++){
        delete elementList[i];
        elementList[i]=0;
        
    }
}

size_t const ElementTab::getHeight() const {
    return(height);
}

size_t const ElementTab::getWidth() const {
    return(width);
}

std::vector<Element*> ElementTab::getElementList() const {
    return(elementList);
    
}

void ElementTab::addElement(Element* elmt){
    elementList.push_back(elmt);
    TabEvent e;
    notifyObservers(e);
}

Element* const ElementTab::getLocatedElement(Position *loc){
    for(size_t i=0;i<elementList.size();i++){
        Position actu_pos=elementList[i]->getPosition();
        if(actu_pos.getX()==loc->getX() && actu_pos.getY()==loc->getY()){
            return(elementList[i]);
        }
        
        
    }
    TabEvent e;
    notifyObservers(e);
    
    //Cas où il n'y a aucun élément sur cette position
    return(nullptr);
}

void ElementTab::resize(size_t w, size_t h){
    width=w;
    height=h;
    TabEvent e;
    notifyObservers(e);
}

void ElementTab::setElement(Position& pos,int elmt){
    for(size_t i=0;i<elementList.size();i++){
        if (i==elmt){
            elementList[elmt]->setPosition(pos);
        }
    }
    TabEvent e;
    notifyObservers(e);
    //std::cout<<"Observer notifié !"<<std::endl;
    
}





