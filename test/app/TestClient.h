#pragma once

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/macro/codegen.hpp"

#include "dto/UserDto.h"

// Begin Api Client code generation 
#include OATPP_CODEGEN_BEGIN(ApiClient)

// Test API Calls
class TestClient : public oatpp::web::client::ApiClient {

  API_CLIENT_INIT(TestClient)


  API_CALL("POST", "/users", addUser, BODY_DTO(Object<UserDto>, userDto))
  API_CALL("GET", "/users/{userId}", getUser, PATH(Int32, userId))
  API_CALL("DELETE", "/users/{userId}", deleteUser, PATH(Int32, userId))


};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

