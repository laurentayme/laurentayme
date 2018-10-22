#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <exception>
#include "state.h"


using namespace std;
using namespace state;

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    	sf::Texture texture;
    	//sf::Texture texture2;
    
	//sf::VertexArray carre(sf::Quads, 4);
	//sf::VertexArray carre2(sf::Quads, 4);
	std::vector<sf::VertexArray> quadlist;
	for(int j=0;j<5;j++){
	
		for(int i=0;i<5;i++){
    			sf::VertexArray quadd(sf::Quads,4);
    			quadd[0].position = sf::Vector2f(j*400,400*i);
    			quadd[1].position = sf::Vector2f(j*400,400*(i+1));
    			quadd[2].position = sf::Vector2f(400*(j+1),400*(i+1));
    			quadd[3].position = sf::Vector2f(400*(j+1),400*i);
    			quadd[0].texCoords = sf::Vector2f(0, 0);
    			quadd[1].texCoords = sf::Vector2f(0, 400);
    			quadd[2].texCoords = sf::Vector2f(400,400);
    			quadd[3].texCoords = sf::Vector2f(400,0);
    			quadlist.push_back(quadd);
		}
	}

	/*// essai sur les quads
	carre[0].position = sf::Vector2f(0, 0);
	carre[1].position = sf::Vector2f(0, 400);
	carre[2].position = sf::Vector2f(400, 400);
	carre[3].position = sf::Vector2f(400, 0);
	carre2[0].position = sf::Vector2f(400, 0);
	carre2[1].position = sf::Vector2f(400, 400);
	carre2[2].position = sf::Vector2f(800, 400);
	carre2[3].position = sf::Vector2f(800, 0);

	// on définit la couleur des sommets du carre
	/*carre[0].color = sf::Color::Red;
	carre[1].color = sf::Color::Blue;
	carre[2].color = sf::Color::Green;
	carre[3].color = sf::Color::Yellow;*/

	/*carre[0].texCoords = sf::Vector2f(0, 0);
	carre[1].texCoords = sf::Vector2f(0, 400);
	carre[2].texCoords = sf::Vector2f(400,400);
	carre[3].texCoords = sf::Vector2f(400,0);
	carre2[0].texCoords = sf::Vector2f(0, 0);
	carre2[1].texCoords = sf::Vector2f(0, 400);
	carre2[2].texCoords = sf::Vector2f(400,400);
	carre2[3].texCoords = sf::Vector2f(400,0);*/

	texture.loadFromFile("/home/vincent/Bureau/pltimages/myAvatar2.png");
	//texture2.loadFromFile("/home/vincent/Bureau/pltimages/myAvatar.png");

	sf::RenderWindow window(sf::VideoMode(2000, 2000), "My window");
	while (window.isOpen())
	    {
	        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la 			précédente itération
        	sf::Event event;
        	while (window.pollEvent(event))
        	{
        	    // évènement "fermeture demandée" : on ferme la fenêtre
        	    if (event.type == sf::Event::Closed)
        	        window.close();
        	}
        	window.clear(sf::Color::Black);
            	for(int i=0;i<25;i++){
                window.draw(quadlist[i],&texture);
        	}
       	 	//window.draw(carre, &texture);
        	//window.draw(carre2, &texture2);
        	//window.draw(carre);
       	 	window.display();
    }



    
}

// Fin test SFML

// test map

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(2*width * height * 4);


        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width*2; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width*2) * 4];
		

                // on définit ses quatre coins
		if(i%2==0){
                	quad[0].position = sf::Vector2f(i/2 * tileSize.x+32, j * tileSize.y);
                	quad[1].position = sf::Vector2f((i/2 + 1) * tileSize.x, j * tileSize.y+16);
                	quad[2].position = sf::Vector2f((i/2 + 1) * tileSize.x-32, (j + 1) * tileSize.y);
                	quad[3].position = sf::Vector2f(i/2 * tileSize.x, (j + 1) * tileSize.y-16);
		}
		else{
			quad[0].position = sf::Vector2f((i+1)/2 * tileSize.x, j * tileSize.y+16);
                	quad[1].position = sf::Vector2f(((i+1)/2 + 1) * tileSize.x-32, (j+1) * tileSize.y);
                	quad[2].position = sf::Vector2f((i+1)/2 * tileSize.x, (j + 1) * tileSize.y+16);
                	quad[3].position = sf::Vector2f((i+1)/2 * tileSize.x-32, (j + 1) * tileSize.y);
		}
                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x+32, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y+16);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x-32, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y-16);
		
            }

        return true;
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);

    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

//fin test map



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
    }
    string etat_jeu="Menu";
    string commande_user;
    
    /*cout << "It works !" << endl;*/
    
    /*
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
  */
    
//test map
	// on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(640, 320), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
       	0, 0, 0, 0, 0, 0, 1, 1, 1, 1,1, 1, 1, 1, 1, 1,0, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 2, 0, 0,0, 0,1, 1, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 3, 3, 3, 3, 3,0, 1,0, 0, 2, 0, 4, 4, 3, 0, 1, 1,
	1, 0, 0, 0,0, 1, 1, 0, 3, 3,3, 7, 7, 0, 1, 1, 1, 2, 0, 0,
	1, 0, 1, 0, 1, 0, 1, 0, 1, 0,1 ,0, 0, 5, 4, 6, 8, 8, 8, 7,
	0, 0, 0, 0, 0, 0, 1, 1, 1, 1,1, 1, 1, 1, 1, 1,0, 1, 1, 1, 
	1, 1, 1, 0, 0, 0, 0, 2, 0, 0,0, 0,1, 1, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 3, 3, 3, 3, 3,0, 1,0, 0, 2, 0, 4, 4, 3, 0, 1, 1,
	1, 0, 0, 0,0, 1, 1, 0, 3, 3,3, 7, 7, 0, 1, 1, 1, 2, 0, 0,
	1, 0, 1, 0, 1, 0, 1, 0, 1, 0,1 ,0, 0, 5, 4, 6, 8, 8, 8, 7
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("/home/vincent/Bureau/pltimages/tilsetsaisonplat.png", sf::Vector2u(64, 32), level, 10,10))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }
//fin test mapS



    return 0;
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

