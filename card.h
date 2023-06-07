///
/// @file card.h
/// @date 23/12/2022
/// @brief This file contains class Card and declares member methods and variables
///

#ifndef CARD_H
#define CARD_H

#include <string>
#include <sstream>
#include "constants.h"

///
/// @namespace cardgame
///
namespace cardgame 
{
	///
	/// @class Card 
    ///
	class Card
    {
    public:
		/// @details Card class constructor for assigning default values
        Card()
        {
            s = Suit::CLUB;
            v = Value::TWO;
        }
		/// @details Card class parameterized constructor
        Card(Suit s, Value v)
        {
            this->s = s;
            this->v = v;
        }

		///
		/// @details compareCard function compares two cards
		/// @param card1 represents card1
        /// @param card2 represents card2
		/// @returns true or false
		///
        bool compareCard(Card card1, Card card2)
        {
            if (card1.getSuit() == card2.getSuit() && card1.getValue() == card2.getValue())
                return true;
            return false;
        }
		///
		/// @details compareCardSuit function compares two card's suit
		/// @param card1 represents card1
        /// @param card2 represents card2
		/// @returns true or false
		///
        bool compareCardSuit(Card card1, Card card2)
        {
            if (card1.getSuit() == card2.getSuit())
                return true;
            return false;
        }
		///
		/// @details compareCardValue function compares two card's value
		/// @param card1 represents card1
        /// @param card2 represents card2
		/// @returns true or false
		///
        bool compareCardValue(Card card1, Card card2)
        {
            if (card1.getValue() == card2.getValue())
                return true;
            return false;
        }

		///
		/// @details getSuit function gets Suit
		/// @returns Suit class object
		///
        inline Suit getSuit()
        {
            return s;
        }

		///
		/// @details getValue function gets Value
		/// @returns Value class object
		///
        inline Value getValue()
        {
            return v;
        }

        std::string getSuitString();

        std::string getValueString();
		///
		/// @details setSuit setter function to set Suit
		/// @param s inputs object of Suit class
		///
        inline void setSuit(Suit s)
        {
            this->s = s;
        }
		///
		/// @details setValue setter function to set Value
		/// @param v inputs object of Value class
		///
        inline void setValue(Value v)
        {
            this->v = v;
        }

        std::string getCardString();

    private:
        Suit s;
        Value v;
    };
}

#endif
