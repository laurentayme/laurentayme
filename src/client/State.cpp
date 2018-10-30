#include <stdio.h>
#include "state.h"
using namespace state;

State::State(ElementTab* tab){
	carte=tab;
}
	
ElementTab* State::getMap() const{
	return carte;     
 }

ElementTab* State::getCharacters() const{
    return characters;
}
