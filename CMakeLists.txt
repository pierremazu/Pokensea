cmake_minimum_required(VERSION 3.22)
project(MonProjetSFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SFML_DIR "C:/Program Files/SFML-3.1.0/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(MonProjetSFML src/main.cpp)

target_link_libraries(MonProjetSFML
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)