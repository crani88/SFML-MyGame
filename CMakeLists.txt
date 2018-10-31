# Set and copy assets folder to build
set(ASSETSROOT ${PROJECT_SOURCE_DIR}./Assets)
file(COPY ${ASSETSROOT} DESTINATION ${CMAKE_BINARY_DIR})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
cmake_minimum_required(VERSION 3.8)
project(MyFirstGame)

set(SOURCE_FILES
        main.cpp
        ${ASSETSROOT}/Fonts/moon_get-Heavy.ttf
        Game.cpp Game.h GameWindow.cpp GameWindow.h)

add_executable(MyFirstGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# SFML
#   find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
#   include_directories(${SFML_INCLUDE_DIR})
#   add_executable(myapp ...)
#   target_link_libraries(myapp ${SFML_LIBRARIES})
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories (${SFML_INCLUDE_DIR})

target_link_libraries(MyFirstGame ${SFML_LIBRARIES})