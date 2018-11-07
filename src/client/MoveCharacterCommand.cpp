/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>

using namespace engine;

MoveCharacterCommand::MoveCharacterCommand(int character){
    this->character=character;
}

MoveCharacterCommand::~MoveCharacterCommand(){
}


CommandTypeId MoveCharacterCommand::getTypeId() const {  
    return(CommandTypeId::MOVE_CHARACTER);
}

void MoveCharacterCommand::execute(state::State& act_state){
    
    //Récupération de la liste de characters
    std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
    
    //On récupère la position actuelle du Character
    state::Position pos=chars[character]->getPosition();
    
    //On récupère les dimensions de la carte
    size_t longueur=act_state.getMap()->getHeight();
    size_t largeur=act_state.getMap()->getWidth();
    
    std::cout<<pos.getX()<<std::endl;
    //Cas du Character orienté vers le Nord
    if(chars[character]->getDirection()==1){
        if(pos.getX()>1){ //Vérification Bordure de Map
            pos.setX(pos.getX()-1);
            state::Position& posRef=pos;
            
            act_state.getCharacters()->setElement(posRef,character);
            
            //chars[character]->setPosition(pos);
        }
        else{
            throw "Déplacement vers le Nord Impossible !";
            chars[character]->affiche_Position();
        }
    }
    
    //Cas du Character orienté vers l'Est
    else if(chars[character]->getDirection()==2){
        
        if(pos.getY()<largeur){ //Vérification Bordure de Map
            pos.setY(pos.getY()+1);
            chars[character]->setPosition(pos);
        }
        else{
            throw "Déplacement vers l'Est Impossible !";
        }
        
    }
    
    //Cas du Character orienté vers le Sud
    else if(chars[character]->getDirection()==3){
        
        if(pos.getX()<longueur){ //Vérification Bordure de Map
            pos.setX(pos.getX()+1);
            chars[character]->setPosition(pos);
        }
        else{
            throw "Déplacement vers le Sud Impossible !";
        }
        
    }
    
    //Cas du Character orienté vers l'Ouest
    else if(chars[character]->getDirection()==4){
        
        if(pos.getY()>1){ //Vérification Bordure de Map
            pos.setY(pos.getY()-1);
            chars[character]->setPosition(pos);
        }
        else{
            throw "Déplacement vers l'Ouest Impossible !";
        }
        
    }
    
    
}


