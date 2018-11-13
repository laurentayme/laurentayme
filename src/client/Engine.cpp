#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"
#include <utility>

using namespace engine;


Engine::Engine(){
	

}
Engine::~Engine(){

}

const state::State& Engine::getState() const {
	return(currentState);
}

void Engine::addPassiveCommands(){

}

void Engine::addCommand(int priority,Command* cmd){
	currentCommands[priority]=(std::shared_ptr<Command>) cmd;
}

/*void Engine::addCommandIA(int priority,std::unique_ptr<Command> cmd){
	std::vector<unique_ptr<Command>> cmd_ref
	currentCommands[priority]=cmd;

}*/


void Engine::setState(state::State state){
    currentState=state;
}


void Engine::update(){
	for(int i=0;i<3;i++){
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
		
			if(it->first==i){
				it->second->execute(currentState);
			}
		}
	}
	//currentCommands.clear();
}



