#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    string etat_jeu="Menu";
    string commande_user;
    
    /*cout << "It works !" << endl;*/
    if (argc>1){                 // vérifie s'il y a un argument
        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
            cout << "Bonjour le monde!" << endl;
        }
        else if (strcmp(argv[1],"state")==0){
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
            Character iop("Iop");
            
             //Instancication Wall
            cout<<"   Instanciation Wall..."<<endl;
            Wall wall;
            
             //Instancication Landscape
            cout<<"   Instanciation Landscape..."<<endl;
            Landscape landscape;
            
             //Instancication Space
            cout<<"   Instanciation Space..."<<endl;
            Space space(1);
            
            //Instancication Equipment
            cout<<"   Instanciation Equipment..."<<endl;
            Equipment epee("Epée","main",5);
            
            //Instancication Abilities
            cout<<"   Instanciation Abilities..."<<endl;
            Abilities abilities("Sort",5,1);
            
            cout<<"Aucune Erreur"<<endl;
            
            cout<<endl;
            cout<<"/Test de methodes des classes/"<<endl;
            
            //Test affiche_Classe de Character//
            cout<<"   Test affiche_Classe..."<<endl;
            
            //Character//
            cout<<"      Test Character"<<endl;
            cout<<"      Result: ";
            iop.affiche_Classe();
            
            //Wall//
            cout<<"      Test Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Classe();
            
            //Space//
            cout<<"      Test Space"<<endl;
            cout<<"      Result: ";
            space.affiche_Classe();
            
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
            cout<<"   Test affiche_Position..."<<endl;
            cout<<"      Test sur Character"<<endl;
            cout<<"      Result: ";
            iop.affiche_Position();
            
            cout<<"      Test sur Wall"<<endl;
            cout<<"      Result: ";
            wall.affiche_Position();
            
            cout<<"      Test sur Landscape"<<endl;
            cout<<"      Result: ";
            landscape.affiche_Position();
            
            cout<<"      Test sur Space"<<endl;
            cout<<"      Result: ";
            space.affiche_Position();
            
            cout<<endl;
            
            //Test affiche_Stats de Character//
            cout<<"   Test affiche_Stats sur Character"<<endl;
            cout<<"      Result: ";
            iop.affiche_Stats();
            
            cout<<endl;
           
            
            
            //Test affiche_EquipmentList de Character//
            cout<<"   Test affiche_EquipmentList sur Character"<<endl;
            cout<<"      Result: ";
            iop.affiche_EquipmentList();
            
            
            
            
           
            
            
   
            
           
        }
    }
    
    Character* iop_ptr=new Character("Iop");
    Position* pos = new Position(4,3);
    iop_ptr->setPosition(*pos);
    vector<Element*> elementList;
    
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


