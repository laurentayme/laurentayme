#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include "math.h"
#include <algorithm>  

using namespace engine;

AttackCommand::AttackCommand(int CharacterAttacker,int CharacterTarget,std::string AbilityUsed){
	this->CharacterAttacker=CharacterAttacker;
	this->CharacterTarget=CharacterTarget;
	this->AbilityUsed=AbilityUsed;

}



void AttackCommand::execute(state::State& state){
        
        //Récupération de la liste de characters
        std::vector<state::Element*> chars=state.getCharacters()->getElementList();
        //On récupère la liste des abilités du Character attaquant
        std::vector<state::Abilities*> abilities_list=chars[CharacterAttacker]->getAbilitiesList();

        
	for(int i=0;i<abilities_list.size();i++){
		if(abilities_list[i]->getName()==AbilityUsed) {
                    if((chars[CharacterAttacker]->getPA())>=abilities_list[i]->getnb_pa()){
                        state.getCharacters()->setCharacterPA(CharacterAttacker,chars[CharacterAttacker]->getPA()-abilities_list[i]->getnb_pa());
			state.getCharacters()->setCharacterPV(CharacterTarget,std::max(0,int(chars[CharacterTarget]->getPV()-abilities_list[i]->getDegats())));
                    
                        if(chars[CharacterTarget]->getPV()==0){
                            state.getCharacters()->setCharacterStatut(CharacterTarget,3);
                            state.getCharacters()->eraseCharacter();
                        }
                    }
                    else{
                        std::cout<<"PA insuffisants !"<<std::endl;
                    }
                        
		}
	}

}

CommandTypeId AttackCommand::getTypeId() const {
	return(CommandTypeId::ATTACK);

}
