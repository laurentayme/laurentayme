#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "engine.h"
#include <vector>
#include <random>
#include <iostream>
#include <math.h>
#include<algorithm>


using namespace ai;


DeepAI::DeepAI(const state::State& state, int depth, int character){
    this->current_state=state;
    this->maxDepth=depth;
    characterMap.init(state,character);
    this->character=character;
}

void DeepAI::run(engine::Engine& engine, int character, state::State& state){
    minimax(engine, maxDepth,character,state);
}

void DeepAI::minimax(engine::Engine& engine, int depth, int character, state::State& state){
    
    //On récupère la liste des mvts possibles
    std::priority_queue<Point,std::vector<Point>,PointCompareWeight> queue=characterMap.getQueue();
    std::vector<state::Position> move_list;
    std::vector<state::Element*> chars=state.getCharacters()->getElementList(); 
    state::Position best_Position(chars[character]->getPosition().getX(),chars[character]->getPosition().getY());
    int max_value=-pow(10,10.0);
    int target=0;
    //On retire tous les mouvements amenant sur des obstacles
    
    int EcartX_init=abs(chars[character]->getPosition().getX()-chars[target]->getPosition().getX());
    int EcartY_init=abs(chars[character]->getPosition().getY()-chars[target]->getPosition().getY());
    
    int Distance_init=EcartX_init+EcartY_init;
    
    int Poids_min=std::max(Distance_init-int(chars[character]->getPM()),0);
    
    while(!queue.empty()){
        Point pt=queue.top();
        queue.pop();
        //On filtre les obstacles
        if((pt.getWeight()>=Poids_min) and (pt.getWeight()<pow(10,3.0))){
            state::Position pos(pt.getX(),pt.getY());
            move_list.push_back(pos);
        }
    }
    
    
    
    
    //std::cout<<"I'll test the different movements"<<std::endl;
    for(int i=0; i<move_list.size();i++){
        //On sauvegarde la position initiale
        state::Position Position_init(chars[character]->getPosition().getX(),chars[character]->getPosition().getY());
        //On effectue le déplacement///
        //std::cout<<"I Update the Character position"<<std::endl;
        //On Update le character a la position sélectionnée
        state.getCharacters()->setElement(move_list[i],character);
        
        int val=Min(state,character,depth-1);
        if(val>max_value){
            max_value=val;
            state::Position p(chars[character]->getPosition().getX(),chars[character]->getPosition().getY());
            best_Position=p ;
            std::cout<<"ScoreMax ="<<max_value<<std::endl;
        }

        //On annule les déplacements précédemment faits//
        state.getCharacters()->setElement(Position_init,character); 
            
            /////////////////////////////////////////////////
    }
    
    //Détermination du Vecteur de déplacement associé
    int best_VectX=best_Position.getX()-chars[character]->getPosition().getX();
    int best_VectY=best_Position.getY()-chars[character]->getPosition().getY();
    
    //Détermination de la distance entre la cible et la futur place du character
    int ecart_x=best_Position.getX()-chars[target]->getPosition().getX();
    int ecart_y=best_Position.getY()-chars[target]->getPosition().getY();
   
    
    ecart_x=abs(ecart_x);
    ecart_y=abs(ecart_y);
    
    
    
    
    int distance =ecart_x+ecart_y;
    //std::cout<<"Distance entre les persos :"<<distance<<std::endl;

    //Détermination si une ataque est faisable
        //Récupère ses Abilités//
        std::vector<state::Abilities*> liste_abilities=chars[character]->getAbilitiesList();
        /////////////////////////

        //Liste compétences utilisables
        std::vector<state::Abilities*> abilities_usable;
	size_t damage=0;
	int attackMax;

        //On récupère la liste des abilités utilisables
        for(int i=0; i<liste_abilities.size();i++){
            if(chars[character]->getPA()>=liste_abilities[i]->getnb_pa() and liste_abilities[i]->getUseDistance()>=distance){
                abilities_usable.push_back(liste_abilities[i]);
                //std::cout<<"Ability added: "<<liste_abilities[i]->getName()<<std::endl;
            }
        }

        //On récupère l'abilité ayant les dégats Maximum
        for(int i=0; i<abilities_usable.size();i++){
            if(abilities_usable[i]->getDegats()>damage){
                damage=abilities_usable[i]->getDegats();
                attackMax=i;
            }
        }
    
    
    
    //Execution du meilleur Coup à jouer (Déplacement + attaque) //
    engine::MoveCharacterCommand* best_move=new engine::MoveCharacterCommand(character,best_VectX,best_VectY);
    engine.addCommand(2,best_move);
    
    
    engine::AttackCommand* best_attack=new engine::AttackCommand(character, target, abilities_usable[attackMax]->getName());
    engine.addCommand(3,best_attack);
    engine.update();
    
}

