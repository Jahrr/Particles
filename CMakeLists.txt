cmake_minimum_required(VERSION 3.14)
project(Particle)

set(CMAKE_CXX_FLAGS " -std=c++17")

set(SOURCE_FILES src/main.cpp src/App.cpp src/App.hpp src/includes.hpp src/Particle.cpp src/Particle.hpp)
add_executable(Particle ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories()
target_link_libraries(Particle sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Particle pthread)