#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <exception>
#include <random>
#include "math.h"
#include <cstdio>
#include <chrono>
#include <memory>
#include <fstream>
#include <unistd.h>

#include <thread>
#include <condition_variable>

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
sf::Time tempo = sf::seconds(2);


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <valarray>
#include <stack>


mutex m1;
mutex m2;
mutex m3;

Engine engine1;
State* state1;

render::Scene* scene=nullptr;



ai::DeepAI* ai_1;
ai::DeepAI* ai_2;

int iop_pa=0;
int sram_pa=0;
int iop_pm=0;
int sram_pm=0;

unsigned int microseconds=5000000000;

///// Création de la fenêtre/////
sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Dofus Dungeon");


void testSFML() {
    
    	sf::Texture texture;
        std::vector<Element*> elmt_list;
        std::vector<Element*> elmt_list_landscape;
        std::vector<Element*> elmt_list_wall;
        std::vector<Element*> elmt_list2;
        std::vector<Element*> elmt_listRed;
	std::vector<Element*> listMenu;
        //Durée: 1s
        
        
        //Paramètres de Map//
        int width=11;
        int height=16;
        
        
        
        //CLock
        //clock_t t=clock();
        

        ////Instanciation de qqes objets de la  MAP////

            //Affichage Personnages//

                //Création du Iop//
                Character* c_ptr=new Character("Iop");
                Position pos(height-4,width-4);
                c_ptr->setPosition(pos);
		c_ptr->setTeam(1);
                elmt_list2.push_back(c_ptr);

                //Création du Sram//
                Character* sad_ptr=new Character("Sram");
                sad_ptr->setDirection(3); //Sud
                Position pos_sad(1,4);
                sad_ptr->setPosition(pos_sad);
		sad_ptr->setTeam(2);
                elmt_list2.push_back(sad_ptr);
            ////////////////////////

            //Element List Surbrillance//
                
                Space* white_space= new Space(5);
                Space* turn_space= new Space(6);
     
                Position position(100,100);
                Position& posi_ref=position;
                
                //Elements de Surbrilance Rouge
                for(size_t i=0;i<5;i++){
                    Space* red_space=new Space(4);
                    red_space->setPosition(posi_ref);
                    elmt_listRed.push_back(red_space);
                }
                
                
                
                white_space->setLoc(-100,-100);
                turn_space->setLoc(-100,-100);
                
                
                elmt_listRed.push_back(white_space);
                elmt_listRed.push_back(turn_space);
                
                int nbre=0;
                
                for(int i=2; i<6;i++){
                    nbre+=pow(2,i);
                }
                
                for(int i=0; i<nbre;i++){
                    Space* blue_space= new Space(7);
                    blue_space->setPosition(posi_ref);
                    elmt_listRed.push_back(blue_space);
                }
                
                
            ////////////////////////////

                


            //State Menu list
            Space* state_menu=new Space(1);
            state_menu->setTypeId(2);
            listMenu.push_back(state_menu);

        /////// FIN Instanciation MAP /////////////


        //Création des ElementTab//
        ElementTab* elmtTab_ptr=new ElementTab(width,height,elmt_list);
        ElementTab* elmtTab2_ptr=new ElementTab(width,height,elmt_list2);
        ElementTab* elmtTabLandscape_ptr=new ElementTab(width,height,elmt_list_landscape);
        ElementTab* elmtTabWall_ptr=new ElementTab(width,height,elmt_list_wall);
        ElementTab* elmtTabRed_ptr=new ElementTab(width,height,elmt_listRed);
        ElementTab* elmtTabMenu_ptr = new ElementTab(width,height,listMenu);
        //////////////////////////

        

	//Initialisation de State
        //State* state1=new State;
        state1=new State;
	state1->setMap(elmtTab_ptr);
	state1->setCharacters(elmtTab2_ptr);
        state1->setWall(elmtTabWall_ptr);
	state1->setMenu(elmtTabMenu_ptr);
	state1->setLandscape(elmtTabLandscape_ptr);
        state1->setTour(1);
        int etat=1;
        state1->setEtat(etat);
        //Surbrillance
        state1->setRedMap(elmtTabRed_ptr);

        //Chargement du niveau depuis un fichier json//
        std::string filePath="res/First_Dungeon.json";
        state1->LoadMapFromFile(filePath);
        ///////////////////////
        
        

        //Création de l'ElementTabLayer//
        ElementTabLayer* elmtTabLayer_ptr=new ElementTabLayer(*elmtTab_ptr);
        ElementTabLayer* elmtTabLayer2_ptr=new ElementTabLayer(*elmtTab2_ptr);
        ElementTabLayer* elmtTabLayerLandscape_ptr=new ElementTabLayer(*elmtTabLandscape_ptr);
        ElementTabLayer* elmtTabLayerWall_ptr=new ElementTabLayer(*elmtTabWall_ptr);
        ElementTabLayer* elmtTabLayerRed_ptr=new ElementTabLayer(*elmtTabRed_ptr);
	ElementTabLayer* elmtTabLayerMenu_ptr=new ElementTabLayer(*elmtTabMenu_ptr);
	StateLayer* stateLayerMenu_ptr=new StateLayer(*state1);
        ////////////////////////////////


        //Ajout d'observers sur chaque Couche: map + Personnages//
            //Liaisons Observers/Observable//
            /*elmtTab_ptr->addObserver(elmtTabLayer_ptr);
            elmtTab2_ptr->addObserver(elmtTabLayer2_ptr);
            elmtTabRed_ptr->addObserver(elmtTabLayerRed_ptr);
            //Menu
            elmtTabMenu_ptr->addObserver(elmtTabLayerMenu_ptr);
            //Stats dans le Menu
            elmtTab2_ptr->addObserver(stateLayerMenu_ptr);*/

        //////////////////////////////////////////////////////////
        
        //Initialisation de la Surface de chaque Layer
        /*try{
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
        }*/

        //Définition du State

        

        //Engine & Observables
	
        //Observable observable;
        //Engine engine;
        //engine1.setState(state1);

        //Deep AI
        
        ai_1=new ai::DeepAI(*state1,1,1);
        ai_2=new ai::DeepAI(*state1,1,0);
        
 
        //Mise en place d'Observers sur les AI
        /*elmtTab2_ptr->addObserver(ai_1);
        elmtTab2_ptr->addObserver(ai_2);*/

        //elmtTab2_ptr->addObserver(ai);

        //Gestion des tours
        //int tour=state->getTour();
        
        //PA et PM initiaux//

        //PA
        iop_pa=state1->getCharacters()->getElementList()[0]->getPA();
        sram_pa=state1->getCharacters()->getElementList()[1]->getPA();

        //PM
        iop_pm=state1->getCharacters()->getElementList()[0]->getPM();
        sram_pm=state1->getCharacters()->getElementList()[1]->getPM();
        
        
        scene =new Scene(*state1);
        engine1.setState(&scene->getState());
        
        
        window.setVerticalSyncEnabled(true);
}


