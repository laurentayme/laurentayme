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

HeuristicAI::HeuristicAI(const state::State& state, int randomseed,int chara){
	mt19937 randgen(randomseed);
        current_state=state;
	character=chara;
        characterMap.init(state,character);
}

void HeuristicAI::run(engine::Engine& Engine, int character, state::State& state){

	std::vector<engine::Command*> move_list;

    	listCommands(state,character,move_list);

        std::vector<state::Element*> chars=state.getCharacters()->getElementList();

        int i_min=0;
        int w_min=100;

       /* for(int i=0;i<move_list.size();i++){
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
        Engine.update();*/


         //Test si le character peut attaquer l'adversaire//

	size_t distance=100;

        if(chars.size()>1){//Plus de deux personnages actifs

            //Identification du personnage cible
            int target;

            //Calcul de la distance entre les joueurs//
             //cout<<"Sram Y :"<<chars[character]->getPosition().getX()<<endl;
             //cout<<"Iop Y :"<<chars[target]->getPosition().getX()<<endl;
	    for(size_t i=0;i<chars.size();i++){
	    	if(chars[i]->getTeam()!=chars[character]->getTeam()){

            	int ecart_x=chars[character]->getPosition().getX()-chars[i]->getPosition().getX();
            	int ecart_y=chars[character]->getPosition().getY()-chars[i]->getPosition().getY();

            	ecart_x=std::abs(ecart_x);
            	ecart_y=std::abs(ecart_y);
			if(ecart_x+ecart_y<=distance){
				distance=ecart_x+ecart_y;
				std::cout<<"le joueur adverse se trouve à une distance de "<<distance<<std::endl;
				target=i;
			}
		}

	    }


            //int distance = std::sqrt(std::pow(ecart_x,2.0)+std::pow(ecart_y,2.0));
            //cout<<"Ecart X :"<<ecart_x<<endl;
            //cout<<"Ecart Y :"<<ecart_x<<endl;
            //cout<<"Distance actuelle :"<<distance<<endl;;
            ///////////////////////////////////////////



            //Récupère ses Abilités//
            std::vector<state::Abilities*> liste_abilities=state.getCharacters()->getElementList()[character]->getAbilitiesList();
            /////////////////////////

            //Liste compétences utilisables
            std::vector<state::Abilities*> abilities_usable;
	    size_t damage=0;
	    int attackMax;

            //On récupère la liste des abilités utilisables
            for(int i=0; i<liste_abilities.size();i++){
                if(chars[character]->getPA()>=liste_abilities[i]->getnb_pa()){
                    abilities_usable.push_back(liste_abilities[i]);
                }
            }

            //On récupère l'abilité ayant les dégats Maximum
            for(int i=0; i<abilities_usable.size();i++){
                if(abilities_usable[i]->getDegats()>damage){
                	damage=liste_abilities[i]->getDegats();
			attackMax=i;
                }
            }
	    if(abilities_usable[attackMax]->getUseDistance()>=distance){
	    	engine::AttackCommand* attack=new engine::AttackCommand(character,target,abilities_usable[attackMax]->getName());
                Engine.addCommand(3,attack);
                Engine.update();
	    }
	    else{

                //std::cout<<"Ok !"<<std::endl;
                
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
        	Engine.addCommand(1,move_list[i_min]);
        	Engine.update();
                std::cout<<"J'effectue mon meilleur déplacement..."<<std::endl;

		distance=std::abs((int)(chars[target]->getPosition().getX()-chars[character]->getPosition().getX())) + std::abs((int)(chars[character]->getPosition().getY()-chars[target]->getPosition().getY()));
		//std::cout<<" la cible est en "<<chars[target]->getPosition().getX()<<"   "<<chars[target]->getPosition().getY()<<"le character 0 est en "<<chars[0]->getPosition().getX()<<"  "<<chars[0]->getPosition().getY()<<std::endl;
		if(abilities_usable[attackMax]->getUseDistance()>=distance){
                    engine::AttackCommand* attack=new engine::AttackCommand(character,target,abilities_usable[attackMax]->getName());
                    //std::cout<<"target : "<<target<<"character : "<<character<<"le iop est en   "<<chars[target]->getPosition().getX()<<"   "<<chars[target]->getPosition().getY()<<"le sram est en   "<<chars[character]->getPosition().getX()<<"   "<<chars[character]->getPosition().getY()<<"     la distance est de "<<distance<<"     jattaque le sortilege apres le deplacement"<<std::endl;
                    Engine.addCommand(3,attack);
                    Engine.update();
	    	}
		else{
			damage=0;
			for(int i=0; i<abilities_usable.size();i++){
                		if(abilities_usable[i]->getDegats()>damage and abilities_usable[i]->getUseDistance()>=distance){
                			damage=liste_abilities[i]->getDegats();
					attackMax=i;
				}
                	}
			engine::AttackCommand* attack=new engine::AttackCommand(character,target,abilities_usable[attackMax]->getName());
			//std::cout<<"jattaque le coup de baton apres le deplacement"<<std::endl;
                	Engine.addCommand(3,attack);
                	Engine.update();
                }

	    }


        }



}

void HeuristicAI::stateChanged(const state::Event& event){
    characterMap.update(current_state,character);
	//std::cout<<"le character 0 est en "<<current_state.getCharacters()->getElementList()[0]->getPosition().getX()<<"  "<<current_state.getCharacters()->getElementList()[0]->getPosition().getY()<<std::endl;
}
