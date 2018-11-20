/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include "state.h"
#include "render.h"
#include "engine.h"
#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>



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

   	//Récupération de la liste de characters
   	 std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();

	//Récupération de la liste des obstacles landscape
	std::vector<state::Element*> lands=act_state.getLandscape()->getElementList();

    	//On récupère la position actuelle du Character
   	 state::Position pos=chars[character]->getPosition();

    	//On récupère les dimensions de la carte
    	size_t longueur=act_state.getMap()->getHeight();
    	size_t largeur=act_state.getMap()->getWidth();

	// Déclaration itérateur
	//std::vector<state::Element*>::iterator<state::Element*> it;

	// Déclaration de la position de la case où l'on va vérifier si un obstacle y est
	state::Position posMap;
	posMap.setX(pos.getX());
	posMap.setY(pos.getY());

	if(chars[character]->getPM()>0){

    		if(vectY<=0){
			//West Direction
			this->direction=2;

      			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
      			act_state.getCharacters()->setElementDirection(direction,character);
      			//////////////////

        		for(int i=0; i<abs(vectY);i++){
                            //Test Horloge//
                            
                                //Démarrage Chrono
                                sf::Clock clock;
                            
          			if(pos.getY()<largeur){ //Vérification Bordure de Map
					bool obstacle=false;
					//Vérification d'obstacle
					for(auto it = lands.begin(); it != lands.end(); ++it){
    						if((*it)->getPosition().getX()==posMap.getX() and (*it)->getPosition().getY()==(posMap.getY()-1)){
							obstacle=true;
						}
					}
					bool filledcase=false;
					//Vérification de personnage
					for(auto it = chars.begin(); it != chars.end(); ++it){
    						if((*it)->getPosition().getX()==posMap.getX() and (*it)->getPosition().getY()==(posMap.getY()-1) and (*it)!=chars[character]){
							filledcase=true;
						}
					}
					if(obstacle==false and filledcase==false){
              					pos.setY(pos.getY()-1);
						posMap.setY(posMap.getY()-1);
              					state::Position& posRef=pos;
                                                
                                                //Changement de Tile//
                                                /*act_state.getCharacters()->setElementMove(character,true);
                                                
                                                //On place le personnage entre deux cases
                                                
                                                int char_x=act_state.getCharacters()->getElementList()[character]->getPosition().getX();
                                                int char_y=act_state.getCharacters()->getElementList()[character]->getPosition().getY();
                                                
                                                state::Element* elmt= act_state.getCharacters()->getElementList()[character];
                                                std::shared_ptr<render::TileSet> tileset=act_state.getCharacters()->getTileset();
                                                
                                                
                                                int charPix_X=(120/2.5)*(char_y-char_x)-tileSet.getCellWidth(*elmt_list[i])/2+650+120/2.5;
                                                int charPix_Y=(60/2.5)*(char_x+char_y)+40+60/2.5+0.1*tileSet.getCellHeight(*elmt_list[i]));
                                                
                                                act_state.getCharacters()->getElementList()[character]->setLoc(,);
                                                
                                                //Wait un certain Temps
                                                */
              					act_state.getCharacters()->setElement(posRef,character);
						act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
              					//std::this_thread::sleep_for(std::chrono::nanoseconds(100));
					}

          			}
          			else if(pos.getY()>largeur){
             				throw "Déplacement vers l'Ouest Impossible !";
          			}
        		}

			if(vectX>0){
				//South Direction
        			this->direction=3;

          			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
          			act_state.getCharacters()->setElementDirection(this->direction,character);
                //std::cout<<"La direction vient detre modifiée et vaut :"<<direction<<std::endl;

          			for(int i=0; i<abs(vectX);i++){
            				if(pos.getX()<=longueur){ //Vérification Bordure de Map

						bool obstacle=false;
						//Vérification d'obstacle
						for(auto it = lands.begin(); it != lands.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()+1) and (*it)->getPosition().getY()==posMap.getY()){
							//obstacle=(*it)->isObstacle();
							obstacle=true;
							}
						}
						bool filledcase=false;
						//Vérification de personnage
						for(auto it = chars.begin(); it != chars.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()+1) and (*it)->getPosition().getY()==(posMap.getY()) and (*it)!=chars[character]){
								filledcase=true;
							}
						}
						if(obstacle==false and filledcase==false){
                					pos.setX(pos.getX()+1);
							posMap.setX(posMap.getX()+1);
                					state::Position& posRef=pos;
                					act_state.getCharacters()->setElement(posRef,character);
							act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
                                                        //std::this_thread::sleep_for(std::chrono::nanoseconds(100));
                                                }

					}
           		 		else if(pos.getX()>longueur){
                                            throw "Déplacement vers le Sud Impossible !";

            				}
          			}
        		}
			else if(vectX<0){
				//North Direction
         			this->direction=1;

          			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
          			act_state.getCharacters()->setElementDirection(direction,character);
                //std::cout<<"La direction vient detre modifiée et vaut :"<<direction<<std::endl;

          			for(int i=0; i<abs(vectX);i++){

            				if(pos.getX()<=longueur){ //Vérification Bordure de Map
						bool obstacle=false;
						//Vérification d'obstacle
						for(auto it = lands.begin(); it != lands.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()-1) and (*it)->getPosition().getY()==posMap.getY()){
							//obstacle=(*it)->isObstacle();
							obstacle=true;
							}
						}
						bool filledcase=false;
						//Vérification de personnage
						for(auto it = chars.begin(); it != chars.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()-1) and (*it)->getPosition().getY()==(posMap.getY()) and (*it)!=chars[character]){
								filledcase=true;
							}
						}
						if(obstacle==false and filledcase==false){
                					pos.setX(pos.getX()-1);
							posMap.setX(posMap.getX()-1);
                					state::Position& posRef=pos;
                					act_state.getCharacters()->setElement(posRef,character);
							act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
                                                        //std::this_thread::sleep_for(std::chrono::nanoseconds(100));
                                                }
						/*else if(obstacle==true){
							throw "un obstacle se trouve à cet endroit !";
						}
						else if(filledcase==false){
							throw "un personnage se trouve déjà à cet endroit !";
						}*/
           			 	}
					else if(pos.getX()<=0){
                				throw "Déplacement vers le Nord Impossible !";
            				}
				}
    			}
		}
		else if(vectY>0){
      			//East Direction
      			this->direction=4;

      			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
      			act_state.getCharacters()->setElementDirection(direction,character);
            //std::cout<<"La direction vient detre modifiée et vaut :"<<direction<<std::endl;
      			//////////////////

        		for(int i=0; i<abs(vectY);i++){
          			if(pos.getY()<largeur){ //Vérification Bordure de Map
					bool obstacle=false;
					//Vérification d'obstacle
					for(auto it = lands.begin(); it != lands.end(); ++it){
    						if((*it)->getPosition().getX()==posMap.getX() and (*it)->getPosition().getY()==(posMap.getY()+1)){
							//obstacle=(*it)->isObstacle();
							obstacle=true;
						}
					}
					bool filledcase=false;
						//Vérification de personnage
						for(auto it = chars.begin(); it != chars.end(); ++it){
    							if((*it)->getPosition().getX()==posMap.getX() and (*it)->getPosition().getY()==(posMap.getY()+1) and (*it)!=chars[character]){
								filledcase=true;
							}
						}
						if(obstacle==false and filledcase==false){
              					pos.setY(pos.getY()+1);
						posMap.setY(posMap.getY()+1);
              					state::Position& posRef=pos;
              					act_state.getCharacters()->setElement(posRef,character);
						act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
              					//std::this_thread::sleep_for(std::chrono::nanoseconds(100));
						}
						/*else if(obstacle==true){
							throw "un obstacle se trouve à cet endroit !";
						}
						else if(filledcase==false){
							throw "un personnage se trouve déjà à cet endroit !";
						}*/
          				}
         				else if(pos.getY()>largeur){
              					throw "Déplacement vers l'Ouest Impossible !";
          			}
        		}

        		if(vectX>0){
          			//South Direction
          			this->direction=3;

          			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
          			act_state.getCharacters()->setElementDirection(direction,character);
                //std::cout<<"La direction vient detre modifiée et vaut :"<<direction<<std::endl;

          			for(int i=0; i<abs(vectX);i++){
           				if(pos.getX()<=longueur){ //Vérification Bordure de Map
						bool obstacle=false;
						//Vérification d'obstacle
						for(auto it = lands.begin(); it != lands.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()+1) and (*it)->getPosition().getY()==posMap.getY()){
								//obstacle=(*it)->isObstacle();
								obstacle=true;
							}
						}
						bool filledcase=false;
						//Vérification de personnage
						for(auto it = chars.begin(); it != chars.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()+1) and (*it)->getPosition().getY()==posMap.getY() and (*it)!=chars[character]){
								filledcase=true;
							}
						}
						if(obstacle==false and filledcase==false){
                					pos.setX(pos.getX()+1);
							posMap.setX(posMap.getX()+1);
                					state::Position& posRef=pos;
                					act_state.getCharacters()->setElement(posRef,character);
							act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
                                                        //std::this_thread::sleep_for(std::chrono::nanoseconds(100));
                                                }
						/*else if(obstacle==true){
							throw "un obstacle se trouve à cet endroit !";
						}
						else if(filledcase==false){
							throw "un personnage se trouve déjà à cet endroit !";
						}*/
           				}
           				else if(pos.getX()>longueur){
                				throw "Déplacement vers le Sud Impossible !";
            				}
          			}
        		}
        		else if(vectX<0){
				//North Direction
         			this->direction=1;

          			std::vector<state::Element*> chars=act_state.getCharacters()->getElementList();
          			act_state.getCharacters()->setElementDirection(direction,character);
                //std::cout<<"La direction vient detre modifiée et vaut :"<<direction<<std::endl;

          			for(int i=0; i<abs(vectX);i++){
            				if(pos.getX()<=longueur){ //Vérification Bordure de Map
						bool obstacle=false;
						//Vérification d'obstacle
						for(auto it = lands.begin(); it != lands.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()-1) and (*it)->getPosition().getY()==posMap.getY()){
								obstacle=true;
							}
						}
						bool filledcase=false;
						//Vérification de personnage
						for(auto it = chars.begin(); it != chars.end(); ++it){
    							if((*it)->getPosition().getX()==(posMap.getX()-1) and (*it)->getPosition().getY()==posMap.getY() and (*it)!=chars[character]){
								filledcase=true;
							}
						}
						if(obstacle==false and filledcase==false){
                					pos.setX(pos.getX()-1);
							posMap.setX(posMap.getX()-1);
                					state::Position& posRef=pos;
                					act_state.getCharacters()->setElement(posRef,character);
							act_state.getCharacters()->setCharacterPM(character,chars[character]->getPM()-1);
                                                        //std::this_thread::sleep_for(std::chrono::nanoseconds(100));
                                                }

            				}
            				else if(pos.getX()<=0){
                				throw "Déplacement vers le Nord Impossible !";
           				}
          			}
       			}
    		}
	}
}
