#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include <random>
#include "math.h"
#include <cstdio>
#include <chrono>
#include <thread>
#include <memory>

#include "state.h"
#include "render.h"
#include "engine.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();


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
        std::vector<Element*> elmt_listRed;
	std::vector<Element*> listMenu;
        /*sf::Text text;
        sf::Text textpa;
        sf::Text textpm;
        sf::Font font;*/

        //Paramètres de Map//
        int width=9;
        int height=12;
        
        try{

        ////Instanciation de la  MAP////

            //Création des cases//
                for(int i=0;i<height;i++){
                    for(int j=0;j<width;j++){
                        if(i==0 || j==0){
                            Space* s_ptr=new Space(0);
                            Position position(i,j);
                            Position posref=position;
                            s_ptr->setPosition(posref);
                            elmt_list.push_back(s_ptr);
                        }
                        else{
                            Space* s_ptr=new Space(0);
                            Position position(i,j);
                            Position posref=position;
                            s_ptr->setPosition(posref);
                            elmt_list.push_back(s_ptr);
                        }


                    }
                }
            ////////////////////

            //Création du Landscape//
                for(int i=2;i<height-1;i++){
                    for(int j=2;j<width-1;j++){
                        Landscape* l_ptr=new Landscape;

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
            ////////////////////

            //Affichage des Wall//
                for(int i=0;i<height;i++){
                    for(int j=0;j<width;j++){
                        if(i==0|| j==0){//Visible Wall
                            Wall* w_ptr= new Wall;
                            Position position_wall(i,j);
                            Position posref_wall=position_wall;
                            w_ptr->setPosition(posref_wall);
                            elmt_list_wall.push_back(w_ptr);
                        }
                        //Invisible Wall
                        /*else if(i==height-1|| j==width-1){
                            Wall* w_ptr= new Wall;
                            w_ptr->setWallType(2);
                            Position position_wall(i,j);
                            Position posref_wall=position_wall;
                            w_ptr->setPosition(posref_wall);
                            elmt_list_wall.push_back(w_ptr);
                        }*/
                    }
                }
            ////////////////////


            //Affichage Personnages//
            
                //Création du Iop//
                Character* c_ptr=new Character("Iop");
                Position pos(height-1,width/2);
                c_ptr->setPosition(pos);
                elmt_list2.push_back(c_ptr);
 
                //Création du Sram//
                Character* sad_ptr=new Character("Sram");
                sad_ptr->setDirection(3); //Sud
                Position pos_sad(1,4);   
                sad_ptr->setPosition(pos_sad);
                elmt_list2.push_back(sad_ptr);
                
       
            ////////////////////////

            //Element List Surbrillance//
                Space* red_space=new Space(4);
                Space* white_space= new Space(5);
                white_space->setLoc(362,615);
                elmt_listRed.push_back(red_space);
                elmt_listRed.push_back(white_space);
                
            //State MEnu list
            Space* state_menu=new Space(1);
            state_menu->setTypeId(2);
            listMenu.push_back(state_menu);

        /////// FIN Instanciation MAP /////////////

        //Création des ElementTab//

        ElementTab* elmtTab_ptr=new ElementTab(8,12,elmt_list);
        ElementTab* elmtTab2_ptr=new ElementTab(8,12,elmt_list2);
        ElementTab* elmtTabLandscape_ptr=new ElementTab(8,12,elmt_list_landscape);
        ElementTab* elmtTabWall_ptr=new ElementTab(8,12,elmt_list_wall);
        ElementTab* elmtTabRed_ptr=new ElementTab(8,12,elmt_listRed);
        
        ElementTab* elmtTabMenu_ptr = new ElementTab(8,12,listMenu);


	//Creation de State
	
        State* state=new State;
	state->setMap(elmtTab_ptr);
	state->setCharacters(elmtTab2_ptr);
	state->setMenu(elmtTabMenu_ptr);
	state->setLandscape(elmtTabLandscape_ptr);

        //////////////////////////


        //Création de l'ElementTabLayer//
            //Space Layer
            ElementTab& tab_ref=*elmtTab_ptr;
            ElementTabLayer elmt_tab_layer(tab_ref);

            //Character Layer
            ElementTab& tab_ref2=*elmtTab2_ptr;
            ElementTabLayer elmt_tab_layer2(tab_ref2);

            //Landscape Layer
            ElementTab& tab_ref_landscape=*elmtTabLandscape_ptr;
            ElementTabLayer elmt_tab_layer_landscape(tab_ref_landscape);

            //Wall Layer
            ElementTab& tab_ref_wall=*elmtTabWall_ptr;
            ElementTabLayer elmt_tab_layer_wall(tab_ref_wall);

            //Red Layer
            ElementTab& tab_ref_red=*elmtTabRed_ptr;
            ElementTabLayer elmt_tab_layer_redl(tab_ref_red);
	
            //Menu Layer
            ElementTab& tabMenu_ref=*elmtTabMenu_ptr;
            ElementTabLayer elmt_tabMenu_layer(tabMenu_ref);

            //State
            State& stateMenu_ref=*state;
            StateLayer stateMenuLayer(stateMenu_ref);

        ////////////////////////////////

        ElementTabLayer* elmtTabLayer_ptr=new ElementTabLayer(tab_ref);
        ElementTabLayer* elmtTabLayer2_ptr=new ElementTabLayer(tab_ref2);
        ElementTabLayer* elmtTabLayerLandscape_ptr=new ElementTabLayer(tab_ref_landscape);
        ElementTabLayer* elmtTabLayerWall_ptr=new ElementTabLayer(tab_ref_wall);
        ElementTabLayer* elmtTabLayerRed_ptr=new ElementTabLayer(tab_ref_red);
	ElementTabLayer* elmtTabLayerMenu_ptr=new ElementTabLayer(tabMenu_ref);
	StateLayer* stateLayerMenu_ptr=new StateLayer(stateMenu_ref);

        //Ajout d'observers sur chaque Couche: map + Personnages//
	
	
        //Liaisons Observers/Observable//
        elmtTab_ptr->addObserver(elmtTabLayer_ptr);
        elmtTab2_ptr->addObserver(elmtTabLayer2_ptr);
        elmtTabRed_ptr->addObserver(elmtTabLayerRed_ptr);
        //Menu
        elmtTabMenu_ptr->addObserver(elmtTabLayerMenu_ptr);
        //Stats dans le Menu
        elmtTab2_ptr->addObserver(stateLayerMenu_ptr);

        //////////////////////////////////////////////////////////

        //Initialisation de la Surface de chaque Layer
        try{
            elmtTabLayer_ptr->initSurface();
            elmtTabLayer2_ptr->initSurface();
            elmtTabLayerLandscape_ptr->initSurface();
            elmtTabLayerWall_ptr->initSurface();
            elmtTabLayerRed_ptr->initSurface();
            elmtTabLayerMenu_ptr->initSurface();
            stateLayerMenu_ptr->initSurface();
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }

        //Définition du State
        /*State state;
        state.setMap(&elmtTabLayer_ptr->getTab());
        state.setCharacters(&elmtTabLayer2_ptr->getTab());*/

        //Surbrillance
        state->setRedMap(&elmtTabLayerRed_ptr->getTab());

    //Engine & Observables
	Engine engine;
        Observable observable;

        engine.setState(*state);
        
        
    ///// Création de la fenêtre/////
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    while (window.isOpen()){
        
        // Maintain designated frequency of 5 Hz (200 ms per frame)
        a = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = a - b;

        if (work_time.count() < 20.0)
        {
            std::chrono::duration<double, std::milli> delta_ms(100.0 - work_time.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
        }

        b = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> sleep_time = b - a;

        

        // on gère les évènements
        sf::Event event;
        while (window.waitEvent(event)){
            
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            float Tile_height=75.0/1.25;
            float Tile_Width=149.0/1.25;


            float x_mouse_iso=(localPosition.y-40)/Tile_height-(localPosition.x-650-Tile_Width/2)/Tile_Width;

            float y_mouse_iso=(localPosition.y-40)/Tile_height+(localPosition.x-650-Tile_Width/2)/Tile_Width;


            if(event.type == sf::Event::Closed){
                window.close();
            }


	// Souris déplacé seulement !
            else if(event.type==sf::Event::MouseMoved){
                
                if(localPosition.y>=615 and  localPosition.x>=362 ){
                    WhiteSurbrillanceCommand* case_blanche=new WhiteSurbrillanceCommand(localPosition.x,localPosition.y);
                    engine.addCommand(1,case_blanche);
                    engine.update();
                }

                else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<12 and int(y_mouse_iso)>0 and int(y_mouse_iso)<9 and ((x_mouse_iso+y_mouse_iso)<18) and localPosition.y<=615) {
                    
                    //Gestion Surbrillance//

                    SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
                    engine.addCommand(2, case_rouge);
                    engine.update();
                }
            }
                   
                    
            else if (event.type == sf::Event::MouseButtonPressed ){
                    
                    if(localPosition.x>=362 and localPosition.x<=362+67 and localPosition.y>=615 and localPosition.y<=615+62){
                        
                        
                        AttackCommand* attaque= new AttackCommand(0,1,"Coup d'Epée");
                        engine.addCommand(1,attaque);
                        engine.update();
                        
                    }
                
                
                    else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<12 and int(y_mouse_iso)>0 and int(y_mouse_iso)<9 and localPosition.y<=615 ) {

                    //Gestion Surbrillance//

                        SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
                        engine.addCommand(2, case_rouge);
                


                                       try{

                                           //Gestion Déplacement//
                                           int vectX=int(x_mouse_iso)-c_ptr->getPosition().getX();
                                           int vectY=int(y_mouse_iso)-c_ptr->getPosition().getY();

                                           cout<<vectX<<endl;
                                           cout<<vectY<<endl;

                                           MoveCharacterCommand* deplacement=new MoveCharacterCommand(0,vectX,vectY);
                                           engine.addCommand(2,deplacement);
                                           engine.update();
              
                                          

                                       }
                                       catch(const char* e){
                                           cout<<"Exception :"<<e<<endl;
                                       }
                    }
                    
                    
                    
                
                }
                 
        /*
        //Vérification des états des personnages//
            for(int i=0;i<state->getCharacters()->getElementList().size();i++){
                //Si le Personnage est mort
                if(state->getCharacters()->getElementList()[i]->getStatut()==3){
                    elmtTabLayer2_ptr->getTab().getElementList().erase(elmtTabLayer2_ptr->getTab().getElementList().begin() + i);
                    elmtTabLayer2_ptr->initSurface();
                
                }
            }*/
        ///////////////////////////////////////////
        


        // on dessine le niveau
        window.clear();
        window.draw(*elmtTabLayer_ptr->getSurface()); 
        window.draw(*elmtTabLayerMenu_ptr->getSurface());
        window.draw(*elmtTabLayerRed_ptr->getSurface());
        window.draw(*elmtTabLayerLandscape_ptr->getSurface());
        window.draw(*elmtTabLayerWall_ptr->getSurface());
        window.draw(*elmtTabLayer2_ptr->getSurface());
	window.draw(stateLayerMenu_ptr->getTextpv());
        window.draw(stateLayerMenu_ptr->getTextpvSram());
        window.draw(stateLayerMenu_ptr->getTextpa());
        window.draw(stateLayerMenu_ptr->getTextpm());
        

        window.display();
    }
    }
    
    }
        catch(const char* e){
            cout<<"Exception :"<<e<<endl;
        }




//fin test map
    
}
///// Fin Fenetre SFML /////


int main(int argc,char* argv[])
{
    //testSFML();
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
                //Test_Unitaire();

        }

        else if (strcmp(argv[1],"engine")==0){
            //Test Map
            testSFML();
            
        }

    }

    return(0);

}



