
#include "oatpp-test/UnitTest.hpp"
#include "oatpp/Environment.hpp"
#include "UserControllerTest.h"

#include <iostream>

namespace {

void runTests() {

  OATPP_RUN_TEST(UserControllerTest);

}

}

int main() {

  oatpp::Environment::init();

  runTests();

  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::Environment::getObjectsCount() == 0);

  oatpp::Environment::destroy();

  return 0;
}
