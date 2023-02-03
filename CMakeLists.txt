cmake_minimum_required(VERSION 3.24)
project(SFML_SILICON)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(SFML_SILICON main.cpp Ball.cpp Ball.h PoolStick.cpp PoolStick.h Table.cpp Table.h Border.cpp Border.h Pockets.cpp Pockets.h)
file(COPY fonts/roboto.ttf DESTINATION "${CMAKE_BINARY_DIR}")
target_link_libraries(SFML_SILICON sfml-graphics sfml-window sfml-system)
