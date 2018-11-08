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
        std::vector<Element*> elmt_listRed;
	std::vector<Element*> listMenu;
        /*sf::Text text;
        sf::Text textpa;
        sf::Text textpm;
        sf::Font font;*/

        //Paramètres de Map//
        int width=9;
        int height=12;


        ////Instanciation de la  MAP////

            //Création des cases//
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
            ////////////////////

            //Création du Landscape//
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
            ////////////////////

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
            ////////////////////


            //Affichage Personnages//
                Character* c_ptr=new Character("Iop");
                Character* sad_ptr=new Character("Sadida");
                c_ptr->setTypeId(1);
                c_ptr->setDirection(1); //Nord
                Position pos(height-1,width/2);
                c_ptr->setPosition(pos);
                Position pos_sad(1,width/2);
                sad_ptr->setPosition(pos_sad);
                //c_ptr->setDirection(4);
                elmt_list2.push_back(c_ptr);
                elmt_list2.push_back(sad_ptr);
            ////////////////////////

            //Element List Surbrillance//
                Space* red_space=new Space(4);
                elmt_listRed.push_back(red_space);

        /////// FIN Instanciation MAP /////////////

        //Création des ElementTab//

        ElementTab* elmtTab_ptr=new ElementTab(8,12,elmt_list);
        ElementTab* elmtTab2_ptr=new ElementTab(8,12,elmt_list2);
        ElementTab* elmtTabLandscape_ptr=new ElementTab(8,12,elmt_list_landscape);
        ElementTab* elmtTabWall_ptr=new ElementTab(8,12,elmt_list_wall);
        ElementTab* elmtTabRed_ptr=new ElementTab(8,12,elmt_listRed);



	//Creation de State
	Space* state_ptr=new Space(1);
	state_ptr->setTypeId(2);
	listMenu.push_back(state_ptr);
	ElementTab* elmtTabMenu_ptr = new ElementTab(1,1,listMenu);
	State stateMenu;
	stateMenu.setMap(elmtTab_ptr);
	stateMenu.setCharacters(elmtTab2_ptr);
	stateMenu.setMenu(elmtTabMenu_ptr);

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

	//State
	State& stateMenu_ref=stateMenu;
	StateLayer stateMenuLayer(stateMenu_ref);

        ////////////////////////////////

        ElementTabLayer* elmtTabLayer_ptr=new ElementTabLayer(tab_ref);
        ElementTabLayer* elmtTabLayer2_ptr=new ElementTabLayer(tab_ref2);
        ElementTabLayer* elmtTabLayerLandscape_ptr=new ElementTabLayer(tab_ref_landscape);
        ElementTabLayer* elmtTabLayerWall_ptr=new ElementTabLayer(tab_ref_wall);
        ElementTabLayer* elmtTabLayerRed_ptr=new ElementTabLayer(tab_ref_red);
	StateLayer* elmtStateLayerMenu_ref=new StateLayer(stateMenu_ref);

        //Ajout d'observers sur chaque Couche: map + Personnages//
	elmtTabMenu_ptr->addObserver(elmtStateLayerMenu_ref);
        elmtTab_ptr->addObserver(elmtTabLayer_ptr);
        elmtTab2_ptr->addObserver(elmtTabLayer2_ptr);
        elmtTabRed_ptr->addObserver(elmtTabLayerRed_ptr);

        //////////////////////////////////////////////////////////

        //Initialisation de la Surface de chaque Layer
        try{
            elmtTabLayer_ptr->initSurface();
            elmtTabLayer2_ptr->initSurface();
            elmtTabLayerLandscape_ptr->initSurface();
            elmtTabLayerWall_ptr->initSurface();
            elmtTabLayerRed_ptr->initSurface();
		stateMenuLayer.initSurface();
        }
        catch(const char* e){
            cout<<"Exception: "<<e<<endl;
        }

        //Définition du State
        /*State state;
        state.setMap(&elmtTabLayer_ptr->getTab());
        state.setCharacters(&elmtTabLayer2_ptr->getTab());*/

        //Surbrillance
        stateMenu.setRedMap(&elmtTabLayerRed_ptr->getTab());

    //Engine & Observables
	Engine engine;
        Observable observable;

        engine.setState(stateMenu);


    ///// Création de la fenêtre/////
    sf::RenderWindow window(sf::VideoMode(149*8, 86*9), "Tilemap");
    while (window.isOpen()){

        

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

                if(int(x_mouse_iso)>0 and int(x_mouse_iso)<12 and int(y_mouse_iso)>0 and int(y_mouse_iso)<9) {

                    //Gestion Surbrillance//

                    SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
                    engine.addCommand(1, case_rouge);
                    engine.update();
                }
            }
                   
                    
            else if (event.type == sf::Event::MouseButtonPressed ){
                    
                    if(int(x_mouse_iso)>0 and int(x_mouse_iso)<12 and int(y_mouse_iso)>0 and int(y_mouse_iso)<9) {

                    //Gestion Surbrillance//

                    SurbrillanceCommand* case_rouge=new SurbrillanceCommand(int(x_mouse_iso),int(y_mouse_iso));
                    engine.addCommand(1, case_rouge);
                    engine.update();
                

                                   cout<<"Click X :"<<x_mouse_iso<<"/ Click Y: "<<y_mouse_iso<<endl;


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
                    
    


        // on dessine le niveau
        window.clear();
        window.draw(*elmtTabLayer_ptr->getSurface());
        window.draw(*elmtTabLayerRed_ptr->getSurface());
        window.draw(*elmtTabLayerLandscape_ptr->getSurface());
        window.draw(*elmtTabLayerWall_ptr->getSurface());
        window.draw(*elmtTabLayer2_ptr->getSurface());
	window.draw(*stateMenuLayer.getSurface());
	window.draw(stateMenuLayer.getTextpv());
        window.draw(stateMenuLayer.getTextpa());
        window.draw(stateMenuLayer.getTextpm());
        

        window.display();
    }
    }




//fin test map
}
///// Fin Fenetre SFML /////


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
