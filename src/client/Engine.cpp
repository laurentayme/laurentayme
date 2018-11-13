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
<<<<<<< HEAD
	currentCommands[priority]=(std::shared_ptr<Command>) cmd;
||||||| merged common ancestors
	currentCommands[priority]=std::unique_ptr<Command>(cmd);

=======
	this->currentCommands[priority]=std::unique_ptr<Command>(cmd);

>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
}

<<<<<<< HEAD
/*void Engine::addCommandIA(int priority,std::unique_ptr<Command> cmd){
	std::vector<unique_ptr<Command>> cmd_ref
	currentCommands[priority]=cmd;

}*/


||||||| merged common ancestors
=======
/*void Engine::addCommand(int priority, std::unique_ptr<Command> cmd){
        
    currentCommands.insert(std::make_pair(priority, cmd));
}*/

>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
void Engine::setState(state::State state){
    currentState=state;
}

int Engine::getNbCommands() const {
    return(currentCommands.size());
}


void Engine::update(){
<<<<<<< HEAD
	for(int i=0;i<3;i++){
||||||| merged common ancestors
	for(int i=0;i<10;i++){
=======
    
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
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
                        
			if(it->first==i){
				it->second->execute(currentState);
			}
		}
	}
<<<<<<< HEAD
	//currentCommands.clear();
||||||| merged common ancestors
	
=======
        currentCommands.erase (currentCommands.begin(), currentCommands.end() );
    }

	
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
}





