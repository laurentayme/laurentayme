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
//Json
#include "json/json.h"

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();


using namespace std;
using namespace state;
using namespace render;
using namespace engine;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <valarray>



std::vector<std::vector<Element*>> LoadMapFromFile(std::string filePath){
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

void testSFML() {
    	sf::Texture texture;
        std::vector<Element*> elmt_list;
        std::vector<Element*> elmt_list_landscape;
        std::vector<Element*> elmt_list_wall;
        std::vector<Element*> elmt_list2;
        std::vector<Element*> elmt_listRed;
	std::vector<Element*> listMenu;

        //Paramètres de Map//
        int width=11;
        int height=16;

        

        ////Instanciation de la  MAP////

            //Création des cases//
                /*for(int i=0;i<height;i++){
                    for(int j=0;j<width;j++){
                        if(i==0 || j==0){
                            //Affichage Pierre
                            /*Space* s_ptr=new Space(1);
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
                }*/
            ////////////////////

            //Création du Landscape//
                /*for(int i=2;i<height-2;i++){
                    for(int j=1;j<width-2;j++){
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
                }*/
            ////////////////////

            //Affichage des Wall//
                /*for(int i=0;i<height;i++){
                    for(int j=0;j<width;j++){
                        if(i==0|| j==0){//Visible Wall
                            Wall* w_ptr= new Wall;
                            Position position_wall(i,j);
                            Position posref_wall=position_wall;
                            w_ptr->setPosition(posref_wall);
                            elmt_list_wall.push_back(w_ptr);
                        }
                        //Invisible Wall
                        else if(i==height-1|| j==width-1){
                            Wall* w_ptr= new Wall;
                            w_ptr->setWallType(2);
                            Position position_wall(i,j);
                            Position posref_wall=position_wall;
                            w_ptr->setPosition(posref_wall);
                            elmt_list_wall.push_back(w_ptr);
                        }
                    }
                }*/
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
                Position pos_sad(3,4);
                sad_ptr->setPosition(pos_sad);
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




            //State MEnu list
            Space* state_menu=new Space(1);
            state_menu->setTypeId(2);
            listMenu.push_back(state_menu);

        /////// FIN Instanciation MAP /////////////

        std::string filePath="/home/valentin/laurentayme/res/First_Dungeon.json";
        //Création des ElementTab//
        elmt_list=LoadMapFromFile(filePath)[0];
        elmt_list_landscape=LoadMapFromFile(filePath)[1];
        elmt_list_wall=LoadMapFromFile(filePath)[2];
        ElementTab* elmtTab_ptr=new ElementTab(width,height,elmt_list);
        ElementTab* elmtTab2_ptr=new ElementTab(width,height,elmt_list2);
        ElementTab* elmtTabLandscape_ptr=new ElementTab(width,height,elmt_list_landscape);
        ElementTab* elmtTabWall_ptr=new ElementTab(width,height,elmt_list_wall);
        ElementTab* elmtTabRed_ptr=new ElementTab(width,height,elmt_listRed);

        ElementTab* elmtTabMenu_ptr = new ElementTab(width,height,listMenu);


	//Creation de State

        State* state=new State;
	state->setMap(elmtTab_ptr);
	state->setCharacters(elmtTab2_ptr);
	state->setMenu(elmtTabMenu_ptr);
	state->setLandscape(elmtTabLandscape_ptr);
        state->setTour(1);

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

        //Surbrillance
        state->setRedMap(&elmtTabLayerRed_ptr->getTab());

        //Engine & Observables
	Engine engine;
        Observable observable;

        engine.setState(*state);

        //Random IA
        //ai::Random_AI ai(1);
        ai::HeuristicAI* ai;
        ai=new ai::HeuristicAI(*state,1);
        
        elmtTab2_ptr->addObserver(ai);

        //Gestion des tours
        int tour=state->getTour();

        //PA et PM initiaux//

            //PA
            int iop_pa=state->getCharacters()->getElementList()[0]->getPA();
            int sram_pa=state->getCharacters()->getElementList()[1]->getPA();

            //PM
            int iop_pm=state->getCharacters()->getElementList()[0]->getPM();
            int sram_pm=state->getCharacters()->getElementList()[1]->getPM();

            //cout<<sram_pm<<endl;

    //Horloge
            
    sf::Clock clock;


    ///// Création de la fenêtre/////
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(24);

    while (window.isOpen()){

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

        //Réinitialisation des Stats//
        state->getCharacters()->setCharacterPA(0,iop_pa);
        state->getCharacters()->setCharacterPA(1,sram_pa);

        state->getCharacters()->setCharacterPM(0,iop_pm);
        state->getCharacters()->setCharacterPM(1,sram_pm);



        ////Tour Joueur////
        if(state->getTour()%2==1){
            cout<<"Tour :"<<state->getTour()<<endl;
            cout<<"//Tour Joueur//"<<endl;
            // on gère les évènements
            sf::Event event;
            while (window.waitEvent(event)){
                engine.update();

                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                float Tile_height=60.0/1.30;
                float Tile_Width=120.0/1.28;


                float x_mouse_iso=(localPosition.y-30)/Tile_height-(localPosition.x-650-Tile_Width/2)/Tile_Width;

                float y_mouse_iso=(localPosition.y-30)/Tile_height+(localPosition.x-650-Tile_Width/2)/Tile_Width;


                if(event.type == sf::Event::Closed){
                    window.close();
                }


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
                }


                else if (event.type == sf::Event::MouseButtonPressed ){

                        if(localPosition.y>=590 and  localPosition.x>=362 and localPosition.x<=1000 ){



                            AttackCommand* attaque= new AttackCommand(0,1,localPosition.x,localPosition.y);
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

        ////Tour IA////
            else if (state->getTour()%2==0){
                cout<<"Tour :"<<state->getTour()<<endl;
                cout<<"//Tour IA//"<<endl;
                ///Gestion de l'IA///
                ai->run(engine,1,*state);

                /*MoveCharacterCommand* move = new MoveCharacterCommand(1,1,0);
                engine.addCommand(2,move);
                engine.update();*/

                cout<<"Direction :"<<state->getCharacters()->getElementList()[1]->getDirection()<<endl;



                //Changement de Tour
                state->setTour(state->getTour()+1);

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




//fin test map


///// Fin Fenetre SFML /////


    
    
    /*Json::Reader reader;
    Json::Value root;
    bool parsing = reader.parse(ifs,root,false);
    if(parsing){
     }
        
    //std::string text="{ \"people\": [{\"id\": 1, \"name\":\"MIKE\",\"surname\":\"TAYLOR\"}, {\"id\": 2, \"name\":\"TOM\",\"surname\":\"JERRY\"} ]}";
    
    const Json::Value defValue; //used for default reference
    //bool parsing=reader.parse(ifs,root);
    
        
        
        
        Json::Value height=root["height"];
        cout<<height.asInt()<<endl;
        
    }
    else{
        cout<<"Parsing doesn't work !"<<endl;
    }*/
    
    

    
 


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

        else if (strcmp(argv[1],"ai")==0){
            //Test Map
            testSFML();

        }

    }

    return(0);

}
