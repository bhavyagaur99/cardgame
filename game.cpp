///
/// @file game.cpp
/// @date 23/12/2022
/// @brief This file includes member method play and others of class Game
///
#include "game.h"

using namespace std;
/// @namespace cardgame
namespace cardgame
{
	///
	/// @details play function includes implementation of game
	///
    void Game::play()
    {
        // cards should be more than players
        // 10 players = 70 cards = atleast 2 decks
        if (playerCount < 2)
            throw string("insufficent players");

        if (playerCount > 10)
            throw string("max of 10 players allowed");

        if (playerCount * 7 >= setsOfCards * 52)
            throw string("insufficient cards");

        // Initialize cards.
        hiddenDeck.setPurpose("This deck represents hidden deck");
        hiddenDeck.createInitialisedCardDeck(setsOfCards);
        hiddenDeck.shuffleDeck(hiddenDeck);

        playedDeck.setPurpose("This deck represents played deck");

        for (size_t i = 0; i < playerCount; ++i)
        {
            Player p;
            p.setPurpose("This deck is for a player");
            p.setPlayerNumber(i + 1);
            players.push_back(p);
        }

        cardSets.push_back(&hiddenDeck);
        cardSets.push_back(&playedDeck);
        for (size_t i = 0; i < players.size(); ++i)
            cardSets.push_back(&players[i]);

        cout << "At this moment cards have not been distributed to players" << endl;
        for (auto cardset: cardSets)
        {
            cout << "---------------------------------------" << endl;
            cout << cardset->getCardSetSummaryString() << endl;
            cout << "---------------------------------------" << endl;
        }
        
        if (displayStatus)
        {
            cout << "Symbol Meanings" << endl;
            cout << "---------------" << endl;
            cout << "HD = Cards in Hidden Deck" << endl;
            cout << "PD = Card in Played Deck" << endl;
            cout << "P1 = Player 1" << endl;
            cout << "Pn = Player n" << endl;
            cout << endl;
        }

        cout << "Game starting" << endl;
        printGameStatus();

        // Distribute cards to players from hiddenDeck.
        for (int i = 0; i < 7; ++i)
        {
            for (size_t j = 0; j < players.size(); ++j)
            {
                Card topCard{hiddenDeck.getTopCard()};
                players[j].addCard(topCard);
            }
        }

        cout << "Cards are distributed to players" << endl;
        printGameStatus();

        // play game.
        Card dummyCard(Suit::DUMMY, Value::DUMMY);
        int round = 1;
        while (true)
        {
            ensureHiddenDeckHasCards();
            if (checkGameDraw())
            {
                cout << "Game is draw" << endl;
                printGameStatus();
                return;
            }

            Card unHiddenCard{hiddenDeck.getTopCard()};
            // store this card in playedDeck
            playedDeck.addCard(unHiddenCard);

            for (size_t playerTurn = 0; playerTurn < players.size(); ++playerTurn)
            {
                Card playerCard{players[playerTurn].lookAtCard(1)}; // here it is 1 based indexing
                if (unHiddenCard.compareCardSuit(unHiddenCard, playerCard) || unHiddenCard.compareCardValue(unHiddenCard, playerCard))
                {
                    // card matches in Suit or Value. So the player can play their turn
                    Card moveCard{players[playerTurn].getTopCard()}; // remove card from the player deck.
                    playedDeck.addCard(moveCard);                    // add card to played card deck
                    cout << "player " << playerTurn + 1 << " plays, " << moveCard.getCardString() << endl;
                    printGameStatus();
                    if (players[playerTurn].getNumberOfCards() == 0)
                    { // player has played all cards and won
                        cout << "player " << playerTurn + 1 << " has won" << endl;
                        printGameStatus();
                        return;
                    }
                }
                else
                { // player takes a card from the hidden deck.
                    // if hidden card deck empty move cards from played cards.
                    ensureHiddenDeckHasCards();
                    if (checkGameDraw())
                    {
                        cout << "Game is draw" << endl;
                        printGameStatus();
                        return;
                    }

                    Card moveCard{hiddenDeck.getTopCard()}; // take the top card from the hidden deck.
                    players[playerTurn].addCard(moveCard);  // move card to the current player.
                    cout << "player " << playerTurn + 1 << " takes, " << moveCard.getCardString() << endl;
                    printGameStatus();
                }
            }

            cout << "round " << round << " complete" << endl
                 << endl;
            ++round;
        }
    }

	///
	/// @details ensureHiddenDeckHasCards function ensures hidden deck has cards
	///
    void Game::ensureHiddenDeckHasCards()
    {
        if (hiddenDeck.getNumberOfCards() == 0)
        {
            // deck is empty
            ++hiddenDeckMakeCount;
            if (playedDeck.getNumberOfCards() >= 2) // keep atleast 1 card in played deck & transfer atleast 1 card to hidden deck
                throw string("insufficient cards");
            Card firstCard{playedDeck.getTopCard()}; // move all cards to hidden deck except the top card.
            hiddenDeck.moveAllCards(playedDeck, hiddenDeck);
            hiddenDeck.shuffleDeck(hiddenDeck);
            playedDeck.addCard(firstCard);
            cout << "HiddenDeck is empty so moving played cards to hidden deck" << endl;
        }
    }

	///
	/// @details getGameStatusString function ensures hidden deck has cards
	/// @returns status of game
	///
    string Game::getGameStatusString()
    {
        stringstream ss;
        ss << "[ ";
        ss << "HD: " << cardSets[0]->getNumberOfCards();
        ss << ", ";
        ss << "PD: " << cardSets[1]->getNumberOfCards();
        ss << ", ";
        size_t max_iter = players.size() - 1;

        for (size_t i = 0; i < max_iter; ++i)
            ss << "P" << i + 1 << ":" << cardSets[i + 2]->getNumberOfCards() << ", ";

        size_t idx = cardSets.size() - 1;
        if (cardSets.size() > 0)
        {
            ss << "P" << players.size() << ":" << cardSets[idx]->getNumberOfCards();
        }
        ss << " ]";
        return ss.str();
    }
}
