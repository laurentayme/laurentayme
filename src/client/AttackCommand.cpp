#include <stdio.h>
#include "state.h"
#include "engine.h"


using namespace engine;

AttackCommand::AttackCommand(int CharacterAttacker,int CharacterTarget,std::string AbilityUsed){
	CharacterAttacker=CharacterAttacker;
	CharacterTarget=CharacterTarget;
	AbilityUsed=AbilityUsed;

}

AttackCommand::~AttackCommand(){

}

void AttackCommand::execute(state::State& state){
	state::Character* charAtt_ptr= dynamic_cast<state::Character*>(state.getCharacters()->getElementList()[CharacterAttacker]);
	state::Character* charTar_ptr= dynamic_cast<state::Character*>(state.getCharacters()->getElementList()[CharacterTarget]);

	for(int i=0;i<charAtt_ptr->getAbilitiesList().size();i++)	{
		if(charAtt_ptr->getAbilitiesList()[i]->getName()==AbilityUsed) {

			charTar_ptr->setPV(charTar_ptr->getPV()-charAtt_ptr->getAbilitiesList()[i]->getDegats());

		}
	}

}

CommandTypeId AttackCommand::getTypeId() const {

	return(CommandTypeId::ATTACK);

}
