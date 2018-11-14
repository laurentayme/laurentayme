/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ai.h"
#include "engine.h"
#include <memory>
<<<<<<< HEAD
#include <stdlib.h>
#include <iostream>
||||||| merged common ancestors
=======
#include <stdlib.h>
#include <iostream>
#include <math.h>
>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88

using namespace ai;
using namespace std;


<<<<<<< HEAD
void AI::listCommands(const state::State& state, int character,std::vector<std::shared_ptr<engine::Command>>& move_list){
||||||| merged common ancestors
void AI::listCommands(const state::State& state, int character,std::vector<std::unique_ptr<engine::Command>>& move_list){
=======
void AI::listCommands(const state::State& state, int character,std::vector<engine::Command*>& move_list){
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
    
    std::vector<state::Element*> chars=state.getCharacters()->getElementList();
    //Obtention Nbre PM
    int pm=chars[character]->getPM();
    
    //Map Width
    int width=state.getMap()->getWidth();
    
    //Map Height
    int height=state.getMap()->getHeight();
    
    //On fait une boucle sur le nbre de PM du character
    /*for(int i=1; i<=pm;i++){
        
        //Vérification que le personnage pourra effectuer le(s) mouvement(s)//
        //////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
<<<<<<< HEAD
            if(chars[character]->getPosition().getX()>i+1){//Déplacement Nord
               move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,-i,0)));

                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
            if(chars[character]->getPosition().getX()>i+1){//Déplacement Nord
               move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,-i,0)));

                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
        
            //Déplacement Nord
            if(chars[character]->getPosition().getX()>i+1){
               engine::MoveCharacterCommand* move_north=new engine::MoveCharacterCommand(character,-i,0);
               move_list.push_back(move_north);
               //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,-i,0)));

               //Déplacement Est
                if(chars[character]->getPosition().getY()<=width-i){
                   //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 
                    engine::MoveCharacterCommand* move_east=new engine::MoveCharacterCommand(character,0,i);
                    move_list.push_back(move_east);
                   //Déplacement Sud
                   if(chars[character]->getPosition().getX()<=height-i){
                       //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));
                       engine::MoveCharacterCommand* move_south=new engine::MoveCharacterCommand(character,i,0);
                       move_list.push_back(move_south);
                       
                       
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
<<<<<<< HEAD
<<<<<<< HEAD
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
                   //Déplacement Sud Impossible
                   else{
                       if(chars[character]->getPosition().getY()>i+1){
                           //Déplacement Ouest
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west); 
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
                }
                else{//Déplacement Est Impossible
<<<<<<< HEAD
<<<<<<< HEAD
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
                    //Déplacement Sud
                    if(chars[character]->getPosition().getX()<=height-i){
                       //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));
                       engine::MoveCharacterCommand* move_south=new engine::MoveCharacterCommand(character,i,0);
                       move_list.push_back(move_south);
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
                   else{//Déplacement Sud Impossible
<<<<<<< HEAD
<<<<<<< HEAD
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
                       if(chars[character]->getPosition().getY()>i+1){
                           //Déplacement Ouest
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }

                }

            }
<<<<<<< HEAD
<<<<<<< HEAD
            else{//Déplacement Nord Impossible

                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
            else{//Déplacement Nord Impossible
                if(chars[character]->getPosition().getY()<=width-i){//Déplacement Est
                   move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 

                   if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
            //Déplacement Nord Impossible
            else{
                //Déplacement Est
                if(chars[character]->getPosition().getY()<=width-i){
                    //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand> (new engine::MoveCharacterCommand(character,0,i))); 
                    engine::MoveCharacterCommand* move_east=new engine::MoveCharacterCommand(character,0,i);
                    move_list.push_back(move_east);
                   //Déplacement Sud
                   if(chars[character]->getPosition().getX()<=height-i){
                       //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));
                       engine::MoveCharacterCommand* move_south=new engine::MoveCharacterCommand(character,i,0);
                       move_list.push_back(move_south);
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
<<<<<<< HEAD
<<<<<<< HEAD
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
                   //Déplacement Sud Impossible
                   else{
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
                }
<<<<<<< HEAD
<<<<<<< HEAD
                else{//Déplacement Est Impossible
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                else{//Déplacement Est Impossible
                    if(chars[character]->getPosition().getX()<=height-i){//Déplacement Sud
                       move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));

                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
||||||| merged common ancestors
=======

>>>>>>> f9cb8b644759ca4ebb14a1502e16a2fc6209bf88
                //Déplacement Est Impossible
                else{
                    //Déplacement Sud
                    if(chars[character]->getPosition().getX()<=height-i){
                       //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,i,0)));
                       engine::MoveCharacterCommand* move_south=new engine::MoveCharacterCommand(character,i,0);
                       move_list.push_back(move_south);
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }
<<<<<<< HEAD
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::shared_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
||||||| merged common ancestors
                   else{//Déplacement Sud Impossible
                       if(chars[character]->getPosition().getY()>i+1){//Déplacement Ouest
                           move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
=======
                   //Déplacement Sud Impossible
                   else{
                       //Déplacement Ouest
                       if(chars[character]->getPosition().getY()>i+1){
                           //move_list.push_back(std::unique_ptr<engine::MoveCharacterCommand>(new engine::MoveCharacterCommand(character,0,-i)));
                           engine::MoveCharacterCommand* move_west=new engine::MoveCharacterCommand(character,0,-i);
                           move_list.push_back(move_west);
>>>>>>> 330fe8f9d28ecb1a90a2a1445243b9cac34a7a12
                       }
                   }

                }
            }


    }*/
    //////////FIN Déplacement Personnage////////////
    ////////////////////////////////////////////////

	for(int i=-pm;i<=pm;i++){
		for(int j=-(pm-abs(i));j<=pm-abs(i);j++){
			if(chars[character]->getPosition().getX()+i<height and chars[character]->getPosition().getX()+i>1 and chars[character]->getPosition().getY()+j<width and chars[character]->getPosition().getY()+j>1){
                            
                            engine::MoveCharacterCommand* move = new engine::MoveCharacterCommand(character,i,j);
                            move_list.push_back(move);

			}
		}
	}



}




