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
        this->mouse_x=0;
        this->mouse_y=0;

}

AttackCommand::AttackCommand(int CharacterAttacker,int CharacterTarget, int x, int y){
	this->CharacterAttacker=CharacterAttacker;
	this->CharacterTarget=CharacterTarget;
        this->mouse_x=x;
        this->mouse_y=y;
        
         //On récupère l'attque sur laquelle le joueur a cliqué//
        int case_x=(mouse_x-362)/67;
        int case_y=(mouse_y-595)/62;
        
        //std::cout<<"Case X: "<<case_x<<std::endl;
        //std::cout<<"Case Y: "<<case_y<<std::endl;
        
        
        //Attaque Coup d'Epée
        if(case_x==0 and case_y==0){
            this->AbilityUsed="Coup d'Epée";
        }
        else if(case_x==1 and case_y==0){
            this->AbilityUsed="Colère";
        }
        else if(case_x==2 and case_y==0){
            this->AbilityUsed="Puissance";
        }
        else if(case_x==3 and case_y==0){
            this->AbilityUsed="Epée Destructrice";
        }

}



void AttackCommand::execute(state::State& state){
    
        //Récupération de la liste de characters
        std::vector<state::Element*> chars=state.getCharacters()->getElementList();
        //On récupère la liste des abilités du Character attaquant
        std::vector<state::Abilities*> abilities_list=chars[CharacterAttacker]->getAbilitiesList();

        
	for(int i=0;i<abilities_list.size();i++){
                //Vérification de la possession de l'Abilité par le personnage
		if(abilities_list[i]->getName()==AbilityUsed) {
                    //Vérification du nombe de PA suffisant 
                    if((chars[CharacterAttacker]->getPA())>=abilities_list[i]->getnb_pa()){
                        //Vérification de la distance d'utilisation
                        
                        int ecart_x=abs(chars[CharacterAttacker]->getPosition().getX()-chars[CharacterTarget]->getPosition().getX());
                        int ecart_y=abs(chars[CharacterAttacker]->getPosition().getY()-chars[CharacterTarget]->getPosition().getY());
                        
                        int distance = std::sqrt(std::pow(ecart_x,2.0)+std::pow(ecart_y,2.0));
                        
                        if(distance<=abilities_list[i]->getUseDistance()){
                            state.getCharacters()->setCharacterPA(CharacterAttacker,chars[CharacterAttacker]->getPA()-abilities_list[i]->getnb_pa());
                            state.getCharacters()->setCharacterPV(CharacterTarget,std::max(0,int(chars[CharacterTarget]->getPV()-abilities_list[i]->getDegats())));
                            std::cout<<"Vous avez utilisé l'attaque: "<<abilities_list[i]->getName()<<std::endl;
                            if(chars[CharacterTarget]->getPV()==0){
                                state.getCharacters()->setCharacterStatut(CharacterTarget,3);
                                state.getMenu()->setElementType(0,6);
                                state.setEtat(2);
                                state.getCharacters()->eraseCharacter();
                                
                            }
                        
                        }
                        else{
                            std::cout<<"Vous etes trop loin de la cible pour utiliser la compétence :"<<abilities_list[i]->getName()<<" !"<<std::endl;
                            std::cout<<"La compétence :"<<abilities_list[i]->getName()<<", nécessite d'etre à une distance minimum de "<<abilities_list[i]->getUseDistance()<<" de la cible."<<std::endl;
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
