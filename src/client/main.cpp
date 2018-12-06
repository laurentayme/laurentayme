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
<<<<<<< HEAD
#include <fstream>
#include <ctime>
#include <unistd.h>
||||||| merged common ancestors
=======
#include <fstream>
#include <unistd.h>
>>>>>>> refs/remotes/origin/master

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
<<<<<<< HEAD
unsigned int tempo = 1000000;
||||||| merged common ancestors

=======
//sf::Time tempo = sf::seconds(0.5);

>>>>>>> refs/remotes/origin/master

using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <valarray>

void testSFML() {
    	sf::Texture texture;
        std::vector<Element*> elmt_list;
        std::vector<Element*> elmt_list_landscape;
        std::vector<Element*> elmt_list_wall;
        std::vector<Element*> elmt_list2;
        std::vector<Element*> elmt_listRed;
	std::vector<Element*> listMenu;
        //Durée: 1s
        unsigned int microseconds=500000;

        //Paramètres de Map//
        int width=11;
        int height=16;



        ////Instanciation de qqes objets de la  MAP////

            //Affichage Personnages//

                //Création du Iop//
<<<<<<< HEAD
                Character* c_ptr=new Character("Sram");
                Position pos(height-1,width/2);
||||||| merged common ancestors
                Character* c_ptr=new Character("Iop");
                Position pos(height-1,width/2);
=======
                Character* c_ptr=new Character("Iop");
                Position pos(height-1,width-4);
>>>>>>> refs/remotes/origin/master
                c_ptr->setPosition(pos);
<<<<<<< HEAD
		c_ptr->setTeam(1);
		c_ptr->setPlayer(true);
||||||| merged common ancestors
=======
		c_ptr->setTeam(1);
>>>>>>> refs/remotes/origin/master
                elmt_list2.push_back(c_ptr);

                //Création du Sram//
                Character* sad_ptr=new Character("Sram");
                sad_ptr->setDirection(3); //Sud
                Position pos_sad(3,4);
                sad_ptr->setPosition(pos_sad);
<<<<<<< HEAD
		sad_ptr->setTeam(2);
		sad_ptr->setPlayer(false);
||||||| merged common ancestors
=======
		sad_ptr->setTeam(2);
>>>>>>> refs/remotes/origin/master
                elmt_list2.push_back(sad_ptr);
            ////////////////////////

            //Element List Surbrillance//
                Space* red_space=new Space(4);
                Space* white_space= new Space(5);
                Space* turn_space= new Space(6);
                Position position(100,100);
                Position& posi_ref=position;
                red_space->setPosition(posi_ref);
                white_space->setLoc(-100,-100);
                turn_space->setLoc(-100,-100);
                elmt_listRed.push_back(red_space);
                elmt_listRed.push_back(white_space);
                elmt_listRed.push_back(turn_space);
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


	//Creation de State
        State* state=new State;
	state->setMap(elmtTab_ptr);
	state->setCharacters(elmtTab2_ptr);
        state->setWall(elmtTabWall_ptr);
	state->setMenu(elmtTabMenu_ptr);
	state->setLandscape(elmtTabLandscape_ptr);
        state->setTour(1);
        int etat=1;
        state->setEtat(etat);

<<<<<<< HEAD
        //Chargement du niveau depuis un fichier json//
        std::string filePath="res/Second_Dungeon.json";
        state->LoadMapFromFile(filePath);
        ///////////////////////

||||||| merged common ancestors
        //////////////////////////

=======
        //Chargement du niveau depuis un fichier json//
        std::string filePath="res/First_Dungeon.json";
        state->LoadMapFromFile(filePath);
        ///////////////////////
        
>>>>>>> refs/remotes/origin/master

        //Création de l'ElementTabLayer//
        ElementTabLayer* elmtTabLayer_ptr=new ElementTabLayer(*elmtTab_ptr);
        ElementTabLayer* elmtTabLayer2_ptr=new ElementTabLayer(*elmtTab2_ptr);
        ElementTabLayer* elmtTabLayerLandscape_ptr=new ElementTabLayer(*elmtTabLandscape_ptr);
        ElementTabLayer* elmtTabLayerWall_ptr=new ElementTabLayer(*elmtTabWall_ptr);
        ElementTabLayer* elmtTabLayerRed_ptr=new ElementTabLayer(*elmtTabRed_ptr);
	ElementTabLayer* elmtTabLayerMenu_ptr=new ElementTabLayer(*elmtTabMenu_ptr);
	StateLayer* stateLayerMenu_ptr=new StateLayer(*state);
        ////////////////////////////////


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
<<<<<<< HEAD

            elmtTabLayer_ptr->initSurface();
            elmtTabLayer2_ptr->initSurface();
            elmtTabLayerLandscape_ptr->initSurface();
            elmtTabLayerWall_ptr->initSurface();
            elmtTabLayerRed_ptr->initSurface();
            elmtTabLayerMenu_ptr->initSurface();
            stateLayerMenu_ptr->initSurface();
||||||| merged common ancestors
            elmtTabLayer_ptr->initSurface();
            elmtTabLayer2_ptr->initSurface();
            elmtTabLayerLandscape_ptr->initSurface();
            elmtTabLayerWall_ptr->initSurface();
            elmtTabLayerRed_ptr->initSurface();
            elmtTabLayerMenu_ptr->initSurface();
            stateLayerMenu_ptr->initSurface();
=======
                elmtTabLayer_ptr->initSurface();
                elmtTabLayer2_ptr->initSurface();
                elmtTabLayerLandscape_ptr->initSurface();
                elmtTabLayerWall_ptr->initSurface();
                elmtTabLayerRed_ptr->initSurface();
                elmtTabLayerMenu_ptr->initSurface();
                stateLayerMenu_ptr->initSurface();
            
>>>>>>> refs/remotes/origin/master
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }

        //Définition du State

        //Surbrillance
        state->setRedMap(&elmtTabLayerRed_ptr->getTab());

        //Engine & Observables
	Engine engine;
        Observable observable;

        engine.setState(state);

        //Random IA
