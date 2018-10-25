#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include "state.h"
#include "render.h"


using namespace std;
using namespace state;
using namespace render;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    	sf::Texture texture;
        std::vector<Element*> elmt_list;
        std::vector<Element*> elmt_list_wall;
        std::vector<Element*> elmt_list2;
        std::vector<Element*> elmt_list3;
        sf::Text text;
        sf::Text textpa;
        sf::Text textpm;
        sf::Font font;
        
        
        
        
        
        
        //Creation MAP
        for(int i=0;i<11;i++){
            for(int j=0;j<7;j++){
                Space* s_ptr=new Space(i%3);
		s_ptr->setTypeId(0);
		Position position(i,j);
		Position posref=position;
		s_ptr->setPosition(posref);
                elmt_list.push_back(s_ptr);
            }
            
            Wall* w_ptr=new Wall;
            w_ptr->setTypeId(0);
            Position position(7,5);
	    Position posref=position;
            w_ptr->setPosition(posref);
            elmt_list_wall.push_back(w_ptr);
            
            	
        }
        
        //Personnage IOP
        Character* c_ptr=new Character("Iop");
        c_ptr->setTypeId(1);
        Position pos(4,4);
        c_ptr->setPosition(pos);
        c_ptr->affiche_Position();
        c_ptr->setDirection(4);
        elmt_list2.push_back(c_ptr);
        
        //Menu de State
        try{
            Space* state_ptr=new Space(1);
            state_ptr->setTypeId(2);
            elmt_list3.push_back(state_ptr);
        }
        catch(const char* e){
            std::cout<<"Exception: "<<e<<std::endl;
        }
        
        //Affichage de l'état
        if(!font.loadFromFile("/home/valentin/laurentayme/res/font.TTF")){
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
        textpm.setPosition(220,86*8.44);
        
        
        
        //Création de l'ElementTab
        ElementTab elmt_tab(11,7,elmt_list);
        ElementTab elmt_tab2(1,1,elmt_list2);
        ElementTab elmt_tab3(1,1,elmt_list3);
        ElementTab elmt_tab_wall(1,1,elmt_list_wall);
        
        //Création de l'ElementTabLayer
        //1st Layer
        ElementTab& tab_ref=elmt_tab;
        ElementTabLayer elmt_tab_layer(tab_ref);
        
        //Character
        ElementTab& tab_ref2=elmt_tab2;
        ElementTabLayer elmt_tab_layer2(tab_ref2);
        
        //State
        ElementTab& tab_ref3=elmt_tab3;
        ElementTabLayer elmt_tab_layer3(tab_ref3);
        
        //2nd Layer
        ElementTab& tab_ref_wall=elmt_tab_wall;
        ElementTabLayer elmt_tab_layer_wall(tab_ref_wall);
        
        //Initialisation de la Surface
        try{
            elmt_tab_layer.initSurface();
            elmt_tab_layer2.initSurface();
            elmt_tab_layer3.initSurface();
            elmt_tab_layer_wall.initSurface();
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }
        //Surface surf_ptr=*elmt_tab_layer.getSurface();
        //sf::Texture text;
        //text=surf_ptr->getTexture();
        //surf_ptr->draw(surf_ptr->getQuads(),&text);
        
        
        // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    while (window.isOpen()){
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            }

        // on dessine le niveau
        window.clear();
        
       	window.draw(*elmt_tab_layer.getSurface());
        window.draw(*elmt_tab_layer_wall.getSurface());
        window.draw(*elmt_tab_layer2.getSurface());
        window.draw(*elmt_tab_layer3.getSurface());
        window.draw(text);
        window.draw(textpa);
        window.draw(textpm);
        window.display();

    }
    	
//fin test map
}


void Test_Unitaire();


int main(int argc,char* argv[])
{
    //testSFML();
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
                Test_Unitaire();
    
        }
        
        else if (strcmp(argv[1],"render")==0){
            //Test Map    
            testSFML();
 
                }
    
        }
    }
    
//test map
//testSFML();
                


