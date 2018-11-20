#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"

using namespace engine;
using namespace state;


OrientationCommand::OrientationCommand(int character, int direction){
	this->character=character;
	this->direction=direction;
}
	
CommandTypeId OrientationCommand::getTypeId () const {
	return(CommandTypeId::DIRECTION);
}


void OrientationCommand::execute(state::State& state){
	/*const std::vector<Element*> characterList = state.getCharacters()->getElementList();
	characterList[character]->setDirection(direction);*/
        
        std::vector<state::Element*> chars=state.getCharacters()->getElementList();
        state.getCharacters()->setElementDirection(direction,character);

}

int OrientationCommand::getCharacter() const {
	return(character);
}

void setCharacter(int character){
	character=character;
}

int getDirection(){
	
}

void setDirection(int direction){
	direction=direction;
}

OrientationCommand::~OrientationCommand(){

}