int DeepAI::Evaluate(state::State& state, int elmt){
    //std::cout<<"I Evaluate the actual State"<<std::endl;
    std::vector<state::Element*> chars=state.getCharacters()->getElementList();
    int score=-pow(10,10.0);
    int target=1-elmt;
    
    int distance=std::abs((int)(chars[target]->getPosition().getX()-chars[elmt]->getPosition().getX())) + std::abs((int)(chars[elmt]->getPosition().getY()-chars[target]->getPosition().getY()));
	
    //Récupère ses Abilités//
    std::vector<state::Abilities*> liste_abilities=state.getCharacters()->getElementList()[elmt]->getAbilitiesList();
    /////////////////////////
    int damage=0;

    //On récupère la meilleure attaque depuis la position de elmt
    for(int i=0; i<liste_abilities.size();i++){
        if(chars[elmt]->getPA()>=liste_abilities[i]->getnb_pa() and liste_abilities[i]->getUseDistance()>=distance and liste_abilities[i]->getDegats()>damage){
            damage=liste_abilities[i]->getDegats();
        }
    }
    
    score=damage;
    
    //Récupère les Abilités de l'ENNEMI//
    std::vector<state::Abilities*> liste_abilities_target=state.getCharacters()->getElementList()[target]->getAbilitiesList();
    /////////////////////////
    int damage_target=0;

    //On récupère la meilleure attaque depuis la position de target
    for(int i=0; i<liste_abilities_target.size();i++){
        if(chars[target]->getPA()>=liste_abilities_target[i]->getnb_pa() and liste_abilities_target[i]->getUseDistance()>=distance and liste_abilities_target[i]->getDegats()>damage){
            damage_target=liste_abilities_target[i]->getDegats();
        }
    }
   
    score-=damage_target;
    
    if(damage==0){
        score-=abs(distance);
    }
    
    
    //std::cout<<"Score :"<<score<<std::endl;
    return(score);   
}


void DeepAI::stateChanged(const state::Event&){
    characterMap.update(current_state,character);
}

int DeepAI::Min(state::State& state, int character, int depth){
    
    //On récupère la liste des mvts possibles
    std::priority_queue<Point,std::vector<Point>,PointCompareWeight> queue=characterMap.getQueue();
    std::vector<state::Position> move_list;
    //On retire tous les mouvements amenant sur des obstacles
    while(!queue.empty()){
        Point pt=queue.top();
        queue.pop();
        //On filtre les obstacles
        if(pt.getWeight()<pow(10,3.0)){
            state::Position pos(pt.getX(),pt.getY());
            move_list.push_back(pos);
        }
    }
    
    //std::vector<int> possible_move;
    std::vector<state::Element*> chars=state.getCharacters()->getElementList();
    
    
    if(depth==0){
        return(Evaluate(state,character));
    }
    else{
        int min_value=pow(10,5.0);
    
        for(int i=0; i<move_list.size();i++){
            //On sauvegarde la position initiale
            state::Position Position_init(chars[character]->getPosition().getX(),chars[character]->getPosition().getY());
            //On effectue le déplacement///
            //std::cout<<"I Update the Character position"<<std::endl;
            //On Update le character a la position sélectionnée
            state.getCharacters()->setElement(move_list[i],character);

            if(Max(state,character,depth-1)<min_value){
                min_value=Max(state,character,depth-1);
            }

            //On annule les déplacements précédemment faits//
            state.getCharacters()->setElement(Position_init,character); 
            /////////////////////////////////////////////////
        }
        return(min_value);  
    }
}

int DeepAI::Max(state::State& state, int character, int depth){

    std::vector<state::Element*> chars=state.getCharacters()->getElementList();
    int state_modified=0;
    
    int max_value=-pow(10,5.0);
    
    //On récupère la liste des mvts possibles
    std::priority_queue<Point,std::vector<Point>,PointCompareWeight> queue=characterMap.getQueue();
    std::vector<state::Position> move_list;
    while(!queue.empty()){
        Point pt=queue.top();
        queue.pop();
        //On filtre les obstacles
        if(pt.getWeight()<pow(10,3.0)){
            state::Position pos(pt.getX(),pt.getY());
            move_list.push_back(pos);
        }
    }
    
    if(depth==0){
        return(Evaluate(state,character));
    }
    else{
    
        for(int i=0; i<move_list.size();i++){
            //On sauvegarde la position initiale
            state::Position Position_init(chars[character]->getPosition().getX(),chars[character]->getPosition().getY());
            //On effectue le déplacement///
            //std::cout<<"I Update the Character position"<<std::endl;
            //On Update le character a la position sélectionnée
            state.getCharacters()->setElement(move_list[i],character);

            if(Min(state,character,depth-1)>max_value){
                max_value=Min(state,character,depth-1);
            }

            //On annule les déplacements précédemment faits//
            state.getCharacters()->setElement(Position_init,character); 
            /////////////////////////////////////////////////
        }
        return(max_value);  
    }
}


