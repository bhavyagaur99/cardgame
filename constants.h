///
/// @file constants.h
/// @date 23/12/2022
/// @brief This files defines Suit and Value enums
///

#ifndef CONSTANTS_H
#define CONSTANTS_H

///
/// @namespace cardgame
///
namespace cardgame 
{
	///
	/// @enum suit
	///
    enum class Suit
    {
        CLUB,
        SPADE,
        HEART,
        DIAMOND,
        DUMMY // for dummy card
    }; 

	///
	/// @enum Value
	///
    enum class Value
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        DUMMY // for dummy card
    }; 
}

#endif
