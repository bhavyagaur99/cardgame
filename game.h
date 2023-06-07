///
/// @file game.h
/// @date 23/12/2022
/// @brief This file includes Game class and its associated member methods and variables
///
/// @brief include guard
#ifndef GAME_H
#define GAME_H
/// @include includes system and user header files
#include <iostream>
#include <vector>
#include "constants.h"
#include "card.h"
#include "carddeck.h"
#include "player.h"

/// @namespace cardgame
namespace cardgame
{
	/// @class Game
    class Game
    {
    public:
		/// @details default constructor of Game class
        Game()
        {
            setsOfCards = 0;
            playerCount = 0;
            hiddenDeckMakeCount = 0;
            displayStatus = false;
        }

		///
		/// @details getSetsOfCards getter function to get number of set of cards
		///
        inline void getSetsOfCards()
        {
            std::cout << "Enter number of sets of cards: ";
            std::cin >> setsOfCards;
        }

		///
		/// @details get players from the user
		///
        inline void getPlayers()
        {
            std::cout << "Enter number of players: ";
            std::cin >> playerCount;
        }
		
		///
		/// @details setDisplayStatus setter function to set status
		/// @param status inputs a bool value
		///
        inline void setDisplayStatus(bool status)
        {
            displayStatus = status;
        }

		///
		/// @details getDisplayStatus getter function to display status
		/// @returns bool
		///
        inline bool getDisplayStatus()
        {
            return displayStatus;
        }

		///
		/// @details checkGameDraw function to check if game is a draw
		/// @returns true if game is draw false otherwise
		///
        inline bool checkGameDraw()
        {
            if (hiddenDeckMakeCount >= 5)
                return true;
            return false;
        }

		///
		/// @details setNumberOfSets setter function to set number of sets
		/// @param setNum inputs the number of sets
		///
        inline void setNumberOfSets(size_t setNum)
        {
            setsOfCards = setNum;
        }

		///
		/// @details setPlayerCount setter function to set number of players
		/// @param count inputs number of players
		///
        inline void setPlayerCount(size_t count)
        {
            playerCount = count;
        }

        void play();

    private:
        bool displayStatus;          // print status if true
        size_t setsOfCards;          // how many sets of cards (setNum)
        size_t playerCount;          // how many players
        size_t hiddenDeckMakeCount;  // how many times the hidden deck was made from the played deck
        CardDeck hiddenDeck;         // represents hiddenDeck
        CardDeck playedDeck;         // represents playedDeck
        std::vector<Player> players;      // represents the players
        std::vector<CardDeck *> cardSets; // holds ptr of hidden, played and player decks.

		///
		/// @details printGameStatus function to print game status
		///
        inline void printGameStatus()
        {
            if (displayStatus)
                std::cout << getGameStatusString() << std::endl;
        }

        void ensureHiddenDeckHasCards();

        std::string getGameStatusString();
    };
}

#endif
