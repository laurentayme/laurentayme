/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ai.h"
#include "engine.h"
#include <memory>

using namespace ai;


void AI::listCommands(const state::State& state, int character,std::vector<std::unique_ptr<engine::Command>>& move_list){
    
    std::vector<state::Element*> chars=state.getCharacters()->getElementList();
    //Obtention Nbre PM
    int pm=chars[character]->getPM();
    
    //Map Width
    int width=state.getMap()->getWidth();
    
    //Map Height
    int height=state.getMap()->getHeight();
    
    //On fait une boucle sur le nbre de PM du character
    for(int i=1; i<=pm;i++){
        
        //Vérification que le personnage pourra effectuer le(s) mouvement(s)//
        //////////////////////////////////////////////////////////////////////
            if(chars[character]->getPosition().getX()>i+1){//Déplacement Nord
               move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,-i,0)));

                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                }
                else{//Déplacement Est Impossible
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }

                }

            }
            else{//Déplacement Nord Impossible
                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                }
                else{//Déplacement Est Impossible
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                       }
                   }

                }
            }


    }
    //////////FIN Déplacement Personnage////////////
    ////////////////////////////////////////////////
    
    
    /*//On met dans la liste d'attaque, toutes les attaques qu le personnage possède
    //car on ne sait pas encore où est ce qu'il va se déplacer.
    std::vector<state::Abilities*> abilities_list=chars[character]->getAbilitiesList();
    for(int i=0;i<abilities_list.size();i++){
        attack_list.push_back(std::unique_ptr<state::Abilities>(abilities_list[i]->getName(),abilities_list[i]->getDegats(),abilities_list[i]->getnb_pa(),abilities_list[i]->getUseDistance()));
    }*/
    
}




