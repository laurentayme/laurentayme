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
#include <fstream>
#include <unistd.h>

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
//sf::Time tempo = sf::seconds(0.5);


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <valarray>
#include <stack>

void testSFML(int isRoll) {
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
        
        
        //CLock
        clock_t t;
        t=clock();

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

        //Chargement du niveau depuis un fichier json//
        std::string filePath="res/First_Dungeon.json";
        state->LoadMapFromFile(filePath);
        ///////////////////////
        

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

        //Surbrillance
        state->setRedMap(&elmtTabLayerRed_ptr->getTab());

        //Engine & Observables
	Engine engine;
        Observable observable;

        engine.setState(state);

        //Random IA
        //ai::Heuristic_AI ai(1);
        //ai::Random_AI ai_2(0);
        //ai::HeuristicAI* ai=new ai::HeuristicAI(*state,1,1);
        //ai::HeuristicAI* ai_2=new ai::HeuristicAI(*state,2,0);
        
        ai::DeepAI* ai=new ai::DeepAI(*state,2,1);
        ai::DeepAI* ai_2=new ai::DeepAI(*state,2,0);
        
        
        //Mise en place d'Observers sur les AI
        elmtTab2_ptr->addObserver(ai);
        elmtTab2_ptr->addObserver(ai_2);

        //elmtTab2_ptr->addObserver(ai);

        //Gestion des tours
        int tour=state->getTour();

        //PA et PM initiaux//

            //PA
            int iop_pa=state->getCharacters()->getElementList()[0]->getPA();
            int sram_pa=state->getCharacters()->getElementList()[1]->getPA();

            //PM
            int iop_pm=state->getCharacters()->getElementList()[0]->getPM();
            int sram_pm=state->getCharacters()->getElementList()[1]->getPM();
        ////////////////////  

    ///// Création de la fenêtre/////
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(24);

    if(isRoll==0){
        while (window.isOpen()){



            if(state->getEtat()==1){
            //stateLayerMenu_ptr->initSurface();
            //Réinitialisation des Stats//
            state->getCharacters()->setCharacterPA(0,iop_pa);
            state->getCharacters()->setCharacterPA(1,sram_pa);

            state->getCharacters()->setCharacterPM(0,iop_pm);
            state->getCharacters()->setCharacterPM(1,sram_pm);
            /////////////////////////////


            ////Tour Joueur////
            if(state->getTour()%2==1){


                cout<<"Tour :"<<state->getTour()<<endl;
                cout<<"//Tour Joueur//"<<endl;

                //usleep(microseconds);
                try{
                    ai_2->run(engine,0,*state);
                    state->setTour(state->getTour()+1);
                }
                catch(const char* e){
                    cout<<"Exception :"<<e<<endl;
                }




                // on gère les évènements
                /*sf::Event event;
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
                    }*/

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

                //}

            }

            ////Tour IA////
             else if (state->getTour()%2==0){

                    cout<<"Tour :"<<state->getTour()<<endl;
                    cout<<"//Tour IA//"<<endl;
                    ///Gestion de l'IA///
                    //usleep(microseconds);
                    try{
                        ai->run(engine,1,*state);
                    }
                    catch(const char* e){
                        cout<<"Exception :"<<e<<endl;
                    }


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

                }




            ////////////////////
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
    //Cas du RollBack
    else if(isRoll==1){
        
        stack<State> state_stack;
        
        while (window.isOpen()){
            
            std::cout<<"Actual Time :"<<float(clock())/CLOCKS_PER_SEC<<std::endl;
            if(float(clock())/CLOCKS_PER_SEC>=30){
                
                std::cout<<"Taille de Pile :"<<state_stack.size()<<std::endl;
                
                while(!state_stack.empty()){
                    State state_prec=state_stack.top();

                    state_stack.pop();
                    
                    ElementTab* chars=state->getCharacters();
                    ElementTab* menu=state->getMenu();
                    std::vector<Element*> chars_clone=state_prec.getCharacters()->getElementList();
                    std::vector<Element*> menu_clone=state_prec.getMenu()->getElementList();
                    
                    for(size_t i=0;i<chars->getElementList().size();i++){
                        chars->setElementDirection(chars_clone[i]->getDirection(),i);
                        chars->setCharacterStatut(i,chars_clone[i]->getStatut());
                        Position pos=chars_clone[i]->getPosition();
                        chars->setElement(pos,i);
                        chars->setCharacterPV(i,chars_clone[i]->getPV());
                        chars->setCharacterPM(i,chars_clone[i]->getPM());
                        chars->setCharacterPA(i,chars_clone[i]->getPA());  
                        
                        menu->getElementList().pop_back();
                        menu->getElementList().push_back(menu_clone[0]);
                        
                        
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
                        
                        if(i==0){
                            //cout<<"Iop Cloné :"<<chars_clone[i]->getPV()<<endl;
                            //cout<<"Iop :"<<chars->getElementList()[0]->getPV()<<endl;
                        }
                        
                        
                        
                        
                        usleep(microseconds);
                        
                    }
                  
                }

                window.close();
            }
            else{
                
                //On met l'état initial
                state_stack.push(state->Clone());
                
                
                if(state->getEtat()==1){
        //stateLayerMenu_ptr->initSurface();
        //Réinitialisation des Stats//
        state->getCharacters()->setCharacterPA(0,iop_pa);
        state->getCharacters()->setCharacterPA(1,sram_pa);

        state->getCharacters()->setCharacterPM(0,iop_pm);
        state->getCharacters()->setCharacterPM(1,sram_pm);
        /////////////////////////////

        
        ////Tour Joueur////
        if(state->getTour()%2==1){
            
            
            cout<<"Tour :"<<state->getTour()<<endl;
            cout<<"//Tour Joueur//"<<endl;
            
            usleep(microseconds);
            try{
                ai_2->run(engine,0,*state);
                state->setTour(state->getTour()+1);
            }
            catch(const char* e){
                cout<<"Exception :"<<e<<endl;
            }
            
           
            
            
            // on gère les évènements
            /*sf::Event event;
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
                }*/
         
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
            
            //}
            
            //On sauvegarde l'état dans la pile des états
            state_stack.push(state->Clone());

        }

        ////Tour IA////
         else if (state->getTour()%2==0){
                
                cout<<"Tour :"<<state->getTour()<<endl;
                cout<<"//Tour IA//"<<endl;
                ///Gestion de l'IA///
                usleep(microseconds);
                try{
                    ai->run(engine,1,*state);
                }
                catch(const char* e){
                    cout<<"Exception :"<<e<<endl;
                }
                
                
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
                
                //On sauvegarde l'état dans la pile des états
                state_stack.push(state->Clone());
                
            }
        
        
        
        
        ////////////////////
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
    }
}




//fin test map


///// Fin Fenetre SFML /////


int main(int argc,char* argv[])
{
    int isRoll=0;
    //testSFML();
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
                //Test_Unitaire();

        }

        else if (strcmp(argv[1],"deep_ai")==0 or strcmp(argv[1],"rollback")==0){
            //Test Map
            
            if(strcmp(argv[1],"rollback")==0){
                isRoll=1;
            }
            
            testSFML(isRoll);

        }

    }

    return(0);

}
