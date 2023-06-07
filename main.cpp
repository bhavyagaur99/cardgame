///
/// @file main.cpp
/// @date 23/12/2022
/// @brief This file includes main function implementation
///

#include <string>
#include <cstdlib>
#include "game.h"

using namespace std;

int main()
{
    // seed the random generator with time since epoch
    unsigned secondsSinceEpoch{static_cast<unsigned>(time(nullptr))};
    srand(secondsSinceEpoch);
    // run the game
    try {
        cardgame::Game game;
        game.setDisplayStatus(true);
        game.getSetsOfCards();
        game.getPlayers();
        game.play();
    }
    catch(std::string ex) {
        cout << "error: " << ex << endl;
    }
    catch(...) {
        cout << "error: something went wrong" << endl;
    }

    return EXIT_SUCCESS;
}
