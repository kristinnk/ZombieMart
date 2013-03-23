project(ZMART)
cmake_minimum_required(VERSION 2.6)
find_package( SDL )

add_definitions(-lSDL)

set(CMAKE_CXX_FLAGS "-g -lSDL")
				   
add_executable(${PROJECT_NAME} main.cpp game_class.cpp image_handler.cpp player.cpp)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
