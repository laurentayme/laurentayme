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
	this->currentCommands[priority]=std::unique_ptr<Command>(cmd);

}

/*void Engine::addCommand(int priority, std::unique_ptr<Command> cmd){
        
    currentCommands.insert(std::make_pair(priority, cmd));
}*/

void Engine::setState(state::State state){
    currentState=state;
}

int Engine::getNbCommands() const {
    return(currentCommands.size());
}


void Engine::update(){
    
    if(currentState.getTour()%2==0){
           std::cout<<"I enter into Engine::Update()"<<std::endl; 
           for(int i=0;i<6;i++){
            //std::cout<<"1st Loop !"<<std::endl;
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
                        
			if(it->first==i){
				it->second->execute(currentState);
			}
		}
	}
        currentCommands.erase (currentCommands.begin(), currentCommands.end() );
    }
    else{ 
           for(int i=0;i<6;i++){
            //std::cout<<"1st Loop !"<<std::endl;
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
                        
			if(it->first==i){
				it->second->execute(currentState);
			}
		}
	}
        currentCommands.erase (currentCommands.begin(), currentCommands.end() );
    }

	
}





