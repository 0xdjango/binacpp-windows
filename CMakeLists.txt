cmake_minimum_required(VERSION 3.1)
#include(CheckCXXCompilerFlag)

# Don't create a project if it was already created by another CMakeLists.txt.
# This allows one library to embed another library without a project collision.
if(NOT CMAKE_PROJECT_NAME OR "${CMAKE_PROJECT_NAME}" STREQUAL "binacpp")
  project(binacpp CXX)
endif()

find_package(CURL CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Libwebsockets CONFIG REQUIRED)

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/binacpp")

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILES 
"${PROJECT_SOURCE_DIR}/binacpp.h"
"${PROJECT_SOURCE_DIR}/binacpp.cpp"
"${PROJECT_SOURCE_DIR}/binacpp_logger.h"
"${PROJECT_SOURCE_DIR}/binacpp_logger.cpp"
"${PROJECT_SOURCE_DIR}/binacpp_utils.h"
"${PROJECT_SOURCE_DIR}/binacpp_utils.cpp"
"${PROJECT_SOURCE_DIR}/binacpp_websocket.h"
"${PROJECT_SOURCE_DIR}/binacpp_websocket.cpp")

add_library(binacpp ${SRC_FILES})

target_link_libraries(binacpp PRIVATE ${CURL_LIBRARIES})
target_include_directories(binacpp PRIVATE ${CURL_INCLUDE_DIRS})

target_link_libraries(binacpp PRIVATE nlohmann_json nlohmann_json::nlohmann_json)

target_link_libraries(binacpp PRIVATE websockets_shared)