void Test_Unitaire(){
            size_t c=0;
            cout<<"//Phase de Tests unitaires//"<<endl;
            cout<<endl;

            //Test des instanciations
            cout<<"/Instanciation de chaque classe/"<<endl;
            
            //Instancication ElementTab
            cout<<" ->Instanciation State..."<<endl;
            ElementTab* elTab_ptr=nullptr;
            State state(elTab_ptr);
            
            //Instancication ElementTab
            cout<<" ->Instanciation ElementTab..."<<endl;
            vector<Element*> elementList;
            try{
                elTab_ptr=new ElementTab(2,-1,elementList);
            }
            
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            
            //Instancication Character
            cout<<" ->Instanciation Character..."<<endl;
            Character* iop_ptr=nullptr;
           
            try{
                iop_ptr= new Character("Iop");
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            //Instancication Wall
            cout<<" ->Instanciation Wall..."<<endl;
            Wall wall;
            
            //Instancication Landscape
            cout<<" ->Instanciation Landscape..."<<endl;
            Landscape landscape;
            
            //Instancication Space
            cout<<" ->Instanciation Space..."<<endl;
            Space* space=nullptr;
            try{
                space= new Space(-1);
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            //Instancication Position
            Position* position_ptr=nullptr;
            cout<<" ->Instanciation Position..."<<endl;
            try{
                position_ptr= new Position(1,1); 
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            //Instancication Equipment
            Equipment* epee_ptr=nullptr;
            cout<<" ->Instanciation Equipment..."<<endl;
            try{
                epee_ptr= new Equipment("Epée","main",-1); 
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
                
             
            //Instancication Abilities
            try{
                cout<<" ->Instanciation Abilities..."<<endl;
                Abilities abilities("Sort",-1);
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            
            if(c==0){
                cout<<"/Aucune Erreur"<<endl;
            }
            else{
                cout<<"/Il y a eu "<<c<<" erreur(s) !"<<endl;
            }
            
            
            cout<<endl;
            cout<<"/Test de methodes des classes/"<<endl;
            
            //Test affiche_Classe de Character//
            cout<<" ->Test affiche_Classe..."<<endl;
            
            //Character//
            if(iop_ptr!=nullptr){
                cout<<"     -Test Character"<<endl;
                cout<<"      Result: ";
                iop_ptr->affiche_Classe();
            }
            //Wall//
            cout<<"     -Test Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Classe();
            
            //Space//
            if(space!=nullptr){
                cout<<"     -Test Space"<<endl;
                cout<<"      Result: ";
                space->affiche_Classe();
            }
            
            //Landscape//
            cout<<"     -Test Landscape"<<endl;
            cout<<"      Result: ";
            landscape.affiche_Classe();
            
            cout<<endl;
            
            //Test affiche_Weapon de Equipment//
            if(epee_ptr!=nullptr){
                cout<<" ->Test affiche_Weapon sur Equipment"<<endl;
                cout<<"      Result: ";
                epee_ptr->affiche_Weapon();
            }
            
            cout<<endl;
            
            //Test affiche_Position...//
            cout<<" ->Test affiche_Position..."<<endl;
            if(iop_ptr!=nullptr){
                cout<<"     -Test sur Character"<<endl;
                cout<<"      Result: ";
            
                iop_ptr->affiche_Position();
            }
            cout<<"     -Test sur Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Position();
            
            cout<<"     -Test sur Landscape"<<endl;
            cout<<"      Result: ";
            landscape.affiche_Position();
            
            if(space!=nullptr){
                cout<<"     -Test sur Space"<<endl;
                cout<<"      Result: ";
                space->affiche_Position();
            }
            
            cout<<endl;
            
            //Test setPosition//
            if(position_ptr!=nullptr){
                try{
                    cout<<" ->Test setX()"<<endl;
                    position_ptr->setX(-1);
                    cout<<"      Result: "<<position_ptr->getX()<<endl;
                }
                catch(const char* e){
                    cout<<"      Exception: "<<e<<endl;
                }
                
                try{
                    cout<<" ->Test setY()"<<endl;
                    position_ptr->setY(-1);
                    cout<<"      Result: "<<position_ptr->getY()<<endl;
                }
                catch(const char* e){
                    cout<<"      Exception: "<<e<<endl;
                }
                
            }
            
            cout<<endl;
            
            //Test setTypeId//
            if(iop_ptr!=nullptr){
                try{
                    cout<<" ->Test setTypeId()"<<endl;
                    iop_ptr->setTypeId(2);
                    cout<<"      Result: "<<iop_ptr->getTypeId()<<endl;
                }
                catch(const char* e){
                    cout<<"      Exception: "<<e<<endl;
                }
                
            }
            
            cout<<endl;
            
            
            //Test affiche_Stats de Character//
            if(iop_ptr!=nullptr){
                cout<<" ->Test affiche_Stats sur Character"<<endl;
                cout<<"      Result: ";
                iop_ptr->affiche_Stats();
            }
            cout<<endl;
            
            
            
            //Test affiche_EquipmentList de Character//
            if(iop_ptr!=nullptr){
                cout<<" ->Test affiche_EquipmentList sur Character"<<endl;
                cout<<"   Result: ";
                iop_ptr->affiche_EquipmentList();
            }
            
            cout<<endl;
            
            //Test affiche_Statut de Character//
            if(iop_ptr!=nullptr){
                cout<<" ->Test affiche_Statut sur Character"<<endl;
                cout<<"   Mise à 0 des pts de vie..."<<endl;;
                iop_ptr->setPV(0);
                cout<<"   Result: ";
                iop_ptr->afficheStatut();
                
            }
            
            cout<<endl;
            cout<<"//Fin des Tests unitaires//"<<endl;
            
            delete elTab_ptr;
            elTab_ptr=nullptr;
            
            delete iop_ptr;
            iop_ptr=nullptr;
            
            delete position_ptr;
            position_ptr=nullptr;
            
            delete epee_ptr;
            epee_ptr=nullptr;
            
            delete space;
            space=nullptr;
}