void Moteur(){
        while(1){
            m2.lock();
            engine1.update();
            m2.unlock();
        }         
}

void IA(){  
    while(1){
        m2.lock();
        if(window.isOpen()and scene->getState().getTour()%2==0 and scene->getState().getCharacters()->getElementList()[0]->getStatut()!=3 and scene->getState().getCharacters()->getElementList()[1]->getStatut()!=3){
            scene->getState().getCharacters()->setCharacterPA(1,sram_pa);
            scene->getState().getCharacters()->setCharacterPM(1,sram_pm);
            cout<<"Tour :"<<scene->getState().getTour()<<endl;
            cout<<"//Tour Sram//"<<endl; 
            ai_1->run(engine1,1,scene->getState());
            sleep(2);
            //Changement de Tour
            scene->getState().setTour(scene->getState().getTour()+1);
        }
        m2.unlock();  
        
    }
}

void IA_2(){  
    while(1){
        m2.lock();
        if(window.isOpen()and scene->getState().getTour()%2==1 and scene->getState().getCharacters()->getElementList()[0]->getStatut()!=3 and scene->getState().getCharacters()->getElementList()[1]->getStatut()!=3){
            scene->getState().getCharacters()->setCharacterPA(1,iop_pa);
            scene->getState().getCharacters()->setCharacterPM(1,iop_pm);
            
            cout<<"Tour :"<<scene->getState().getTour()<<endl;
            cout<<"//Tour Iop//"<<endl;
            
            ai_2->run(engine1,0,scene->getState());
            sleep(2);

            //Changement de Tour
            scene->getState().setTour(scene->getState().getTour()+1);
        }
        m2.unlock();  
        
    }
}






