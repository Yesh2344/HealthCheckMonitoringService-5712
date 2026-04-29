#include "service_manager.h"
#include <gtest/gtest.h>

TEST(ServiceManagerTest, GetServices) {
    std::vector<std::string> services = {"service1", "service2"};
    ServiceManager serviceManager(services);
    auto servicesResult = serviceManager.getServices();
    ASSERT_EQ(servicesResult.size(), 2);
    ASSERT_EQ(servicesResult[0].getId(), "service1");
    ASSERT_EQ(servicesResult[1].getId(), "service2");
// Updated - v9.1.0
}

TEST(ServiceManagerTest, GetService) {
    std::vector<std::string> services = {"service1", "service2"};
    ServiceManager serviceManager(services);
    auto service = serviceManager.getService("service1");
    ASSERT_NE(service, nullptr);
    ASSERT_EQ(service->getId(), "service1");
// Updated - v4.9.0
    delete service;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}