<<<<<<< HEAD
        //ai::Random_AI ai(1);
	//ai::Random_AI ai2(0);
        //ai::HeuristicAI ai(*state,1);
	//ai = new HeuristicAI(*state,1);
	ai::HeuristicAI* ai=new ai::HeuristicAI(*state,1,1);
	elmtTab2_ptr->addObserver(ai);
	ai::HeuristicAI* ai2=new ai::HeuristicAI(*state,0,0);
	elmtTab2_ptr->addObserver(ai2);
	

        //elmtTab2_ptr->addObserver(ai);
	//elmtTab2_ptr->addObserver(ai2);
||||||| merged common ancestors
        ai::Random_AI ai(1);
=======
        //ai::Heuristic_AI ai(1);
        //ai::Random_AI ai_2(0);
        ai::HeuristicAI* ai=new ai::HeuristicAI(*state,1,1);
        ai::HeuristicAI* ai_2=new ai::HeuristicAI(*state,2,0);
        
        //Mise en place d'Observers sur les Heuristic_AI
        elmtTab2_ptr->addObserver(ai);
        elmtTab2_ptr->addObserver(ai_2);

        //elmtTab2_ptr->addObserver(ai);
>>>>>>> refs/remotes/origin/master

        //Gestion des tours
        int tour=state->getTour();

        //PA et PM initiaux//

            //PA
            int iop_pa=state->getCharacters()->getElementList()[0]->getPA();
            int sram_pa=state->getCharacters()->getElementList()[1]->getPA();

            //PM
            int iop_pm=state->getCharacters()->getElementList()[0]->getPM();
            int sram_pm=state->getCharacters()->getElementList()[1]->getPM();
<<<<<<< HEAD
        ////////////////////

            
||||||| merged common ancestors

            //cout<<sram_pm<<endl;




=======
        ////////////////////  

