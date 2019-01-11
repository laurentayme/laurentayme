/** 
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "client.h"
#include "json/json.h"

using namespace std;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    this->services.push_back(std::move(service));  
}

AbstractService* ServicesManager::findService (const string& url) const {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    for(size_t i=0; i<services.size();i++){
        if(services[i].getPattern()=="/version" or services[i].getPattern()=="version/suite" or services[i].getPattern()=="version/23"){
            return(services[i]);
        }
        else{
            return(nullptr);
        }
    }
    
    
    
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    if(url!="/version"){
        throw ServiceException(HttpStatus::BAD_REQUEST,"Bad URL !");
    }
    
    else{
        AbstractService* my_service;
        my_service=findService(url)
        if(my_service!=nullptr){
            
            if(method=="GET"){
                my_service.get();
                return(HttpStatus::OK);
            }
            else if(method=="PUT"){
                my_service.put();
                return(HttpStatus::OK);
            }
            else if(method=="POST"){
                my_service.post();
                return(HttpStatus::OK);
            }
            else if(method=="REMOVE"){
                my_service.remove();
                return(HttpStatus::OK);
            }
            else{
                return(HttpStatus::BAD_REQUEST);
            }    
        }
        else{
            return(HttpStatus::NOT_FOUND);
        }
        
    }
        
}

/*std::ifstream file("version.json");
        if(!file){  
            std::cout << "File opening failed\n";
            std::ofstream myfile;
            myfile.open("version.json",std::ofstream::out | std::ofstream::app);
            myfile<<"[{"<<"\n";
            myfile<<"major: "<<"1"<<", \n";
            myfile<<"minor: "<<"0"<<", \n";
            myfile<<"}]";
            file.close();  
    }*/
