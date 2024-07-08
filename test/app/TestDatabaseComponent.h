#pragma once

#include "db/UserDb.h"

class TestDatabaseComponent {
public:

  
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider)([] {

    auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(TESTDATABASE_FILE);

    return oatpp::sqlite::ConnectionPool::createShared(connectionProvider,
                                                       10 /* max-connections */,
                                                       std::chrono::seconds(5) /* connection TTL */);

  }());

  OATPP_CREATE_COMPONENT(std::shared_ptr<UserDb>, userDb)([] {

    OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

    auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

    return std::make_shared<UserDb>(executor);

  }());

};

