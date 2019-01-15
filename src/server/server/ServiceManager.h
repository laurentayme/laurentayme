// Generated by dia2code
#ifndef SERVER__SERVICEMANAGER__H
#define SERVER__SERVICEMANAGER__H

#include <vector>
#include <memory>
#include <string>

namespace server {
  class AbstractService;
}

#include "AbstractService.h"
#include "HttpStatus.h"

namespace server {

  /// class ServiceManager - 
  class ServiceManager {
    // Associations
    // Attributes
  protected:
    std::vector<std::unique_ptr<AbstractService>> services;
    // Operations
  public:
    void registerService (std::unique_ptr<AbstractService> service);
    AbstractService const findService (const std::string& url);
    HttpStatus queryService (std::string& out, const std::string& in, const std::string& url,  const std::string& method);
    // Setters and Getters
    const std::vector<std::unique_ptr<AbstractService>>& getServices() const;
    void setServices(const std::vector<std::unique_ptr<AbstractService>>& services);
  };

};

#endif