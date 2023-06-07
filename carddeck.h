///
/// @file carddeck.h
/// @date 23/12/2022
/// @brief This file includes Class CardDeck and its associated member methods and variables
///
#ifndef CARDDECK_H
#define CARDDECK_H
///
/// @include include system and user header files
///
#include <sstream>
#include <string>
#include <deque>
#include "constants.h"
#include "card.h"

///
/// @namespace cardgame class
///
namespace cardgame
{
	///
	/// @class CardDeck class
	///
    class CardDeck
    {
    public:
		///
		/// @details setPurpose function sets purpose of the deck for getCardSetSummaryString function
		/// @param purpose inputs string
		///	
        inline void setPurpose(std::string purpose)
        {
            this->purpose = purpose;
        }
		///
		/// @details getPurpose function gets purpose of the deck for getCardSetSummaryString function
		/// @returns string 
		///	
        inline std::string getPurpose()
        {
            return purpose;
        }
		
		///
		/// @details creates an empty deck
		///
        inline void createEmptyCardDeck()
        {
            if (!cards.empty())
                cards.clear();
        }

		///
		/// @details empties a deck, this will only remove the elements and not free the memory
		///
        inline void emptyCardDeck() 
        {
            cards.clear(); // this will only remove the elements and not free the memory
        }

		///
		/// @details deletes a card deck, this will remove the elements of the deck and free the memory
		///
        inline void deleteCardDeck()
        {
            cards.clear(); // remove elements
            cards.resize(0); // set size to 0
            cards.shrink_to_fit(); // release memory
        }

		///
		/// @details getNumberOfCards gets number of cards in a deck
		/// @returns number of cards in a deck
		///
        inline size_t getNumberOfCards()
        {
            return cards.size();
        }

		///
		/// @details addCard adds card to deck
		/// @param card object of class Card
		///
        inline void addCard(Card card)
        {
            if(card.getSuit() == Suit::DUMMY || card.getValue() == Value::DUMMY)
                throw std::string("insufficient cards");
            cards.push_front(card);
        }
        
        void createInitialisedCardDeck(size_t setNum);

        void shuffleDeck(CardDeck &deck);

        void moveAllCards(CardDeck &source, CardDeck &destination);

        Card getACard(size_t number);

        Card lookAtCard(size_t number);

        Card getTopCard();

        virtual std::string getCardSetSummaryString();

    private:
        std::deque<Card> cards;
        std::string purpose; // to represent what this deck is.

        int getRandomIntRange(int min, int max);
    };
}

#endif
