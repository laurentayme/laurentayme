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

ElementTab* State::getMenu() const{
    return menu;
}
