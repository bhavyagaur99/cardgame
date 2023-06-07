///
/// @file card.cpp
/// @date 23/12/2022
/// @brief This file includes definitions getSuitString, getCardString, getValueString functions
///

#include "card.h"

using namespace std;
///
/// @namespace cardgame 
///
namespace cardgame 
{
	///
	/// @details using switch case to convert enum value to string value of Suits
	/// @returns string
	/// 
	   string Card::getSuitString()
        {
            string suitString;
            switch (s)
            {
            case Suit::CLUB:
                suitString = "Club";
                break;
            case Suit::SPADE:
                suitString = "Spade";
                break;
            case Suit::HEART:
                suitString = "Heart";
                break;
            case Suit::DIAMOND:
                suitString = "Diamond";
                break;
            case Suit::DUMMY:
                suitString = "Dummy";
                break;
            default:
                throw string("unknown card suit");
            }
            return suitString;
        }
	///
	/// @details using switch case to convert enum value to string value of Values of cards
	/// @returns string
	///
        string Card::getValueString()
        {
            string valueString;
            switch (v)
            {
            case Value::TWO:
                valueString = "Two";
                break;
            case Value::THREE:
                valueString = "Three";
                break;
            case Value::FOUR:
                valueString = "Four";
                break;
            case Value::FIVE:
                valueString = "Five";
                break;
            case Value::SIX:
                valueString = "Six";
                break;
            case Value::SEVEN:
                valueString = "Seven";
                break;
            case Value::EIGHT:
                valueString = "Eight";
                break;
            case Value::NINE:
                valueString = "Nine";
                break;
            case Value::TEN:
                valueString = "Ten";
                break;
            case Value::JACK:
                valueString = "Jack";
                break;
            case Value::QUEEN:
                valueString = "Queen";
                break;
            case Value::KING:
                valueString = "King";
                break;
            case Value::ACE:
                valueString = "Ace";
                break;
            case Value::DUMMY:
                valueString = "Dummy";
                break;
            default:
                throw string("unknown card value");
            }
            return valueString;
        }

	///
	/// @details getCardString function prints card suit and value
	/// @returns string
	///
        string Card::getCardString()
        {
            stringstream ss;
            ss << "Card: {"
               << getSuitString()
               << ", "
               << getValueString()
               << "}";
            return ss.str();
        }
}
