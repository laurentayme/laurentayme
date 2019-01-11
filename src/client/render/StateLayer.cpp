#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace render;
using namespace state;

StateLayer::StateLayer (const state::State& state) : state(state) {
	std::shared_ptr<StateTileSet> tileseto;
	this->tileset=tileseto;
	
	

}

void StateLayer::initSurface (){

	std::vector<Element*> elmt_list_menu= state.getMenu()->getElementList();
	state::Element& e=*elmt_list_menu[0];
	Tile t1(0,0,1490,1053);
	const Tile& t=t1;
	//const Tile& t=tileset->getTile(e);
	TileSet& tileSet2= *tileset;
	StateTileSet statetileset;
	StateTileSet& to= statetileset;
	
	surface->initQuads(1);
	surface->loadTexture(statetileset.getImageFile());
	//std::cout<<"la taille maximale de surface est de : "<<surface.texture.getMaximumSize()<<std::endl;



        //Menu de State
        
                //Affichage de l'état
            if(!font.loadFromFile("res/font.TTF") or !font2.loadFromFile("res/fontDofus.ttf")){
                 throw "Error Font Loading !";
             }
       
            //Sram Vivant/ 
            if(state.getCharacters()->getElementList().size()>1){
                //PV Iop//
                textpv.setFont(font);
                textpv.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPV()));
                textpv.setCharacterSize(24);
                textpv.setColor(sf::Color::White);
                textpv.setPosition(240,86*7.4-25);
                /////////
                //PV Sram//
                 textpv_sram.setFont(font);
                 textpv_sram.setString(std::to_string(state.getCharacters()->getElementList()[1]->getPV()));
                 textpv_sram.setCharacterSize(18);
                 textpv_sram.setColor(sf::Color::White);
                 
                 if(state.getCharacters()->getElementList()[1]->getPV()<10){
                     textpv_sram.setPosition(154,130);
                 }
                 else{
                     textpv_sram.setPosition(142,130);
                 }
             }
             //Un Personnage Mort
            for(int i=0; i<state.getCharacters()->getElementList().size();i++){
                if(state.getCharacters()->getElementList()[0]->getStatut()==3){
                    textpv.setFont(font);
                    textpv.setString(std::to_string(0));
                    textpv.setCharacterSize(24);
                    textpv.setColor(sf::Color::White);
                    textpv.setPosition(240,86*7.4-25);  
                
                }
                else{
                    textpv_sram.setFont(font);
                    textpv_sram.setString(std::to_string(state.getCharacters()->getElementList()[i]->getPV()));
                    textpv_sram.setCharacterSize(18);
                    textpv_sram.setColor(sf::Color::White);
                    textpv_sram.setPosition(142,130);
                }
            
            }
                
             ///////////

             textpa.setFont(font);

             textpa.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPA()));
             textpa.setCharacterSize(23);
             textpa.setColor(sf::Color::White);
             textpa.setPosition(297,86*8.43-25);

             textpm.setFont(font);
             textpm.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPM()));
             textpm.setCharacterSize(23);
             textpm.setColor(sf::Color::White);
             if(state.getCharacters()->getElementList()[0]->getPM()>10){
                 textpm.setPosition(205,86*8.44-25);
             }
             else{
                 textpm.setPosition(220,86*8.44-25);
             } 
        
        
        

	const ElementTab* menu =state.getMenu();
	//const ElementTab& menu_ref=*menu;

	surface->setSpriteLocation(0,0,0,to,*menu);

	surface->setSpriteTexture(0,t,*menu);
		
}

void StateLayer::stateChanged(const state::Event& event){
    
        std::vector<Element*> elmt_list_menu= state.getMenu()->getElementList();
	state::Element& e=*elmt_list_menu[0];
        
        if(e.getTypeId()==2){
            //PV Iop//
            textpv.setFont(font);
            textpv.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPV()));
            textpv.setCharacterSize(24);
            textpv.setColor(sf::Color::White);
            textpv.setPosition(240,86*7.4-25);
            /////////

            //PV Sram//

            //Sram Vivant/ 
            if(state.getCharacters()->getElementList().size()>1){

                textpv_sram.setFont(font);
                textpv_sram.setString(std::to_string(state.getCharacters()->getElementList()[1]->getPV()));
                textpv_sram.setCharacterSize(18);
                textpv_sram.setColor(sf::Color::White);
                if(state.getCharacters()->getElementList()[1]->getPV()<10){
                    textpv_sram.setPosition(154,130);
                }
                else{
                    textpv_sram.setPosition(142,130);
                }

            }
            //Sram Mort
            else{
                textpv_sram.setFont(font);
                textpv_sram.setString(std::to_string(0));
                textpv_sram.setCharacterSize(18);
                textpv_sram.setColor(sf::Color::White);
                textpv_sram.setPosition(154,130);
            }
            ///////////

            textpa.setFont(font);

            textpa.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPA()));
            textpa.setCharacterSize(23);
            textpa.setColor(sf::Color::White);
            textpa.setPosition(297,86*8.43-25);

            textpm.setFont(font);
            textpm.setString(std::to_string(state.getCharacters()->getElementList()[0]->getPM()));
            textpm.setCharacterSize(23);
            textpm.setColor(sf::Color::White);
            if(state.getCharacters()->getElementList()[0]->getPM()>10){
                textpm.setPosition(205,86*8.44-25);
            }
            else{
                textpm.setPosition(220,86*8.44-25);
            }
        }
        
        
        
        else if (e.getTypeId()==6){
            textwin.setFont(font2);
            
            if(state.getCharacters()->getElementList()[0]->getStatut()!=3){
                textwin.setString("You Win !");
                textwin.setColor(sf::Color::Yellow);
            }
            else if(state.getCharacters()->getElementList()[0]->getStatut()==3){
                textwin.setString("You Loose...");
                textwin.setColor(sf::Color::Red);
            }
            
            
            textwin.setCharacterSize(100);
            textwin.setPosition(149*3,86*4);
            
            const ElementTab* menu =state.getMenu();
            //const ElementTab& menu_ref=*menu;
            StateTileSet statetileset;
            surface->setSpriteLocation(0,0,0,statetileset,*menu);
            Tile t1(0,0,1490,1053);
            surface->setSpriteTexture(0,t1,*menu);
        }
        else{
            const ElementTab* menu =state.getMenu();
            //const ElementTab& menu_ref=*menu;
            StateTileSet statetileset;
            surface->setSpriteLocation(0,0,0,statetileset,*menu);
            Tile t1(0,0,1490,1053);
            surface->setSpriteTexture(0,t1,*menu);
        }
        	
}

sf::Text StateLayer::getTextpv() const {
	return(textpv);
}

sf::Text StateLayer::getTextpvSram() const {
	return(textpv_sram);
}

sf::Text StateLayer::getTextpa() const {
	return(textpa);
}

sf::Text StateLayer::getTextpm() const {
	return(textpm);
}

sf::Font StateLayer::getFont() const {
	return(font);
}

sf::Font StateLayer::getFont2() const {
	return(font2);
}

sf::Text StateLayer::getTextwin() const{
    return (textwin);
}
