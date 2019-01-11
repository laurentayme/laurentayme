#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include "math.h"
#include <algorithm>  

using namespace engine;

HandleStatut::HandleStatut(int chara){
	character=chara;

}

CommandTypeId HandleStatut::getTypeId() const {
	return(CommandTypeId::STATUT);

}

void HandleStatut::execute(state::State& state){
	//personnage boosté//
	if(state.getCharacters()->getElementList()[character]->getStatut()==4){
		state.getCharacters()->getElementList()[character]->setPA(state.getCharacters()->getElementList()[character]->getMaxStat(2)+1);
		state.getCharacters()->getElementList()[character]->setStatut(5);
		state.getCharacters()->getElementList()[character]->setPM(state.getCharacters()->getElementList()[character]->getMaxStat(1));
	}
	//personnage tour après boosté//
	else if(state.getCharacters()->getElementList()[character]->getStatut()==5){
		state.getCharacters()->getElementList()[character]->setPA(state.getCharacters()->getElementList()[character]->getMaxStat(2)-1);
		state.getCharacters()->getElementList()[character]->setStatut(1);
		state.getCharacters()->getElementList()[character]->setPM(state.getCharacters()->getElementList()[character]->getMaxStat(1));
	}
	//personnage empoisonné//s
	else if(state.getCharacters()->getElementList()[character]->getStatut()==2){
		state.getCharacters()->getElementList()[character]->setPV(state.getCharacters()->getElementList()[character]->getPV()-3);
		state.getCharacters()->getElementList()[character]->setPM(state.getCharacters()->getElementList()[character]->getMaxStat(1));
		state.getCharacters()->getElementList()[character]->setPA(state.getCharacters()->getElementList()[character]->getMaxStat(2));
	
	}
	//personnage à l' état normal//
	else if(state.getCharacters()->getElementList()[character]->getStatut()==1){
		state.getCharacters()->getElementList()[character]->setPM(state.getCharacters()->getElementList()[character]->getMaxStat(1));
		state.getCharacters()->getElementList()[character]->setPA(state.getCharacters()->getElementList()[character]->getMaxStat(2));
	}
	
	
}

Json::Value HandleStatut::serialize(){
	Json::Value cmd;
	cmd[" Type "]=this->getTypeId();
	cmd[" Character "]=this->character;
	return cmd;

}

void HandleStatut::deserialize(Json::Value cmd){
	//std::cout<<cmd[" Character "].asInt()<<"taille  json "<<sizeof(cmd[" Character "].asInt())<<"taille int    "<<sizeof(int)<<cmd[" Type "]<<std::endl;
	this->character=cmd[" Character "].asInt();
	std::cout<<"le personnage   "<<this->character<<std::endl;
}