void Rendu(){

    //Mise en place des Observers//
    scene->getState().getRedMap()->addObserver(scene->getRedLayer());
    scene->getState().getCharacters()->addObserver(scene->getCharsLayer());
    scene->getState().getCharacters()->addObserver(scene->getStateLayer());
    scene->getState().getMap()->addObserver(scene->getMapLayer());
    scene->draw(window);
    //Mise en place d'Observers sur les AI
    scene->getState().getCharacters()->addObserver(ai_1);
    scene->getState().getCharacters()->addObserver(ai_2);
    
    int new_turn=1;
    ////////////////////////////////
    while (window.isOpen()){
        
        //Phase de Combat//
        if(scene->getState().getEtat()==1){
            scene->draw(window);
            // on gère les évènements
                    
            sf::Event event;
            while (window.waitEvent(event)){
                //m2.lock();
                
                if(event.type == sf::Event::Closed){
                        window.close();
                }        
                /*if(new_turn==1){
                    scene->getState().getCharacters()->setCharacterPA(0,iop_pa);
                    scene->getState().getCharacters()->setCharacterPM(0,iop_pm);
                    cout<<"Tour :"<<scene->getState().getTour()<<endl;
                    cout<<"//Tour Joueur//"<<endl;
                    new_turn=0;
                }
                        
                else if(scene->getState().getTour()%2==1){
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    // Souris déplacé seulement !
                    else if(event.type==sf::Event::MouseMoved){  
                        MouseMovedCommand* mouse_moved=new MouseMovedCommand(localPosition.x,localPosition.y);
                        engine1.addCommand(1,mouse_moved);
                    }

                    else if (event.type == sf::Event::MouseButtonPressed ){    
                        ClickCommand* click=new ClickCommand(localPosition.x,localPosition.y);
                        engine1.addCommand(1,click);
                        if(localPosition.x>=1030  and localPosition.y>=470 and localPosition.y<=540){
                            new_turn=1;
                        }
                    }
                }*/

                    /*else if (scene->getState().getMenu()->getElementList()[0]->getTypeId()==6){
                            window.clear();
                            scene->getState().setEtat(2);
                            break;
                    }
                    
                    //Fin d'une partie//
                        for(int i=0; i<scene->getState().getCharacters()->getElementList().size();i++){
                            if(scene->getState().getCharacters()->getElementList()[i]->getStatut()==3){
                                break;
                            }
                    }*/
                
                //m2.unlock();
                // on dessine le niveau
                scene->draw(window); 
                
            }
        }  
    }  
}
    




//fin test map


///// Fin Fenetre SFML /////


int main(int argc,char* argv[])
{
 
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }

        else if (strcmp(argv[1],"deep_ai")==0){
            //Test Map
            
            testSFML();
            
            //thread th(Moteur);
            thread th2(Rendu);
            thread th3(IA);
            thread th4(IA_2);
            
           
            
            //th.join();
            th2.join();
            th3.join();
            th4.join();
            
        }

    }

    return(0);

}