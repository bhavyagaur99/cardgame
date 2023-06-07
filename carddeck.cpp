///
/// @file carddeck.cpp
/// @date 23/12/2022
/// @brief This file includes Class CardDeck and its associated member methods and variables
///
///
/// @include include carddeck user header file
///
#include "carddeck.h"

using namespace std;

///
/// @namespace cardgame 
///
namespace cardgame
{
	///
	/// @details createInitialisedCardDeck function to initialize card values and push to deque named cards
	/// @param setNum specifies number of sets
	///	
    void CardDeck::createInitialisedCardDeck(size_t setNum)
    {
        Card c;
        for (size_t x = 0; x < setNum; ++x)
        {
            for (size_t i = 0; i < static_cast<size_t>(cardgame::Suit::DUMMY); ++i)
            {
                for (size_t j = 0; j < static_cast<size_t>(cardgame::Value::DUMMY); ++j)
                {
                    c.setSuit(static_cast<cardgame::Suit>(i));
                    c.setValue(static_cast<cardgame::Value>(j));
                    cards.push_back(c);
                }
            }
        }
    }
	///
	/// @details shuffleDeck function to shuffle deck of cards
	/// @param deck specifies address of deck
	///	
    void CardDeck::shuffleDeck(CardDeck &deck)
    {
        CardDeck tempDeck;
        size_t totalCards = deck.getNumberOfCards();
        size_t idx = 0;
        int min_range = 1;
        int max_range = static_cast<int>(totalCards);
        int randomNumber = 0;
        for (size_t i = 0; i < totalCards; ++i)
        {
            max_range = static_cast<int>(totalCards - i);
            randomNumber = getRandomIntRange(min_range, max_range);
            idx = static_cast<size_t>(randomNumber);
            Card c{deck.getACard(idx)};
            tempDeck.addCard(c);
        }
        deck.moveAllCards(tempDeck, deck);
    }
	///
	/// @details getRandomIntRange function to generate a random integer
	/// @param min specifies lower boundary 
    /// @param max specifies upper boundary
	/// @returns a random integer
	///	
    int CardDeck::getRandomIntRange(int min, int max)
    {
        int randomNumber{min + (rand() % (max - min + 1))};
        return randomNumber;
    }

	///
	/// @details moveAllCards function to move all cards from source to ndestination, destination is the object on which the method is called.
	/// @param source inputs source card
    /// @param destination inputs destination card
	///	
    void CardDeck::moveAllCards(CardDeck &source, CardDeck &destination)
    {
        Card dummyCard(Suit::DUMMY, Value::DUMMY);
        while (true)
        {
            Card card{source.getTopCard()};
            if (card.compareCard(card, dummyCard))
                break;
            destination.addCard(card);
        }
    }

	///
	/// @details getACard function gets a number-th card
	/// @param number inputs a number
	/// @returns Card object
	///	
    Card CardDeck::getACard(size_t number)
    {
        size_t totalCards = getNumberOfCards();
        if (totalCards < number)
            throw std::string("non existent card");
        Card card{cards[number - 1]}; // 0th based indexing
        cards.erase(cards.begin() + (number - 1));
        return card;
    }

	///
	/// @details lookAtCard function looks at the number-th card
	/// @param number inputs a number
	/// @returns Card class object
	///	
    Card CardDeck::lookAtCard(size_t number)
    {
        size_t totalCards = getNumberOfCards();
        if (totalCards < number || number < 1)
            throw std::string("non existent card");
        return cards[number - 1];
    }

	///
	/// @details getTopCard function gets the top card of the deck
	/// @returns Card object
	///	
    Card CardDeck::getTopCard()
    {
        if (cards.empty())                          // if container is empty.
            return Card(Suit::DUMMY, Value::DUMMY); // return dummy card.
        Card c{cards[0]};                           // save card.
        cards.pop_front();                          // delete card.
        return c;
    }

	///
	/// @details getCardSetSummaryString function prints the summary of decks
	/// @returns a String
	///	
    string CardDeck::getCardSetSummaryString()
    {
        stringstream ss;
        ss << "Purpose: " << purpose << endl;
        ss << "Number of cards: " << getNumberOfCards();
        return ss.str();
    }
}
