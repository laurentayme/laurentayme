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

ElementTab::ElementTab(int w, int h,std::vector<Element*>& elementList){
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

Element* ElementTab::getLocatedElement(Position *loc)const{
    for(size_t i=0;i<elementList.size();i++){
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

}


void ElementTab::setElementDirection(int dir, int elmt){
    for(size_t i=0;i<elementList.size();i++){
        if (i==elmt){
            elementList[elmt]->setDirection(dir);
        }
    }
    TabEvent e;
    notifyObservers(e);
}

void ElementTab::setLocation(float x, float y,int elmt){
    for(size_t i=0;i<elementList.size();i++){
        if (i==elmt){
            elementList[elmt]->setLoc(x,y);
        }
    }
    TabEvent e;
    notifyObservers(e);

}

void ElementTab::setCharacterPV(int element,int pv){
	for(size_t i=0;i<elementList.size();i++){
		if (i==element){
            		elementList[element]->setPV(pv);
       	 	}
    	}
    	StateEvent s(StateEventId::PVChanged);
    	notifyObservers(s);
}

void ElementTab::setCharacterPM(int element,int pm){
	for(size_t i=0;i<elementList.size();i++){
        	if (i==element){
            	elementList[element]->setPM(pm);
        	}
    	}
        //std::cout<<"I am in setPM function"<<std::endl;
    	StateEvent s(StateEventId::PMChanged);
    	notifyObservers(s);
}

void ElementTab::setCharacterPA(int element,int pa){
	for(size_t i=0;i<elementList.size();i++){
        	if (i==element){
            		elementList[element]->setPA(pa);
        	}
    	}
    	StateEvent s(StateEventId::PAChanged);
    	notifyObservers(s);
}

void ElementTab::setCharacterStatut(int element, int statut){
    for(size_t i=0;i<elementList.size();i++){
        	if (i==element){
            		elementList[element]->setStatut(statut);
        	}
    	}
    	StateEvent s(StateEventId::PAChanged);
    	notifyObservers(s);
}

void ElementTab::eraseCharacter(){
    for(size_t i=0;i<elementList.size();i++){
        if(elementList[i]->getStatut()==3 and elementList[i]->isPlayer()==false){
            std::string name =elementList[i]->getClass();
             //elementList.erase(elementList.begin() + i);
             std::cout<<name<<" a été tué !"<<std::endl;
        }

    }
    	StateEvent s(StateEventId::PVChanged);
    	notifyObservers(s);

}

void ElementTab::setElementMove(int element, bool move){
    for(size_t i=0;i<elementList.size();i++){
        	if (i==element){
            		elementList[element]->setMoving(move);
        	}
    	}
    	StateEvent s(StateEventId::PAChanged);
    	notifyObservers(s);
}

void ElementTab::setElementList(std::vector<Element*> elmt_list){
	this->elementList=elmt_list;
}

void ElementTab::setElementType(int element, int type){
    for(size_t i=0;i<elementList.size();i++){
        	if (i==element){
            		elementList[element]->setTypeId(type);
                }
    }
    StateEvent s(StateEventId::PAChanged);
    notifyObservers(s);
}
