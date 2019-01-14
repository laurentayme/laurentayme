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
    Player* player;
    if(id!=1 and id !=2){
        throw(HttpStatus::NOT_FOUND, "Invalid Player ID !");
    }
    else{
        *player=game.getPlayer(id);
        out["name"]=player->name;
        out["free"]=player->free;
    }     
}

HttpStatus PlayerService::post (const Json::Value& in, int id) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    if(in.isMember("name")){
        //Copie des données d'utilisateur
        Player futur_user(game.getPlayer(id));
        
        futur_user.free=in["free"].asBool();
        game.setPlayer(id, futur_user);    
    }
    
    
}

HttpStatus PlayerService::put (Json::Value& out,const Json::Value& in) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    Player new_player(in["name"].asString(),true);
    int id=game.getPlayers().size()+1;
    game.addPlayer(new_player);
                
    //Ecriture de la sortie
    out["id"]=id;
    
}

HttpStatus PlayerService::remove (int id) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    if(id>=0 and id<game.getPlayers().size()){
        game.removePlayer(id);
        return(HttpStatus::OK);
    }
    else{
        throw(HttpStatus::BAD_REQUEST,"Bad Player ID !");
    }
}

Game PlayerService::getGame() const{
    return(game);
}

