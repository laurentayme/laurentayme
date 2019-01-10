#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "state.h"
#include "engine.h"
#include <utility>
#include "json/json.h"
#include <fstream>

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
	/*if(cmd->getTypeId()==CommandTypeId::TURN){
		update();
	}*/

}


void Engine::setState(state::State* state){
    currentState=state;
}

int Engine::getNbCommands() const {
    return(currentCommands.size());
}


void Engine::update(){ 
	    notifyUpdating();
           for(int i=0;i<5;i++){
            //std::cout<<"1st Loop !"<<std::endl;
		for(auto it =currentCommands.begin();it!=currentCommands.end();it++){
                        
			if(it->first==i){
                            if(it->second->getTypeId()==CommandTypeId::CLICK or it->second->getTypeId()==CommandTypeId::MOUSEMOVED or it->second->getTypeId()==CommandTypeId::SURBRILLANCE){
					if(enableRecord==true){
						std::ifstream file("replay.json");
   							 if(!file){  
								std::cout << "File opening failed\n";
								std::ofstream myfile;
								myfile.open("replay.json",std::ofstream::out | std::ofstream::app);
								myfile<<"["<<"\n";
								myfile<<it->second->serialize();
								myfile<<",";
								myfile<< "\n";
								record.append(it->second->serialize());
								
							   }
						file.close();
						std::ofstream myfile;
						myfile.open("replay.json",std::ofstream::out | std::ofstream::app);
						myfile<<it->second->serialize();
						myfile<<",";
						myfile<< "\n";
						record.append(it->second->serialize());
				}
                                it->second->execute(*currentState,*this);
				
				
                            }
                            else{
				if(enableRecord==true){
					std::ifstream file("replay.json");
						 if(!file){  
							std::cout << "File opening failed\n";
							std::ofstream myfile;
							myfile.open("replay.json",std::ofstream::out | std::ofstream::app);
							myfile<<"["<<"\n";
							myfile<<it->second->serialize();
							myfile<<",";
							myfile<< "\n";
							record.append(it->second->serialize());
							
						   }
					file.close();
					std::ofstream myfile;
					myfile.open("replay.json",std::ofstream::out | std::ofstream::app);
					myfile<<it->second->serialize();
					myfile<<",";
					myfile<< "\n";
					record.append(it->second->serialize());
				}
                                it->second->execute(*currentState);
				
                            }
                            
			}
		}
	}
        currentCommands.erase (currentCommands.begin(), currentCommands.end() );
	notifyUpdated();

	
}


void Engine::setEnableRecord(bool rec){
	this->enableRecord=rec;
}

