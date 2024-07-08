
#include "AppComponent.h"

#include "controller/UserController.h"
#include "controller/StaticController.h"

#include "oatpp-swagger/Controller.hpp"

#include "oatpp/network/Server.hpp"

#include <iostream>

void run() {
  
  AppComponent components; // Environment components Object
  
  // Router component is here
  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  oatpp::web::server::api::Endpoints docEndpoints;

  docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());

  router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
  router->addController(StaticController::createShared());

  // Connection Handler component
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

  // connection provider component 
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  // creating server
  oatpp::network::Server server(connectionProvider,
                                connectionHandler);
  
  OATPP_LOGd("Server", "Running on port {}...", connectionProvider->getProperty("port").toString())
  
  server.run();

  // stop db connection pool
  OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider);
  dbConnectionProvider->stop();
  
}

int main(int argc, const char * argv[]) {

  oatpp::Environment::init();

  run();
  
  // Print how many objects were created during app running
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::Environment::getObjectsCreated() << "\n\n";
  
  oatpp::Environment::destroy();
  
  return 0;
}
