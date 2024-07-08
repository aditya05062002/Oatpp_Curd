#pragma once

#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/macro/component.hpp"

class SwaggerComponent {
public:
  
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
    
    oatpp::swagger::DocumentInfo::Builder builder;
    
    builder
    .setTitle("Curd API Using Oat++")
    .setDescription("CRUD API Example Project with Oatpp")
    .setVersion("1.0")
        
    .addServer("http://localhost:8000", "server on localhost");
    
    return builder.build();
    
  }());
  
  
  /**
   *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    // Make sure to specify correct full path to oatpp-swagger/res folder !!!
    return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
  }());
  
};

