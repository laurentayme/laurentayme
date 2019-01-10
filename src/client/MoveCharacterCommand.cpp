/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include "state.h"
#include "engine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>



using namespace engine;


MoveCharacterCommand::MoveCharacterCommand(int character, int vectX, int vectY){
    this->character=character;
    this->vectX=vectX;
    this->vectY=vectY;
}

MoveCharacterCommand::~MoveCharacterCommand(){
}


CommandTypeId MoveCharacterCommand::getTypeId() const {
    return(CommandTypeId::MOVE_CHARACTER);
}

void MoveCharacterCommand::execute(state::State& act_state){
	std::cout<<"VECTX : "<<vectX<<"  VECTY : "<<vectY<<std::endl;
	if(vectX==0 and vectY==0){
		std::cout<<"Reste sur place "<<std::endl;
	}
	
	else{
	   	//Récupération de la liste de characters
	   	 std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();

		//Récupération de la liste des obstacles landscape
		std::vector<state::Element*> lands=act_state.getLandscape()->getElementList();



	    	//On récupère la position actuelle du Character
	   	 state::Position pos=chars[character]->getPosition();

		//On récupère la position désirée
		state::Position posFinal;
		posFinal.setX(pos.getX()+vectX);
		posFinal.setY(pos.getY()+vectY);
	    	//On récupère les dimensions de la carte
	    	size_t longueur=act_state.getMap()->getHeight();
	    	size_t largeur=act_state.getMap()->getWidth();

		// Déclaration itérateur
		//std::vector<state::Element*>::iterator<state::Element*> it;

		// Déclaration de la position de la case où l'on va vérifier si un obstacle y est
		state::Position posMap;
		posMap.setX(pos.getX());
		posMap.setY(pos.getY());

	///////////////////////////////////////////////////////////solution actuelle///////////////////////////////////////////////////:	
			if(chars[character]->getPM()>0){
			int tab[2*chars[character]->getPM()+1][2*chars[character]->getPM()+1];
			tab[chars[character]->getPM()+1][chars[character]->getPM()+1]=0;
			for(size_t i=0;i<2*chars[character]->getPM()+1;i++){
				for(size_t j=0;j<2*chars[character]->getPM()+1;j++){
					tab[i][j]=0;
					if(pos.getX()-chars[character]->getPM()+i<=0 or pos.getX()-chars[character]->getPM()+i>=longueur or pos.getY()-chars[character]->getPM()+j<=0 or pos.getY()-chars[character]->getPM()+j>=largeur){
						tab[i][j]=1;
					}
					//Vérification d'obstacle
					for(auto it = lands.begin(); it != lands.end(); ++it){
	    					if((*it)->getPosition().getX()==pos.getX()-chars[character]->getPM()+i and (*it)->getPosition().getY()==pos.getY()-chars[character]->getPM()+j){
								tab[i][j]=1;
						}
					}
					//Vérification de personnage
					for(auto it = chars.begin(); it != chars.end(); ++it){
	    					if((*it)->getPosition().getX()==pos.getX()-chars[character]->getPM()+i and (*it)->getPosition().getY()==pos.getY()-chars[character]->getPM()+j and (*it)!=chars[character]){
							tab[i][j]=1;
						}
					}
				}
			}
		
			for(size_t i=0;i<2*chars[character]->getPM()+1;i++){
				for(size_t j=0;j<2*chars[character]->getPM()+1;j++){
					//std::cout<<tab[i][j];
				}
				//std::cout<<std::endl;
			}

			int pmMax=chars[character]->getPM();
			int pm=chars[character]->getPM();
			state::Position posAct=pos;
			int diff=abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY());
			int posAct_tabx=pmMax;
			int posAct_taby=pmMax;	
			std::vector<state::Position> path;
			path.push_back(posAct);
			std::vector<state::Position> pathMem;
			pathMem.push_back(posAct);
			int indice=0;
			int nbPosUsed=pm;
			int diff2;
			int NbPosMin=diff;
			bool north,south,east,west;
		
			//std::cout<<"x depart : "<<pos.getX()<<"  y depart : "<<pos.getY()<<std::endl;
			//std::cout<<"x voulu : "<<pos.getX()+vectX<<"  y voulu : "<<pos.getY()+vectY<<std::endl;

			while(pmMax>=pm){

				while(pm>0){
					//Si deplacement plus selon X
					if(abs(vectX)>=abs(vectY)){
						//Si deplacement plus Nord
						if(vectX<0){
							if(tab[posAct_tabx-1][posAct_taby]==0){
								posAct.setX(posAct.getX()-1);
								posAct_tabx=posAct_tabx-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX+1;
								north=true;
								south=false;
								east=false;
								west=false;
								//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
				


							else if(tab[posAct_tabx][posAct_taby-1]==0){
								posAct.setY(posAct.getY()-1);
								posAct_taby=posAct_taby-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY+1;
								north=false;
								south=false;
								east=false;
								west=true;
								//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

							}
							else if(tab[posAct_tabx][posAct_taby+1]==0){
								posAct.setY(posAct.getY()+1);
								posAct_taby=posAct_taby+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY-1;
								north=false;
								south=false;
								east=true;
								west=false;
								//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}

							else if(tab[posAct_tabx+1][posAct_taby]==0){
								posAct.setX(posAct.getX()+1);
								posAct_tabx=posAct_tabx+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX-1;
								north=false;
								south=true;
								east=false;
								west=false;
								//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
							else{
								break;
							}
							if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
								break;
							}
						}
						// Si deplacement plus Sud
						else{
							if(tab[posAct_tabx+1][posAct_taby]==0){
								posAct.setX(posAct.getX()+1);
								posAct_tabx=posAct_tabx+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX-1;
								north=false;
								south=true;
								east=false;
								west=false;
								//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}

							else if(tab[posAct_tabx][posAct_taby-1]==0){
								posAct.setY(posAct.getY()-1);
								posAct_taby=posAct_taby-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY+1;
								north=false;
								south=false;
								east=false;
								west=true;
								//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

							}
							else if(tab[posAct_tabx][posAct_taby+1]==0){
								posAct.setY(posAct.getY()+1);
								posAct_taby=posAct_taby+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY-1;
								north=false;
								south=false;
								east=true;
								west=false;
								//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
						
							else if(tab[posAct_tabx-1][posAct_taby]==0){
								posAct.setX(posAct.getX()-1);
								posAct_tabx=posAct_tabx-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX+1;
								north=true;
								south=false;
								east=false;
								west=false;
								//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
							else{
								break;
							}
							if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
								break;
							}
					
						}
					}
					// Si deplacement plus selon Y
					else{
						// Si deplacement selon ouest
						if(vectY<0){


							if(tab[posAct_tabx][posAct_taby-1]==0){
								posAct.setY(posAct.getY()-1);
								posAct_taby=posAct_taby-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY+1;
								north=false;
								south=false;
								east=false;
								west=true;
								//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

							}
							else if(tab[posAct_tabx-1][posAct_taby]==0){
								posAct.setX(posAct.getX()-1);
								posAct_tabx=posAct_tabx-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX+1;
								north=true;
								south=false;
								east=false;
								west=false;
								//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
				
							else if(tab[posAct_tabx+1][posAct_taby]==0){
								posAct.setX(posAct.getX()+1);
								posAct_tabx=posAct_tabx+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX-1;
								north=false;
								south=true;
								east=false;
								west=false;
								//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}


						
							else if(tab[posAct_tabx][posAct_taby+1]==0){
								posAct.setY(posAct.getY()+1);
								posAct_taby=posAct_taby+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY-1;
								north=false;
								south=false;
								east=true;
								west=false;
								//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}
							else{
								break;
							}
							if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
								break;
							}
						}
						// Si deplacement plus selon est
						else{
							if(tab[posAct_tabx][posAct_taby+1]==0){
								posAct.setY(posAct.getY()+1);
								posAct_taby=posAct_taby+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY-1;
								north=false;
								south=false;
								east=true;
								west=false;
								//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}

							else if(tab[posAct_tabx+1][posAct_taby]==0){
								posAct.setX(posAct.getX()+1);
								posAct_tabx=posAct_tabx+1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX-1;
								north=false;
								south=true;
								east=false;
								west=false;
								//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}

							else if(tab[posAct_tabx-1][posAct_taby]==0){
								posAct.setX(posAct.getX()-1);
								posAct_tabx=posAct_tabx-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectX=vectX+1;
								north=true;
								south=false;
								east=false;
								west=false;
								//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
							}


							else if(tab[posAct_tabx][posAct_taby-1]==0){
								posAct.setY(posAct.getY()-1);
								posAct_taby=posAct_taby-1;
								path.push_back(posAct);
								indice=indice+1;
								pm=pm-1;
								tab[posAct_tabx][posAct_taby]=1;
								vectY=vectY+1;
								north=false;
								south=false;
								east=false;
								west=true;
								//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

							}
						
							else{
								break;
							}
							if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
								break;
							}
					
						}
					}
			
			
				//std::cout<<"pm1="<<pm<<std::endl;
				}

			
				diff2=abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY());
				if(diff2<diff and indice<=nbPosUsed){
					diff=diff2;
					//std::cout<<"difference pos ini final : "<<diff<<std::endl;
					nbPosUsed=indice;
					//std::cout<<"nbre positions utilisees : "<<nbPosUsed<<std::endl;
					if(pathMem.size()<path.size()){
						for(size_t u=0;u<pathMem.size();u++){
							pathMem[u]=path[u];
						}
						for(size_t j=pathMem.size();j<path.size();j++){
							pathMem.push_back(path[j]);
						}
					}
					else if(pathMem.size()>path.size()){
						while(path.size()>pathMem.size()){
							pathMem.pop_back();
						}
						for(size_t j=0;j<path.size();j++){
							pathMem[j]=path[j];
						} 
					}
					else{
						for(size_t j=0;j<path.size();j++){
							pathMem[j]=path[j];
						}
					}
					if((diff==0) and (nbPosUsed==NbPosMin)){
					break;

					}
				}
				if(north==true){
					vectX=vectX-1;
				}
				if(south==true){
					vectX=vectX+1;
				}
				if(east==true){
					vectY=vectY+1;
				}
				if(west==true){
					vectY=vectY-1;
				}
				path.pop_back();
				posAct=path[path.size()-1];
				posAct_tabx=posAct.getX()-pos.getX()+pmMax;
				posAct_taby=posAct.getY()-pos.getY()+pmMax;
				//path.push_back(posAct);
				pm=pm+1;
				indice=indice-1;
				//std::cout<<"pm2="<<pm<<std::endl;

			}
			//std::cout<<" il y a "<<path.size()+1<<"positions "<<std::endl;
			//std::cout<<" il y a "<<pathMem.size()<<"positions en memoire"<<std::endl;
			for(size_t k=1;k<pathMem.size();k++){
				state::Position& posRef=pathMem[k];
				//std::cout<<"deplacement "<<k<<" : x= "<<posRef.getX()<<"  y= "<<posRef.getY()<<std::endl;
		                act_state.getCharacters()->setElementMove(character,0);

		                act_state.getCharacters()->setElement(posRef,character);
				act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
			
			

			}
			//std::cout<<" il y a "<<pathMem.size()<<"positions en memoire"<<std::endl;
			if(pathMem.size()>=2){
				if(pathMem[pathMem.size()-1].getX()-pathMem[pathMem.size()-2].getX()==-1){
					this->direction=1;
					act_state.getCharacters()->setElementDirection(direction,character);
				}
				if(pathMem[pathMem.size()-1].getX()-pathMem[pathMem.size()-2].getX()==1){
					this->direction=3;
					act_state.getCharacters()->setElementDirection(direction,character);
				}
				if(pathMem[pathMem.size()-1].getY()-pathMem[pathMem.size()-2].getY()==-1){
					this->direction=2;
					act_state.getCharacters()->setElementDirection(direction,character);
				}
				if(pathMem[pathMem.size()-1].getY()-pathMem[pathMem.size()-2].getY()==1){
					this->direction=4;
					act_state.getCharacters()->setElementDirection(direction,character);
				}
			}
			//std::cout<<" dans la direction :  "<<this->direction<<std::endl;
		
		
		}
		//std::cout<<"x actuel : "<<chars[character]->getPosition().getX()<<"  y actuel : "<<chars[character]->getPosition().getY()<<std::endl;
	}
}



void MoveCharacterCommand::execute(state::State& act_state, engine::Engine& engine){

   	//Récupération de la liste de characters
   	 std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();

	//Récupération de la liste des obstacles landscape
	std::vector<state::Element*> lands=act_state.getLandscape()->getElementList();



    	//On récupère la position actuelle du Character
   	 state::Position pos=chars[character]->getPosition();

	//On récupère la position désirée
	state::Position posFinal;
	posFinal.setX(pos.getX()+vectX);
	posFinal.setY(pos.getY()+vectY);

    	//On récupère les dimensions de la carte
    	size_t longueur=act_state.getMap()->getHeight();
    	size_t largeur=act_state.getMap()->getWidth();

	// Déclaration itérateur
	//std::vector<state::Element*>::iterator<state::Element*> it;

	// Déclaration de la position de la case où l'on va vérifier si un obstacle y est
	state::Position posMap;
	posMap.setX(pos.getX());
	posMap.setY(pos.getY());

///////////////////////////////////////////////////////////solution actuelle///////////////////////////////////////////////////:	
	if(chars[character]->getPM()>0){
		int tab[2*chars[character]->getPM()+1][2*chars[character]->getPM()+1];
		tab[chars[character]->getPM()+1][chars[character]->getPM()+1]=0;
		for(size_t i=0;i<2*chars[character]->getPM()+1;i++){
			for(size_t j=0;j<2*chars[character]->getPM()+1;j++){
				tab[i][j]=0;
				if(pos.getX()-chars[character]->getPM()+i<=0 or pos.getX()-chars[character]->getPM()+i>=longueur or pos.getY()-chars[character]->getPM()+j<=0 or pos.getY()-chars[character]->getPM()+j>=largeur){
					tab[i][j]=1;
				}
				//Vérification d'obstacle
				for(auto it = lands.begin(); it != lands.end(); ++it){
    					if((*it)->getPosition().getX()==pos.getX()-chars[character]->getPM()+i and (*it)->getPosition().getY()==pos.getY()-chars[character]->getPM()+j){
							tab[i][j]=1;
					}
				}
				//Vérification de personnage
				for(auto it = chars.begin(); it != chars.end(); ++it){
    					if((*it)->getPosition().getX()==pos.getX()-chars[character]->getPM()+i and (*it)->getPosition().getY()==pos.getY()-chars[character]->getPM()+j and (*it)!=chars[character]){
						tab[i][j]=1;
					}
				}
			}
		}
		
		for(size_t i=0;i<2*chars[character]->getPM()+1;i++){
			for(size_t j=0;j<2*chars[character]->getPM()+1;j++){
				//std::cout<<tab[i][j];
			}
			//std::cout<<std::endl;
		}

		int pmMax=chars[character]->getPM();
		int pm=chars[character]->getPM();
		state::Position posAct=pos;
		int diff=abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY());
		int posAct_tabx=pmMax;
		int posAct_taby=pmMax;	
		std::vector<state::Position> path;
		path.push_back(posAct);
		std::vector<state::Position> pathMem;
		pathMem.push_back(posAct);
		int indice=0;
		int nbPosUsed=pm;
		int diff2;
		int NbPosMin=diff;
		bool north,south,east,west;
		
		//std::cout<<"x depart : "<<pos.getX()<<"  y depart : "<<pos.getY()<<std::endl;
		//std::cout<<"x voulu : "<<pos.getX()+vectX<<"  y voulu : "<<pos.getY()+vectY<<std::endl;

		while(pmMax>=pm){

			while(pm>0){
				//Si deplacement plus selon X
				if(abs(vectX)>=abs(vectY)){
					//Si deplacement plus Nord
					if(vectX<0){
						if(tab[posAct_tabx-1][posAct_taby]==0){
							posAct.setX(posAct.getX()-1);
							posAct_tabx=posAct_tabx-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX+1;
							north=true;
							south=false;
							east=false;
							west=false;
							//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
				


						else if(tab[posAct_tabx][posAct_taby-1]==0){
							posAct.setY(posAct.getY()-1);
							posAct_taby=posAct_taby-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY+1;
							north=false;
							south=false;
							east=false;
							west=true;
							//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

						}
						else if(tab[posAct_tabx][posAct_taby+1]==0){
							posAct.setY(posAct.getY()+1);
							posAct_taby=posAct_taby+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY-1;
							north=false;
							south=false;
							east=true;
							west=false;
							//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}

						else if(tab[posAct_tabx+1][posAct_taby]==0){
							posAct.setX(posAct.getX()+1);
							posAct_tabx=posAct_tabx+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX-1;
							north=false;
							south=true;
							east=false;
							west=false;
							//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
						else{
							break;
						}
						if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
							break;
						}
					}

					// Si deplacement plus Sud
					else{
						if(tab[posAct_tabx+1][posAct_taby]==0){
							posAct.setX(posAct.getX()+1);
							posAct_tabx=posAct_tabx+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX-1;
							north=false;
							south=true;
							east=false;
							west=false;
							//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}

						else if(tab[posAct_tabx][posAct_taby-1]==0){
							posAct.setY(posAct.getY()-1);
							posAct_taby=posAct_taby-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY+1;
							north=false;
							south=false;
							east=false;
							west=true;
							//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

						}
						else if(tab[posAct_tabx][posAct_taby+1]==0){
							posAct.setY(posAct.getY()+1);
							posAct_taby=posAct_taby+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY-1;
							north=false;
							south=false;
							east=true;
							west=false;
							//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
						
						else if(tab[posAct_tabx-1][posAct_taby]==0){
							posAct.setX(posAct.getX()-1);
							posAct_tabx=posAct_tabx-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX+1;
							north=true;
							south=false;
							east=false;
							west=false;
							//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
						else{
							break;
						}
						if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
							break;
						}
					
					}
				}
				// Si deplacement plus selon Y
				else{
					// Si deplacement selon ouest
					if(vectY<0){


						if(tab[posAct_tabx][posAct_taby-1]==0){
							posAct.setY(posAct.getY()-1);
							posAct_taby=posAct_taby-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY+1;
							north=false;
							south=false;
							east=false;
							west=true;
							//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

						}
						else if(tab[posAct_tabx-1][posAct_taby]==0){
							posAct.setX(posAct.getX()-1);
							posAct_tabx=posAct_tabx-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX+1;
							north=true;
							south=false;
							east=false;
							west=false;
							//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
				
						else if(tab[posAct_tabx+1][posAct_taby]==0){
							posAct.setX(posAct.getX()+1);
							posAct_tabx=posAct_tabx+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX-1;
							north=false;
							south=true;
							east=false;
							west=false;
							//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}


						
						else if(tab[posAct_tabx][posAct_taby+1]==0){
							posAct.setY(posAct.getY()+1);
							posAct_taby=posAct_taby+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY-1;
							north=false;
							south=false;
							east=true;
							west=false;
							//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}
						else{
							break;
						}
						if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
							break;
						}
					}
					// Si deplacement plus selon est
					else{
						if(tab[posAct_tabx][posAct_taby+1]==0){
							posAct.setY(posAct.getY()+1);
							posAct_taby=posAct_taby+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY-1;
							north=false;
							south=false;
							east=true;
							west=false;
							//std::cout<<"east"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}

						else if(tab[posAct_tabx+1][posAct_taby]==0){
							posAct.setX(posAct.getX()+1);
							posAct_tabx=posAct_tabx+1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX-1;
							north=false;
							south=true;
							east=false;
							west=false;
							//std::cout<<"south"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}

						else if(tab[posAct_tabx-1][posAct_taby]==0){
							posAct.setX(posAct.getX()-1);
							posAct_tabx=posAct_tabx-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectX=vectX+1;
							north=true;
							south=false;
							east=false;
							west=false;
							//std::cout<<"north"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;
						}


						else if(tab[posAct_tabx][posAct_taby-1]==0){
							posAct.setY(posAct.getY()-1);
							posAct_taby=posAct_taby-1;
							path.push_back(posAct);
							indice=indice+1;
							pm=pm-1;
							tab[posAct_tabx][posAct_taby]=1;
							vectY=vectY+1;
							north=false;
							south=false;
							east=false;
							west=true;
							//std::cout<<"west"<<"position x : "<<posAct.getX()<<"position y : "<<posAct.getY()<<"position tableau x :"<<posAct_tabx<<"position tableau y :"<<posAct_taby<<std::endl;

						}
						
						else{
							break;
						}
						if((abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY()))==0){
							break;
						}
					
					}
				}
			
			
			//std::cout<<"pm1="<<pm<<std::endl;
			}

			
			diff2=abs(posFinal.getX()-posAct.getX()) + abs(posFinal.getY()-posAct.getY());
			if(diff2<diff and indice<=nbPosUsed){
				diff=diff2;
				//std::cout<<"difference pos ini final : "<<diff<<std::endl;
				nbPosUsed=indice;
				//std::cout<<"nbre positions utilisees : "<<nbPosUsed<<std::endl;
				if(pathMem.size()<path.size()){
					for(size_t u=0;u<pathMem.size();u++){
						pathMem[u]=path[u];
					}
					for(size_t j=pathMem.size();j<path.size();j++){
						pathMem.push_back(path[j]);
					}
				}
				else if(pathMem.size()>path.size()){
					while(path.size()<pathMem.size()){
						pathMem.pop_back();
					}
					for(size_t j=0;j<path.size();j++){
						pathMem[j]=path[j];
					} 
				}
				else{
					for(size_t j=0;j<path.size();j++){
						pathMem[j]=path[j];
					}
				}
				if((diff==0) and (nbPosUsed==NbPosMin)){
				break;

				}
			}
			if(north==true){
				vectX=vectX-1;
			}
			if(south==true){
				vectX=vectX+1;
			}
			if(east==true){
				vectY=vectY+1;
			}
			if(west==true){
				vectY=vectY-1;
			}
			path.pop_back();
			posAct=path[path.size()-1];
			posAct_tabx=posAct.getX()-pos.getX()+pmMax;
			posAct_taby=posAct.getY()-pos.getY()+pmMax;
			//path.push_back(posAct);
			pm=pm+1;
			indice=indice-1;
			//std::cout<<"pm2="<<pm<<std::endl;

		}
		//std::cout<<" il y a "<<path.size()+1<<"positions "<<std::endl;
		//std::cout<<" il y a "<<pathMem.size()<<"positions en memoire"<<std::endl;
		for(size_t k=1;k<pathMem.size();k++){
			state::Position& posRef=pathMem[k];
			//std::cout<<"deplacement "<<k<<" : x= "<<posRef.getX()<<"  y= "<<posRef.getY()<<std::endl;
                	
                        
                        
                        //Tentative gestion du Temps//
                        sf::Clock clock;
                        sf::Time t=sf::seconds(0.1f);
                        clock.restart();
                        while(clock.getElapsedTime()<t){
                            
                            //Coordonnées Intermédiaires
                            int x_inter=(posRef.getX()-act_state.getCharacters()->getElementList()[character]->getPosition().getX());
                            int y_inter=(posRef.getY()-act_state.getCharacters()->getElementList()[character]->getPosition().getY());
                        
                            //Pixel Position
                            //int Pixel_xInter=650+;
                            //int Pixel_yInter=30+;
                            act_state.getCharacters()->setElementMove(character,1);
                            act_state.getCharacters()->setLocation(x_inter,y_inter,character);
                            
                        }
                        act_state.getCharacters()->setElementMove(character,0);

                        act_state.getCharacters()->setElement(posRef,character);
			act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
			engine.update();
			

		}
		//std::cout<<" il y a "<<pathMem.size()<<"positions en memoire"<<std::endl;
		if(pathMem.size()>=2){
			if(pathMem[pathMem.size()-1].getX()-pathMem[pathMem.size()-2].getX()==-1){
				this->direction=1;
				act_state.getCharacters()->setElementDirection(direction,character);
			}
			if(pathMem[pathMem.size()-1].getX()-pathMem[pathMem.size()-2].getX()==1){
				this->direction=3;
				act_state.getCharacters()->setElementDirection(direction,character);
			}
			if(pathMem[pathMem.size()-1].getY()-pathMem[pathMem.size()-2].getY()==-1){
				this->direction=2;
				act_state.getCharacters()->setElementDirection(direction,character);
			}
			if(pathMem[pathMem.size()-1].getY()-pathMem[pathMem.size()-2].getY()==1){
				this->direction=4;
				act_state.getCharacters()->setElementDirection(direction,character);
			}
		}
		//std::cout<<" dans la direction :  "<<this->direction<<std::endl;
		
		
	}
	//std::cout<<"x actuel : "<<chars[character]->getPosition().getX()<<"  y actuel : "<<chars[character]->getPosition().getY()<<std::endl;
	
}


int MoveCharacterCommand::getVectX() const{
    return(vectX);
}

int MoveCharacterCommand::getVectY() const{
    return(vectY);
}

Json::Value MoveCharacterCommand::serialize(){
	Json::Value cmd;
	cmd[" Type "]=this->getTypeId();
	cmd[" Character "]=this->character;
	std::cout<<"En serialisation X : "<<this->getVectX()<<"  ou  : "<<vectX<<"   En serialisation Y : "<<this->getVectY()<<std::endl;
	cmd[" X Move "]=this->getVectX();
	cmd[" Y Move "]=this->getVectY();
	return cmd;

}

void MoveCharacterCommand::deserialize(Json::Value cmd){
	this->character=cmd[" Character "].asInt();
	this->vectX=cmd[" X Move "].asInt();
	this->vectY=cmd[" Y Move "].asInt();
}

