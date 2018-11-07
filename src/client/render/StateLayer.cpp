#include <stdio.h>
#include "state.h"
#include "render.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace render;
using namespace state;

StateLayer::StateLayer (const state::State& state) : state(state) {
	StateTileSet* tileSet = new StateTileSet;
	//tileset=tileSet;
	
	

}

void StateLayer::initSurface (){
	surface->initQuads(1);
	//surface->loadTexture("");
	
	std::vector<Element*> elmt_list_menu= state.getMenu()->getElementList();
        sf::Text text;
        sf::Text textpa;
        sf::Text textpm;
        sf::Font font;


//Menu de State
       try{
            Space* state_ptr=new Space(1);
            state_ptr->setTypeId(2);
            elmt_list_menu.push_back(state_ptr);
        }
        catch(const char* e){
            std::cout<<"Exception: "<<e<<std::endl;
        }
        
        //Affichage de l'état
      /*  if(!font.loadFromFile("res/font.TTF")){
            throw "Error Font Loading !";
        }
        
        text.setFont(font);
        
        text.setString(std::to_string(c_ptr->getPV()));
        text.setCharacterSize(24);
        text.setColor(sf::Color::White);
        text.setPosition(240,86*7.4);
        
        textpa.setFont(font);
        
        textpa.setString(std::to_string(c_ptr->getPA()));
        textpa.setCharacterSize(23);
        textpa.setColor(sf::Color::White);
        textpa.setPosition(297,86*8.43);
        
        textpm.setFont(font);
        textpm.setString(std::to_string(c_ptr->getPM()));
        textpm.setCharacterSize(23);
        textpm.setColor(sf::Color::White);
        textpm.setPosition(220,86*8.44);*/


	//State
       // ElementTab& tab_ref3=elmt_tab3;
       // ElementTabLayer elmt_tab_layer3(tab_ref3);


	/* window.draw(*elmt_tab_layer3.getSurface());
	window.draw(text);
        window.draw(textpa);
        window.draw(textpm);*/
        
	
	
	
	
}

void StateLayer::stateChanged(const state::Event& event){
	std::cout<<"Un evenement a eu lieu et la couche StateLayer est au courant"<<std::endl;
	initSurface();
	
}