>>>>>>> refs/remotes/origin/master
    ///// Création de la fenêtre/////
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(24);

    while (window.isOpen()){
<<<<<<< HEAD
	if(state->getCharacters()->getElementList().size()>1 and state->getCharacters()->getElementList()[0]->getPV()!=0){
||||||| merged common ancestors

        /*// Maintain designated frequency of 5 Hz (200 ms per frame)
        a = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = a - b;

        if (work_time.count() < 20.0)
        {
            std::chrono::duration<double, std::milli> delta_ms(100.0 - work_time.count());
            auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
            std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
        }

        b = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> sleep_time = b - a;*/

=======
        
        
        
        if(state->getEtat()==1){
        //stateLayerMenu_ptr->initSurface();
>>>>>>> refs/remotes/origin/master
        //Réinitialisation des Stats//
        state->getCharacters()->setCharacterPA(0,iop_pa);
        state->getCharacters()->setCharacterPA(1,sram_pa);

        state->getCharacters()->setCharacterPM(0,iop_pm);
        state->getCharacters()->setCharacterPM(1,sram_pm);
<<<<<<< HEAD
        /////////////////////////////


||||||| merged common ancestors



=======
        /////////////////////////////

        
>>>>>>> refs/remotes/origin/master
        ////Tour Joueur////
        if(state->getTour()%2==1){
            
            
            cout<<"Tour :"<<state->getTour()<<endl;
            cout<<"//Tour Joueur//"<<endl;
<<<<<<< HEAD
	    usleep(tempo);
	    ai2->run(engine,0,*state);
	    state->setTour(state->getTour()+1);

            /*MoveCharacterCommand* move = new MoveCharacterCommand(1,1,0);
            engine.addCommand(2,move);
            engine.update();*/
||||||| merged common ancestors
=======
            
            usleep(microseconds);
            try{
                ai_2->run(engine,0,*state);
                state->setTour(state->getTour()+1);
            }
            catch(const char* e){
                cout<<"Exception :"<<e<<endl;
            }
            
           
            
            
>>>>>>> refs/remotes/origin/master
            // on gère les évènements
<<<<<<< HEAD
            /*sf::Event event;
            while (window.waitEvent(event)){
||||||| merged common ancestors
            sf::Event event;
            while (window.waitEvent(event)){
=======
            sf::Event event;
           /* while (window.waitEvent(event)){
>>>>>>> refs/remotes/origin/master
                engine.update();
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if(event.type == sf::Event::Closed){
                    window.close();
                }
<<<<<<< HEAD
                // Souris déplacé seulement !
                else if(event.type==sf::Event::MouseMoved){   
                    MouseMovedCommand* mouse_moved=new MouseMovedCommand(localPosition.x,localPosition.y);
                    engine.addCommand(1,mouse_moved);
                    engine.update();    
||||||| merged common ancestors


            // Souris déplacé seulement !
                else if(event.type==sf::Event::MouseMoved){

                    if(localPosition.y>=590 and  localPosition.x>=362 and localPosition.x<=1000 ){
                        //On masque les autres surbrillances
                        state->getRedMap()->setElement(posi_ref,0);
                        state->getRedMap()->setLocation(-100,-100,2); //TurnSurbrillance

                        WhiteSurbrillanceCommand* case_blanche=new WhiteSurbrillanceCommand(localPosition.x,localPosition.y);
                        engine.addCommand(1,case_blanche);
                        engine.update();
                    }

                    //Bouton Fin du Tour
                    else if(localPosition.x>=1030  and localPosition.y>=470 and localPosition.y<=540){
                       //On masque les autres surbrillances
                        state->getRedMap()->setElement(posi_ref,0);//Case Rouge
                        state->getRedMap()->setLocation(-100,-100,1);//WhiteSurbrillance

                       TurnSurbrillanceCommand* turn_blanche=new TurnSurbrillanceCommand;
                       engine.addCommand(1,turn_blanche);
                       engine.update();



                    }



                    else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<height and int(y_mouse_iso)>0 and int(y_mouse_iso)<width and ((x_mouse_iso+y_mouse_iso)<22) and localPosition.y<=615) {

                        state->getRedMap()->setLocation(-100,-100,1);//WhiteSurbrillance
                        state->getRedMap()->setLocation(-100,-100,2);//TurnSurbrillance

                        SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
                        engine.addCommand(1, case_rouge);
                        engine.update();
                    }

                    else{
                        //Masque toutes les surbrillances
                         state->getRedMap()->setLocation(-100,-100,2);
                         state->getRedMap()->setLocation(-100,-100,1);
                         state->getRedMap()->setElement(posi_ref,0);
                    }
=======
                // Souris déplacé seulement !
                else if(event.type==sf::Event::MouseMoved){
                    MouseMovedCommand* mouse_moved=new MouseMovedCommand(localPosition.x,localPosition.y);
                    engine.addCommand(1,mouse_moved);
                    engine.update();
>>>>>>> refs/remotes/origin/master
                }

                else if (event.type == sf::Event::MouseButtonPressed ){
<<<<<<< HEAD
                    ClickCommand* click=new ClickCommand(localPosition.x,localPosition.y);
                    engine.addCommand(1,click);
                    engine.update();
                    if (state->getTour()%2==0){
                        break;
                    }
                }*/
            


||||||| merged common ancestors

                        if(localPosition.y>=590 and  localPosition.x>=362 and localPosition.x<=1000 ){



                            AttackCommand* attaque= new AttackCommand(0,1,"Coup d'Epée");
                            engine.addCommand(1,attaque);
                            engine.update();

                        }

                        //Bouton Fin du Tour
                        if(localPosition.x>=1030  and localPosition.y>=470 and localPosition.y<=540){
                            //Changement de Tour
                            state->setTour(state->getTour()+1);
                            break;
                        }


                        else if(int(x_mouse_iso)>0 and int(x_mouse_iso)<height and int(y_mouse_iso)>0 and int(y_mouse_iso)<width and ((x_mouse_iso+y_mouse_iso)<22) and localPosition.y<=600) {

                            //Gestion Déplacement//
                            int vectX=int(x_mouse_iso)-c_ptr->getPosition().getX();
                            int vectY=int(y_mouse_iso)-c_ptr->getPosition().getY();

                            cout<<vectX<<endl;
                            cout<<vectY<<endl;
                            cout<<"Déplacement du personnage !"<<endl;

                            MoveCharacterCommand* deplacement=new MoveCharacterCommand(0,vectX,vectY);
                            engine.addCommand(2,deplacement);
                            engine.update();



                        }




                    }
=======
                    ClickCommand* click=new ClickCommand(localPosition.x,localPosition.y);
                    engine.addCommand(1,click);
                    engine.update();
                    if (state->getTour()%2==0){
                        break;
                    }
                }
                else if (state->getMenu()->getElementList()[0]->getTypeId()==6){
                    window.clear();
                    state->setEtat(2);
                    break;
                }
                
                //Fin d'une partie//
                for(int i=0; i<state->getCharacters()->getElementList().size();i++){
                    if(state->getCharacters()->getElementList()[i]->getStatut()==3){
                        break;
                    }
                }
         
>>>>>>> refs/remotes/origin/master
        // on dessine le niveau
<<<<<<< HEAD
            window.clear();

||||||| merged common ancestors
            window.clear();
=======
        */  window.clear();
>>>>>>> refs/remotes/origin/master
            window.draw(*elmtTabLayer_ptr->getSurface());
            window.draw(*elmtTabLayerLandscape_ptr->getSurface());
            window.draw(*elmtTabLayerWall_ptr->getSurface());
            window.draw(*elmtTabLayerMenu_ptr->getSurface());
            window.draw(*elmtTabLayerRed_ptr->getSurface());
            window.draw(*elmtTabLayer2_ptr->getSurface());
            window.draw(stateLayerMenu_ptr->getTextpv());
            window.draw(stateLayerMenu_ptr->getTextpvSram());
            window.draw(stateLayerMenu_ptr->getTextpa());
            window.draw(stateLayerMenu_ptr->getTextpm());
            window.display();
            

            //}

<<<<<<< HEAD
            }

        //}
||||||| merged common ancestors

        }
        }
