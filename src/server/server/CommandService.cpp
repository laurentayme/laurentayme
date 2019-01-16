#include <stdio.h>
#include "server.h"

using namespace std;
using namespace server;

CommandService::CommandService(engine::Engine& engine) : engine(engine){

}

HttpStatus CommandService::get(Json::Value& out,int id) const {
	

}


HttpStatus CommandService::put(Json::Value& out, Json::Value& in){

}
