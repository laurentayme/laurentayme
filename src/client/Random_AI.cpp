/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
using namespace std;

Random_AI::Random_AI(int randomSeed){
    //Initialisation de la variable aléatoire
    mt19937 randgen(randomSeed);
}


void Random_AI::run(engine::Engine& Engine, int character, state::State& state){

    std::vector<engine::Command*> move_list;

    listCommands(state,character,move_list);

    //std::cout<<"Move List created !"<<std::endl;
    std::cout<<"Move List size: "<<move_list.size()<<endl;


    //Choix Aléatoire Uniforme de la direction//
    std::uniform_int_distribution<int> dis(0,move_list.size()-1);
    int x=dis(randgen);
    std::cout<<"Tirage X= "<<x<<std::endl;
    ////////////////////////////////////////////

    //On fait une boucle sur l'ensemble des commandes possibles
    for(int i=0; i<move_list.size();i++){
        if(x==i){
            Engine.addCommand(3,move_list[i]);
        }
    }
    //std::cout<<"Nb Commands in Engine: "<<Engine.getNbCommands()<<std::endl;
    Engine.update();

    //Test si le character peut attaquer l'adversaire//

        std::vector<state::Element*> chars=state.getCharacters()->getElementList();


        if(chars.size()>1){//Deux personnages actifs

            //Identification du personnage cible
            int target=1-character;
            //cout<<target<<endl;;

            //Calcul de la distance entre les joueurs//
             //cout<<"Sram Y :"<<chars[character]->getPosition().getX()<<endl;
             //cout<<"Iop Y :"<<chars[target]->getPosition().getX()<<endl;

            int ecart_x=chars[character]->getPosition().getX()-chars[target]->getPosition().getX();
            int ecart_y=chars[character]->getPosition().getY()-chars[target]->getPosition().getY();

            ecart_x=std::abs(ecart_x);
            ecart_y=std::abs(ecart_y);
            int distance = std::sqrt(std::pow(ecart_x,2.0)+std::pow(ecart_y,2.0));
            //cout<<"Ecart X :"<<ecart_x<<endl;
            //cout<<"Ecart Y :"<<ecart_x<<endl;
            //cout<<"Distance actuelle :"<<distance<<endl;;
            ///////////////////////////////////////////

            //Récupère ses Abilités//
            std::vector<state::Abilities*> liste_abilities=state.getCharacters()->getElementList()[character]->getAbilitiesList();
            /////////////////////////

            //Liste compétences utilisables
            std::vector<state::Abilities*> abilities_usable;

            for(int i=0; i<liste_abilities.size();i++){
                if(distance<=liste_abilities[i]->getUseDistance() and chars[character]->getPA()>=liste_abilities[i]->getnb_pa()){
                    abilities_usable.push_back(liste_abilities[i]);
                }
            }
            //cout<<liste_abilities.size()<<endl;
            //cout<<"Ok !"<<endl;

            //Choix Aléatoire Uniforme d'une abilité utilisable//
            if(abilities_usable.size()>0){
                cout<<"I can attack !"<<endl;
                std::uniform_int_distribution<int> abilities_dis(1,abilities_usable.size());
                int y=abilities_dis(randgen);

                engine::AttackCommand* attack=new engine::AttackCommand(character,target,abilities_usable[y-1]->getName());
                Engine.addCommand(3,attack);
                Engine.update();

            }
            else if(abilities_usable.size()==0){
                cout<<"I can't attack !"<<endl;
                Engine.update();
            }

        }
}

void Random_AI::stateChanged(const state::Event& event){
}


