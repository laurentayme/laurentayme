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

const state::State* Engine::getState() const {
	return(currentState);
}

void Engine::addPassiveCommands(){
}

void Engine::addCommand(int priority,Command* cmd){
	this->currentCommands[priority]=std::unique_ptr<Command>(cmd);

}


void Engine::setState(state::State* state){
    currentState=state;
}

int Engine::getNbCommands() const {
    return(currentCommands.size());
}


void Engine::update(){ 
           for(int i=0;i<4;i++){
            //std::cout<<"1st Loop !"<<std::endl;
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
                        
			if(it->first==i){
			
                            if(it->second->getTypeId()==CommandTypeId::CLICK or it->second->getTypeId()==CommandTypeId::MOUSEMOVED or it->second->getTypeId()==CommandTypeId::SURBRILLANCE){
                                it->second->execute(*currentState,*this);
                            }
                            else{
                                it->second->execute(*currentState);
                            }
                            
			}
		}
	}
        currentCommands.erase (currentCommands.begin(), currentCommands.end() );

	
}




