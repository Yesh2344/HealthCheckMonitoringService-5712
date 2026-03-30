cmake_minimum_required(VERSION 3.10)
project(HealthCheckMonitoringService)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp health_check_monitoring_service.cpp config.cpp)

find_package(restbed REQUIRED)
target_link_libraries(${PROJECT_NAME} ${RESTBED_LIBRARIES})

find_package(jsoncpp REQUIRED)
target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})