=======
        }
>>>>>>> refs/remotes/origin/master

        ////Tour IA////
<<<<<<< HEAD
         else if (state->getTour()%2==0){
||||||| merged common ancestors
            else if (state->getTour()%2==0){
=======
         else if (state->getTour()%2==0){
                
>>>>>>> refs/remotes/origin/master
                cout<<"Tour :"<<state->getTour()<<endl;
                cout<<"//Tour IA//"<<endl;
		usleep(tempo);
                ///Gestion de l'IA///
<<<<<<< HEAD
                ai->run(engine,1,*state);

                /*MoveCharacterCommand* move = new MoveCharacterCommand(1,1,0);
                engine.addCommand(2,move);
                engine.update();*/

||||||| merged common ancestors
                ai.run(engine,1,*state);

                /*MoveCharacterCommand* move = new MoveCharacterCommand(1,1,0);
                engine.addCommand(2,move);
                engine.update();*/

                cout<<"Direction :"<<state->getCharacters()->getElementList()[1]->getDirection()<<endl;



=======
                usleep(microseconds);
                ai->run(engine,1,*state);
                
>>>>>>> refs/remotes/origin/master
                //Changement de Tour
                state->setTour(state->getTour()+1);
                if (state->getMenu()->getElementList()[0]->getTypeId()==6){
                    window.clear();
                    state->setEtat(2);
                }
                
                //Fin d'une partie//
                for(int i=0; i<state->getCharacters()->getElementList().size();i++){
                    if(state->getCharacters()->getElementList()[i]->getStatut()==3){
                        break;
                    }
                }
                
                // on dessine le niveau
                window.clear();

                window.draw(*elmtTabLayer_ptr->getSurface());
                window.draw(*elmtTabLayerLandscape_ptr->getSurface());
                window.draw(*elmtTabLayerWall_ptr->getSurface());
                window.draw(*elmtTabLayerMenu_ptr->getSurface());
                window.draw(*elmtTabLayerRed_ptr->getSurface());
                window.draw(*elmtTabLayer2_ptr->getSurface());
                window.draw(stateLayerMenu_ptr->getTextpv());
                window.draw(stateLayerMenu_ptr->getTextpvSram());
                window.draw(stateLayerMenu_ptr->getTextpa());
                window.draw(stateLayerMenu_ptr->getTextpm());
                window.display();
<<<<<<< HEAD

          }
||||||| merged common ancestors

            }




=======
                
            }
        
        
        
        
        ////////////////////
