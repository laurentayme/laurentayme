<<<<<<< HEAD
#include <stdio.h>
#include "state.h"
#include "engine.h"
#include "client.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>



using namespace client;

Client::Client(){

}

void Client::engineUpdating(){
	characters_ai->run(engine,0,engine.getState());
	
}

void Client::engineUpdated(){
	engine.getState()->flushCachedEvents();
}

void Client::run(){
	//engine.run();
}
||||||| merged common ancestors
=======
#include <stdio.h>
#include "client.h"
#include <memory>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace client;
>>>>>>> refs/remotes/origin/master
