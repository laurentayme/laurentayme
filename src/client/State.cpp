#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "state.h"
#include "json/json.h"
using namespace state;

/*State::State(ElementTab* tab,ElementTab* chara,ElementTab* men){
	carte=tab;
	characters=chara;
	menu=men;
}*/

ElementTab* State::getMap() const{
	return carte;
 }

ElementTab* State::getCharacters() const{
    return characters;
}

ElementTab* State::getRedMap() const{
	return red_map;
 }


ElementTab* State::getMenu() const{
    return (this->menu);
}

void State::setMap(ElementTab* map){
    this->carte=map;
}

void State::setCharacters(ElementTab* characters){
    this->characters=characters;
}

void State::setMenu(ElementTab* menu){
    this->menu=menu;
}


void State::setRedMap(ElementTab* red_map){
	this->red_map=red_map;
 }

void State::setLandscape(ElementTab* landscape){
    this->landscape=landscape;
}


ElementTab* State::getLandscape() const {
	return landscape;
 }

void State::setTour(int act_tour){
    tour=act_tour;
}

int State::getTour() const{
    return(tour);
}


void State::setWall(ElementTab* mur){
    this->wall=mur;
}

ElementTab* State::getWall() const{
    return(this->wall);
}

void State::LoadMapFromFile(std::string filePath){
    std::vector<Element*> new_elmt_list;
    std::vector<Element*> new_elmt_list_landscape;
    std::vector<Element*> new_elmt_list_wall;

    bool alive = true;
    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;
    std::ifstream test(filePath, std::ifstream::binary);
    bool parsingSuccessful = reader.parse( test, root, false );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << reader.getFormatedErrorMessages()
               << "\n";
    }

    /// Affichage Space Layer ///
    /////////////////////////////
    int c=root["layers"][0]["data"].size();
    //std::vector<int> space_list=root["layers"][0]["data"];
    for(int i=0;i<c;i++){
        int ord=i%11;
        int abs=i/11;
        //Pierre Bord de Map
        if (root["layers"][0]["data"][i].asInt()==4){
           Space* s_ptr=new Space(1);
           Position position(abs,ord);
           //Position posref=position;
           s_ptr->setPosition(position);
           new_elmt_list.push_back(s_ptr);
        }
        else{//Cas d'un Space "classique"
          Space* s_ptr=new Space(0);
          Position position(abs,ord);
          //Position posref=position;
          s_ptr->setPosition(position);
          new_elmt_list.push_back(s_ptr);

        }
    }



    /// Affichage Landscape Layer ///
    /////////////////////////////////
    int c_1=root["layers"][1]["data"].size();
    for(int i=0;i<c_1;i++){
        int ord=i%11;
        int abs=i/11;
        //Mur Bord de Map
        if (root["layers"][1]["data"][i].asInt()==1){
           Wall* w_ptr= new Wall;
           Position position(abs,ord);
           w_ptr->setPosition(position);
           new_elmt_list_wall.push_back(w_ptr);
        }
        //Stone classique
        else if (root["layers"][1]["data"][i].asInt()==3){
           Landscape* l_ptr=new Landscape;
           Position position(abs,ord);
           l_ptr->setPosition(position);
           l_ptr->setLandscapeType(0);
           new_elmt_list_landscape.push_back(l_ptr);
        }

        //Double Stone
        else if (root["layers"][1]["data"][i].asInt()==2){
          Landscape* l_ptr=new Landscape;
          Position position(abs,ord);
          l_ptr->setPosition(position);
          l_ptr->setLandscapeType(1);
          new_elmt_list_landscape.push_back(l_ptr);

        }
    }
    //////////////////////

    this->carte->setElementList(new_elmt_list);
    this->landscape->setElementList(new_elmt_list_landscape);
    this->wall->setElementList(new_elmt_list_wall);


    /////////////////////////////////
}

void State::setEtat(int etat){
    this->etat=etat;
}

int State::getEtat() const{
    return(etat);
}


State State::Clone(){
    State clone_state;
    //Clonage des Characters
    std::vector<Element*> elmt_list=this->characters->getElementList();
    std::vector<Element*> elmt_list_clone;
    std::vector<Element*> menu_elmt_list;
    
    
    
    
    for(size_t i=0;i<this->characters->getElementList().size();i++){
        Character* character=new Character(elmt_list[i]->getClass());
        character->setDirection(elmt_list[i]->getDirection());
        character->setPV(elmt_list[i]->getPV());
        character->setPA(elmt_list[i]->getPA());
        character->setPM(elmt_list[i]->getPM());
        state::Position pos=elmt_list[i]->getPosition();
        character->setPosition(pos);
        character->setTeam(elmt_list[i]->getTeam());
        character->setStatut(elmt_list[i]->getStatut());
        
        elmt_list_clone.push_back(character);
        
    }
    
    ElementTab* characters_clone =new state::ElementTab(this->characters->getWidth(),this->characters->getHeight(),elmt_list_clone);
    

    menu_elmt_list=this->menu->getElementList();
    
    ElementTab* menu_clone =new state::ElementTab(this->menu->getWidth(),this->menu->getHeight(),menu_elmt_list);
   
    //Initialisation du state cloné//
    clone_state.setCharacters(characters_clone);
    clone_state.setMap(this->carte);
    clone_state.setLandscape(this->landscape);
    clone_state.setMenu(menu_clone);
    clone_state.setWall(this->wall);
    clone_state.setRedMap(this->red_map);
    clone_state.setTour(this->tour);
    clone_state.setEtat(this->etat);
    
    return(clone_state);   
}

