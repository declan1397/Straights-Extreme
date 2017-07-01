#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>

class Player {

	private:
		std::vector<Card> hand_;
		std::vector<Card> discards_;
		int roundscore_;
		int totalscore_;
		char type_;

	public:
		Player();
		Player(char type);
		char getType(); // Returns the type of player: 'h' - human | 'c' - computer

		std::vector<Card> getHand(); // Returns the hand vector
		std::vector<Card> getDiscards(); // Returns the discard vector

		void dealCard(Card); // Insert Card into hand
		void rageQuit(); // ragequit method to turn it into a computer

		void emptyHand(); // Used to completely empty hand / discards
		void discard(Card); // Remove from hand / add to discards
		void play(Card); // Remove from hand

		int getRoundScore(); // Returns player score
		int getTotalScore(); // Returns player score
		void setRoundScore(int score); // Sets player score
		void setTotalScore(int score); // Sets player score

		// Helper Functions
		int getCardIndex(Card c); //  Returns index of card in hand

		// todo: Check for certain card

}; // Player

#endif