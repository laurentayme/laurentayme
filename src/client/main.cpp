#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include "state.h"
#include "render.h"
#include <random>
#include "engine.h"
#include "math.h"


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    	sf::Texture texture;
        std::vector<Element*> elmt_list;
        std::vector<Element*> elmt_list_landscape;
        std::vector<Element*> elmt_list_wall;
        std::vector<Element*> elmt_list2;
        /*std::vector<Element*> elmt_list3;
        sf::Text text;
        sf::Text textpa;
        sf::Text textpm;
        sf::Font font;*/
        
        //Paramètres de Map//
        int width=9;
        int height=12;
             
        
        //Creation MAP
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(i==0 || j==0){
                    Space* s_ptr=new Space(1);
                    s_ptr->setTypeId(0);
                    Position position(i,j);
                    Position posref=position;
                    s_ptr->setPosition(posref);
                    elmt_list.push_back(s_ptr);
                }
                else{
                    Space* s_ptr=new Space(0);
                    s_ptr->setTypeId(0);
                    Position position(i,j);
                    Position posref=position;
                    s_ptr->setPosition(posref);
                    elmt_list.push_back(s_ptr);
                }
                
		
            }
        }
            
        //Affichage du Landscape//
        for(int i=2;i<height-1;i++){
            for(int j=2;j<width-1;j++){
                Landscape* l_ptr=new Landscape;
                l_ptr->setTypeId(0);
                
                //Aleatoire//
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dis(1,8);
                int x=dis(gen);
                
                
                if((i%x==0) && (j%(x+2)==0)){
                    l_ptr->setLandscapeType(1);
                    Position position(i,j);
                    Position posref=position;
                    l_ptr->setPosition(posref);
                    elmt_list_landscape.push_back(l_ptr);
                }
                else if(((i%(x+3)==0) && (j%2==0))||((i%2==0) && (j%(x)==0))){
                    Position position(i,j);
                    Position posref=position;
                    l_ptr->setPosition(posref);
                    elmt_list_landscape.push_back(l_ptr);
                }
                
                
                
            }
        }
            
        //Affichage des Wall//
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(i==0|| j==0){//Visible Wall
                    Wall* w_ptr= new Wall;
                    w_ptr->setTypeId(0);
                    Position position_wall(i,j);
                    Position posref_wall=position_wall;
                    w_ptr->setPosition(posref_wall);
                    elmt_list_wall.push_back(w_ptr);
                }
                //Invisible Wall
                else if(i==height-1|| j==width-1){
                    Wall* w_ptr= new Wall;
                    w_ptr->setTypeId(0);
                    w_ptr->setWallType(2);
                    Position position_wall(i,j);
                    Position posref_wall=position_wall;
                    w_ptr->setPosition(posref_wall);
                    //elmt_list_wall.push_back(w_ptr);
                }
            }
        }
        
            
            
            /*Wall* w_ptr2=new Wall;
            *w_ptr2=*w_ptr;
            posref_wall.setX(4);
            posref_wall.setY(2);
            w_ptr2->setPosition(posref_wall);
            elmt_list_wall.push_back(w_ptr2);*/
            
	
        
        
        //Affichage Personnages
        Character* c_ptr=new Character("Iop");
        Character* sad_ptr=new Character("Sadida");
        c_ptr->setTypeId(1);
        c_ptr->setDirection(1); //Nord
        Position pos(height-1,width/2);
        c_ptr->setPosition(pos);
        cout<<c_ptr->getPosition().getX()<<endl;
        Position pos_sad(1,width/2);
        sad_ptr->setPosition(pos_sad);
        //c_ptr->setDirection(4);
        elmt_list2.push_back(c_ptr);
        elmt_list2.push_back(sad_ptr);
        
        
        //Menu de State
       /* try{
            Space* state_ptr=new Space(1);
            state_ptr->setTypeId(2);
            elmt_list3.push_back(state_ptr);
        }
        catch(const char* e){
            std::cout<<"Exception: "<<e<<std::endl;
        }*/
        
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
        
        
        
        //Création de l'ElementTab
        
        ElementTab* elmtTab_ptr=new ElementTab(11,7,elmt_list);
        ElementTab* elmtTab2_ptr=new ElementTab(1,1,elmt_list2);
        ElementTab* elmtTabLandscape_ptr=new ElementTab(1,1,elmt_list_landscape);
        ElementTab* elmtTabWall_ptr=new ElementTab(1,1,elmt_list_wall);
        
        
        
        /*ElementTab elmt_tab(11,7,elmt_list);
        ElementTab elmt_tab2(1,1,elmt_list2);
        //ElementTab elmt_tab3(1,1,elmt_list3);
        ElementTab elmt_tab_landscape(1,1,elmt_list_landscape);
        ElementTab elmt_tab_wall(1,1,elmt_list_wall);
         */ 
        
        //Création de l'ElementTabLayer
        //1st Layer
        ElementTab& tab_ref=*elmtTab_ptr;
        ElementTabLayer elmt_tab_layer(tab_ref);
        
        //Character
        ElementTab& tab_ref2=*elmtTab2_ptr;
        ElementTabLayer elmt_tab_layer2(tab_ref2);
        
        
        
        //2nd Layer
        ElementTab& tab_ref_landscape=*elmtTabLandscape_ptr;
        ElementTabLayer elmt_tab_layer_landscape(tab_ref_landscape);
        
        //3rd Layer
        ElementTab& tab_ref_wall=*elmtTabWall_ptr;
        ElementTabLayer elmt_tab_layer_wall(tab_ref_wall);
        
        //Initialisation de la Surface
        try{
            elmt_tab_layer.initSurface();
            elmt_tab_layer2.initSurface();
            elmt_tab_layer_landscape.initSurface();
            elmt_tab_layer_wall.initSurface();
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }
        
        //Définition du State et des pointeurs ElementTab
        State state;

        state.setMap(&elmt_tab_layer.getTab());
        state.setCharacters(&elmt_tab_layer2.getTab());
        //state.setMenu();
        
        
        
    //Engine & Observables
	Engine engine;
        Observable observable;
        
        engine.setState(state);
        
        ElementTabLayer* elmtTabLayer_ref=new ElementTabLayer(tab_ref);
        ElementTabLayer* elmtTabLayer2_ref=new ElementTabLayer(tab_ref2);
        ElementTabLayer* elmtTabLayerLandscape_ref=new ElementTabLayer(tab_ref_landscape);
        ElementTabLayer* elmtTabLayerWall_ref=new ElementTabLayer(tab_ref_wall);
        
        elmtTab_ptr->addObserver(elmtTabLayer_ref);
        elmtTab2_ptr->addObserver(elmtTabLayer2_ref);
        
        //state.addObserver(elmtTabLayer2_ref);
        
        //elmt_tab_landscape.addObserver(elmtTabLayerLandscape_ref);
        //elmt_tab_wall.addObserver(elmtTabLayerWall_ref);
      

        // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    while (window.isOpen()){
        
        //Initialisation de la Surface
        try{   
            //elmt_tab_layer2.initSurface();
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }
        
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event)){
	sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            if(event.type == sf::Event::Closed){
                window.close();
            }


	// Boutton souris cliqué
        else if (event.type == sf::Event::MouseButtonPressed){
            //Obtenir la coordonnée suivant X
            
            float cote=sqrt(pow(32.0/2.25,2.0)+pow(75/2.25,2.0));
            
            float Tile_height=75.0/1.25;
            float Tile_Width=149.0/1.25;
            
              
            float x_mouse_iso=(localPosition.y-40)/Tile_height-(localPosition.x-650-Tile_Width/2)/Tile_Width;
            
            float y_mouse_iso=(localPosition.y-40)/Tile_height+(localPosition.x-650-Tile_Width/2)/Tile_Width;
            
            //int x_mouse_iso=(2*(localPosition.y/75-localPosition.x/149)+650-80/75)/2-321;
            //int y_mouse_iso=-(2*(localPosition.x/149-localPosition.y/75)-650+80/75)/2-321;
            
                if(int(x_mouse_iso)>=0 and int(x_mouse_iso)<=11 and int(y_mouse_iso)>=0 and int(y_mouse_iso)<=7) {
			
                        //Engine & Observables
                    /*cout<<"Nbre Observers dans elmt_tab 2 avant Move :"<<elmt_tab2.observers.size()<<endl;
                    cout<<"Nbre Observers dans state avant Move :"<<state.observers.size()<<endl;
                    TabEvent e;
                    elmt_tab2.notifyObservers(e);*/
                    try{
                        MoveCharacterCommand* pas= new MoveCharacterCommand(0);
			engine.addCommand(1,pas);
			engine.update();
                        elmt_tab_layer2.initSurface();
                    }
                    catch(const char* e){
                        cout<<"Exception :"<<e<<endl;
                    }
                        
                        /*cout<<"Coordonnées ok !"<<endl;
                        cout<<"Mouse X: "<<int(x_mouse_iso)<<" , Mouse Y: "<<int(y_mouse_iso)<<endl;
                        
                        //Position* pos_ptr=new Position(0,0);
                        //*pos_ptr=pos;
                        
                        //c_ptr->setPosition(Position p(1,2));
                        c_ptr->affiche_Position();
                        pos.setX(int(x_mouse_iso));
                        pos.setY(int(y_mouse_iso));
                        c_ptr->setPosition(pos);
                        c_ptr->affiche_Position();
                        elmt_list2.push_back(c_ptr);
                        
                        elmt_tab_layer2.initSurface();
                        
              
                        //elmt_tab_layer2.getElementTab().getElementList()[0]->set_Position();
                        //delete pos_ptr;*/
                        
                        
                }
                    
                else{
                    cout<<"Nope ! (X)"<<endl;
                    cout<<"Mouse X: "<<int(x_mouse_iso)<<" , Mouse Y: "<<int(y_mouse_iso)<<endl;
                    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
	}
             

        // on dessine le niveau
        window.clear();
        
       	window.draw(*elmt_tab_layer.getSurface());
        window.draw(*elmt_tab_layer_landscape.getSurface());
        window.draw(*elmt_tab_layer_wall.getSurface());
        window.draw(*elmt_tab_layer2.getSurface());
        window.display();

    }
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
    
    return(0);
//test map
//testSFML();
}
                


void Test_Unitaire(){
            size_t c=0;
            cout<<"//Phase de Tests unitaires//"<<endl;
            cout<<endl;

            //Test des instanciations
            cout<<"/Instanciation de chaque classe/"<<endl;
            
            //Instancication ElementTab
            cout<<" ->Instanciation State..."<<endl;
            ElementTab* elTab_ptr=nullptr;
            //State state(elTab_ptr);
            
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

