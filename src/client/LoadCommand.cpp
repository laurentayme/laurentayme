#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"
#include <SFML/Graphics.hpp>

using namespace engine;
using namespace state;

LoadCommand::LoadCommand (const char* f){
	fileName=f;
}

CommandTypeId LoadCommand::getTypeId () const {
	return(CommandTypeId::LOAD);
}

void LoadCommand::execute(state::State& state){
	
}

	
LoadCommand::~LoadCommand(){

}

