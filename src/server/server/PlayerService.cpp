/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */
#include <stdio.h>
#include "server.h"

using namespace std;
using namespace server;

PlayerService::PlayerService (Game& game) : AbstractService("/user"),
    game(game) {
    
}

HttpStatus PlayerService::get (Json::Value& out, int id) const {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    if(id<1 or id>2){
        throw ServiceException(HttpStatus::NOT_FOUND, "Invalid Player ID !");
    }
    else{
        out["name"]=game.getPlayer(id).name;
        out["free"]=game.getPlayer(id).free;
        return(HttpStatus::OK);
    }     
}

HttpStatus PlayerService::post (const Json::Value& in, int id) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    if(in.isMember("free")){
        //Copie des données d'utilisateur
        Player futur_user(game.getPlayer(id));
        
        futur_user.free=in["free"].asBool();
        game.setPlayer(id, futur_user);  
        return(HttpStatus::OK);
    }   
    else if(in.isMember("name")){
        //Copie des données d'utilisateur
        Player futur_user(game.getPlayer(id));
        
        futur_user.name=in["name"].asString();
        game.setPlayer(id, futur_user); 
        return(HttpStatus::OK);
    }
    else if(in.isMember("name") and in.isMember("free")){
        //Copie des données d'utilisateur
        Player futur_user(game.getPlayer(id));
        
        futur_user.name=in["name"].asString();
        futur_user.free=in["free"].asBool();
        game.setPlayer(id, futur_user); 
        return(HttpStatus::OK);
    }
    else{
        throw ServiceException(HttpStatus::BAD_REQUEST,"Bad POST Request");
    }
    
    
}

HttpStatus PlayerService::put (Json::Value& out,const Json::Value& in) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    int id=-1;
    
    if(in.isMember("free")){
        Player new_player(in["name"].asString(),in["free"].asBool());
        id=game.getPlayers().size()+1;
        game.addPlayer(new_player);
    }
    else{
        Player new_player(in["name"].asString(),true);
        id=game.getPlayers().size()+1;
        game.addPlayer(new_player);
        
    }
    for(int i=0;i<game.getPlayers().size();i++){
    Json::Value valeur;
    valeur["name"]=game.getPlayers()[i].name;
    valeur["free"]=game.getPlayers()[i].free;
    out.append(valeur);
    }
               
    //Ecriture de la sortie
    //out["id"]=id;
    return(HttpStatus::OK);
}

HttpStatus PlayerService::remove (Json::Value& out,int id) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    if(id>=0 and id<=game.getPlayers().size()){
        game.removePlayer(id);
	if(game.getPlayers().size()!=0){
		for(int i=0;i<game.getPlayers().size();i++){
	    		Json::Value valeur;
	    		valeur["name"]=game.getPlayers()[i].name;
	    		valeur["free"]=game.getPlayers()[i].free;
	    		out.append(valeur);
	    	}
	}
	else{
		out["joueur"]="aucun";
	}
       return(HttpStatus::OK);
    }
    
    else{
        throw ServiceException(HttpStatus::BAD_REQUEST,"Bad Player ID !");
    }
}

Game PlayerService::getGame() const{
    return(game);
}

