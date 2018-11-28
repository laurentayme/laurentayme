#include <stdio.h>
#include "state.h"
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
    return menu;
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


std::vector<std::vector<state::Element*>> State::LoadMapFromFile(std::string filePath){
    std::vector<std::vector<Element*>> Liste_Layers;
    std::vector<Element*> elmt_list;
    std::vector<Element*> elmt_list_landscape;
    std::vector<Element*> elmt_list_wall;
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
           elmt_list.push_back(s_ptr);                 
        }
        else{//Cas d'un Space "classique"
          Space* s_ptr=new Space(0);
          Position position(abs,ord);
          //Position posref=position;
          s_ptr->setPosition(position);
          elmt_list.push_back(s_ptr);                                                                        
                        
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
           elmt_list_wall.push_back(w_ptr);                 
        }
        //Stone classique
        else if (root["layers"][1]["data"][i].asInt()==3){
           Landscape* l_ptr=new Landscape;
           Position position(abs,ord);
           l_ptr->setPosition(position);
           l_ptr->setLandscapeType(0);
           elmt_list_landscape.push_back(l_ptr);                 
        }
        
        //Double Stone
        else if (root["layers"][1]["data"][i].asInt()==2){
          Landscape* l_ptr=new Landscape;
          Position position(abs,ord);
          l_ptr->setPosition(position);
          l_ptr->setLandscapeType(1);
          elmt_list_landscape.push_back(l_ptr);                                                                        
                        
        }
    }
    //////////////////////
    Liste_Layers.push_back(elmt_list);
    Liste_Layers.push_back(elmt_list_landscape);
    Liste_Layers.push_back(elmt_list_wall);
    return(Liste_Layers);  
}
}