>>>>>>> refs/remotes/origin/master
    }
    else if(state->getEtat()==0){
        
        // on gère les évènements
        sf::Event event;
        while (window.waitEvent(event)){
            engine.update();
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            if(event.type == sf::Event::Closed){
                window.close();
            }
            
            // Souris déplacé seulement !
            else if(event.type==sf::Event::MouseMoved){
                MouseMovedCommand* mouse_moved=new MouseMovedCommand(localPosition.x,localPosition.y);
                engine.addCommand(1,mouse_moved);
                engine.update();
            }
            
            else if (event.type == sf::Event::MouseButtonPressed ){
                ClickCommand* click=new ClickCommand(localPosition.x,localPosition.y);
                engine.addCommand(1,click);
                engine.update();
                if (state->getEtat()==1){
                    break;
                }
                else if(state->getEtat()==3){//Exit State
                    window.close();
                }
            }
            
            window.clear();
            window.draw(*elmtTabLayerMenu_ptr->getSurface());
            window.display();
            
            
            
        }
        
    }
<<<<<<< HEAD
}
||||||| merged common ancestors


    catch(const char* e){
        cout<<"Exception :"<<e<<endl;
    }
=======
    else if(state->getEtat()==2){
        window.clear();
        window.draw(*elmtTabLayerMenu_ptr->getSurface());
        window.draw(stateLayerMenu_ptr->getTextwin());
        window.display();

        sf::Event event;
        while (window.waitEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }

            window.clear();
            window.draw(*elmtTabLayerMenu_ptr->getSurface());
            window.draw(stateLayerMenu_ptr->getTextwin());
            window.display();
        }
        
    }
    }
}
>>>>>>> refs/remotes/origin/master




//fin test map


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

        else if (strcmp(argv[1],"heuristic_ai")==0){
            //Test Map
            testSFML();

        }

    }

    return(0);

}
