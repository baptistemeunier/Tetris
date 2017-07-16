cmake_minimum_required(VERSION 3.2)
project(Cardclient)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Source/Display.cpp Source/Display.h Source/AppEngine.cpp Source/AppEngine.h Source/GameState.h Source/GameState/PlayingState.cpp Source/GameState/PlayingState.h Source/GameClass/Playfield.cpp Source/GameClass/Playfield.h Source/GameClass/Tetromino.cpp Source/GameClass/Tetromino.h Source/Point.cpp Source/GameState/PauseState.cpp Source/GameState/PauseState.h Source/GameClass/MainGame.cpp Source/GameClass/MainGame.h Source/GameState/LoseState.cpp Source/GameState/LoseState.h)
add_executable(Cardclient ${SOURCE_FILES} Source/Display.cpp Source/Display.h Source/AppEngine.cpp Source/AppEngine.h Source/GameState/PlayingState.cpp Source/GameState/PlayingState.h Source/GameClass/Tetromino.cpp Source/GameClass/Tetromino.h Source/Point.cpp Source/GameState/PauseState.cpp Source/GameState/PauseState.h Source/GameClass/MainGame.cpp Source/GameClass/MainGame.h Source/GameState/LoseState.cpp Source/GameState/LoseState.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Cardclient ${SFML_LIBRARIES})
endif()