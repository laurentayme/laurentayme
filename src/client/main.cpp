#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include "state.h"

using namespace std;
using namespace state;

void Test_Unitaire();


int main(int argc,char* argv[])
{
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
                Test_Unitaire();
    
        }
    }
    string etat_jeu="Menu";
    string commande_user;
    
    /*cout << "It works !" << endl;*/
    
    
    Character* iop_ptr=new Character("Iop");
    Position* pos = new Position(4,3);
    iop_ptr->setPosition(*pos);
    vector<Element*> elementList;
    
    try{
        iop_ptr->setPV(-3); 
    }
    catch(const char* e){
        cout<<"Exception: "<<e<<endl;
    }
    
    try{
        iop_ptr->setPA(-1);
    }
    catch(const char* e){
        cout<<"Exception: "<<e<<endl;
    }
    
    try{
        iop_ptr->setDirection(5);
    }
    catch(const char* e){
        cout<<"Exception: "<<e<<endl;
    }
    
    iop_ptr->affiche_Stats();
    
    elementList.push_back(iop_ptr);
    
    
    ElementTab carte(1,2,elementList);
    
    //carte.getElementList()[0]->affiche_Classe();
    
    /*Landscape land;
    Wall wall;
    Space space(1);
    land.affiche_Classe();
    wall.affiche_Classe();
    space.affiche_Classe();*/
  
    
    return 0;
}

void Test_Unitaire(){
    
            cout<<"//Phase de Tests unitaires//"<<endl;
            cout<<endl;

            //Test des instanciations
            cout<<"/Instanciation de chaque classe/"<<endl;
            
            //Instancication ElementTab
            cout<<"   Instanciation ElementTab..."<<endl;
            vector<Element*> elementList;
            ElementTab elTab(2,4,elementList);
            
            //Instancication Character
            cout<<"   Instanciation Character..."<<endl;
            Character* iop_ptr=nullptr;
            size_t c=0;
            try{
                iop_ptr= new Character("Io");
            }
            catch(const char* e){
                c+=1;
                cout<<"   Exception: "<<e<<endl;
            }
            
            //Instancication Wall
            cout<<"   Instanciation Wall..."<<endl;
            Wall wall;
            
            //Instancication Landscape
            cout<<"   Instanciation Landscape..."<<endl;
            Landscape landscape;
            
            //Instancication Space
            cout<<"   Instanciation Space..."<<endl;
            Space* space;
            try{
                space= new Space(1);
            }
            catch(const char* e){
                cout<<"Exception: "<<e<<endl;
            }
            
            //Instancication Equipment
            cout<<"   Instanciation Equipment..."<<endl;
            Equipment epee("Epée","main",5);
            
            //Instancication Abilities
            cout<<"   Instanciation Abilities..."<<endl;
            Abilities abilities("Sort",5,1);
            
            if(c==0){
                cout<<"   Aucune Erreur"<<endl;
            }
            else{
                cout<<"   Il y a eu "<<c<<" erreur(s) !"<<endl;
            }
            
            
            cout<<endl;
            cout<<"/Test de methodes des classes/"<<endl;
            
            //Test affiche_Classe de Character//
            cout<<"   Test affiche_Classe..."<<endl;
            
            //Character//
            if(iop_ptr!=nullptr){
                cout<<"      Test Character"<<endl;
                cout<<"      Result: ";
                iop_ptr->affiche_Classe();
            }
            //Wall//
            cout<<"      Test Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Classe();
            
            //Space//
            if(space!=nullptr){
                cout<<"      Test Space"<<endl;
                cout<<"      Result: ";
                space->affiche_Classe();
            }
            
            //Landscape//
            cout<<"      Test Landscape"<<endl;
            cout<<"      Result: ";
            landscape.affiche_Classe();
            
            cout<<endl;
            
            //Test affiche_Weapon de Equipment//
            cout<<"   Test affiche_Weapon sur Equipment"<<endl;
            cout<<"      Result: ";
            epee.affiche_Weapon();
            
            cout<<endl;
            
            //Test affiche_Position...//
            if(iop_ptr!=nullptr){
                cout<<"   Test affiche_Position..."<<endl;
                cout<<"      Test sur Character"<<endl;
                cout<<"      Result: ";
            
                iop_ptr->affiche_Position();
            }
            cout<<"      Test sur Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Position();
            
            cout<<"      Test sur Landscape"<<endl;
            cout<<"      Result: ";
            landscape.affiche_Position();
            
            if(space!=nullptr){
                cout<<"      Test sur Space"<<endl;
                cout<<"      Result: ";
                space->affiche_Position();
            }
            
            cout<<endl;
            
            //Test affiche_Stats de Character//
            if(iop_ptr!=nullptr){
                cout<<"   Test affiche_Stats sur Character"<<endl;
                cout<<"      Result: ";
                iop_ptr->affiche_Stats();
            }
            cout<<endl;
            
            
            
            //Test affiche_EquipmentList de Character//
            if(iop_ptr!=nullptr){
                cout<<"   Test affiche_EquipmentList sur Character"<<endl;
                cout<<"      Result: ";
                iop_ptr->affiche_EquipmentList();
            }
            delete iop_ptr;
            iop_ptr=nullptr;
            
            delete space;
            space=nullptr;
}

