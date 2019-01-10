#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include "math.h"

using namespace engine;

LoadCommand::LoadCommand(const char* f){
	
}

CommandTypeId LoadCommand::getTypeId() const{
    return CommandTypeId::LOAD;
}

void LoadCommand::execute(state::State& state){
 
}

LoadCommand::~LoadCommand(){
}

Json::Value LoadCommand::serialize(){
	Json::Value cmd;
	cmd[" Type "]=this->getTypeId();
	cmd[" filename "]=this->fileName;
	return cmd;

}

void LoadCommand::deserialize(Json::Value cmd){
	this->fileName=cmd[" filename "].asString();
}
