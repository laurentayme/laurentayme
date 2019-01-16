#include <stdio.h>
#include "server.h"

using namespace std;
using namespace server;

GameService::GameService(Game& game) : game(game){

}

HttpStatus GameService::get(Json::Value& out,int id) const {

}
