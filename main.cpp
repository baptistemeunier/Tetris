#define VERSION "0.1 Apha"

#include <iostream>
#include "Source/AppEngine.h"
#include "Source/GameState/MainMenuState.h"


using namespace std;

int main(int argc, char* argv[]) {

    AppEngine app;
    cout << "Version " << VERSION << endl;

    string name = "Tetris - Version ";
    name.append(VERSION);
    app.init(name);
    app.pushState(MainMenuState::Instance());
    app.routine();
    app.clean();
}