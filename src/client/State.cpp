#include <stdio.h>
#include "state.h"
using namespace state;

/*State::State(ElementTab* tab,ElementTab* chara,ElementTab* men){
	carte=tab;
	characters=chara;
	menu=men;
}*/
	
ElementTab* State::getMap() const{
	return carte;     
 }

ElementTab* State::getCharacters() const{
    return characters;
}

ElementTab* State::getRedMap() const{
	return red_map;     
 }


ElementTab* State::getMenu() const{
    return menu;
}

void State::setMap(ElementTab* map){
    this->carte=map;
}

void State::setCharacters(ElementTab* characters){
    this->characters=characters;
}

void State::setMenu(ElementTab* menu){
    this->menu=menu;
}


void State::setRedMap(ElementTab* red_map){
	this->red_map=red_map;     
 }

void State::setLandscape(ElementTab* landscape){
    this->landscape=landscape;
}


ElementTab* State::getLandscape() const {
	return landscape;     
 }



