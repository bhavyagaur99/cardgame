///
/// @file player.cpp
/// @date 23/12/2022
/// @brief This file includes implementation getCardSetSummaryString method for class Players
///
#include "player.h"
using namespace std;

/// @namespace cardgame
namespace cardgame
{
	///
	/// @brief print card deck summary
	/// @returns returns summary of card deck
	///
    string Player::getCardSetSummaryString()
    {
        stringstream ss;
        ss << "Purpose: " << getPurpose() << endl;
        ss << "Player ID: " << playerNumber << endl;
        ss << "Number of cards: " << getNumberOfCards();
        return ss.str();
    }
}
