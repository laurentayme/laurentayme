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

HeuristicAI::HeuristicAI(const state::State& state, int randomseed){
	mt19937 randgen(randomseed);
        current_state=state;
        characterMap.init(state);
}

void HeuristicAI::run(engine::Engine& Engine, int character, state::State& state){
	
	std::vector<engine::Command*> move_list;

    	listCommands(state,character,move_list);
        
        std::vector<state::Element*> chars=state.getCharacters()->getElementList();
        
        int i_min=0;
        int w_min=100;
        
        for(int i=0;i<move_list.size();i++){
            int x_final=move_list[i]->getVectX()+chars[character]->getPosition().getX();
            int y_final=move_list[i]->getVectY()+chars[character]->getPosition().getY();
            
            std::priority_queue<Point,std::vector<Point>,PointCompareWeight> queue=characterMap.getQueue();
                
            
            while(!queue.empty()){
                Point p=queue.top();
                queue.pop();
                
                if(x_final==p.getX() and y_final==p.getY() and p.getWeight()<w_min){
                    i_min=i;
                    w_min=p.getWeight();
                }   
            }
            
            
            
        }
        
        //On ajoute le "meilleur" déplacement possible à la liste de commandes
        Engine.addCommand(3,move_list[i_min]);
        Engine.update();
        
        
         //Test si le character peut attaquer l'adversaire//


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

void HeuristicAI::stateChanged(const state::Event& event){
    characterMap.update(current_state);
}
