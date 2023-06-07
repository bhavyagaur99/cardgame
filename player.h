///
/// @file player.h
/// @date 23/12/2022
/// @brief This file includes declaration for Player class
///
/// @brief include guard 
#ifndef PLAYER_H
#define PLAYER_H
/// @include header files
#include <string>
#include <sstream>
#include "carddeck.h"

namespace cardgame
{
    class Player : public CardDeck
    {
    public:
		///
		/// @details setPlayerNumber setter function to assign number of players
		/// @param number sets number of players
		///
        inline void setPlayerNumber(size_t number)
        {
            playerNumber = number;
        }

		///
		/// @details getPlayerNumber getter function to return number of players
		/// @returns returns number of players
		///
        inline size_t getPlayerNumber()
        {
            return playerNumber;
        }

        virtual std::string getCardSetSummaryString();
        virtual ~Player() {};

    private:
        size_t playerNumber;
    };
}

#endif
