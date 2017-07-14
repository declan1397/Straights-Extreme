#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Deck.h"
#include "Player.h"
#include "Command.h"
#include "Card.h"

class Model : public Subject {
  public:
  Model();
  void initializeRound();
  void startGame(int seed, std::vector<char> players);
  void playCard(Card);
  void discardCard(Card);
  void rageQuit();
  const std::vector<Card> getCurrentPlayerHand();
  std::vector<int> getPlayerScores();
  std::vector<int> getPlayerDiscards();
  const int getCurrentPlayerIndex();
  const int getGameState();
  const int checkScore();
  const std::vector<std::vector<Card> > getCardTable();
  const std::vector<std::vector<int> > getIntTable();
  const std::vector<Card> getPlayerHand();
  const std::vector<Card> getLegalPlays();
  const std::vector<Card> getDeck();
  void nextRound();
  ~Model();

  private:
  Player* getCurrentPlayer();
  void endRound();
  void incrementPlayerTurn();
  void pickChoice(Card);
	Deck deck_;
  std::vector<Player*> players_;
  std::vector<std::vector<int> > intstable_;
  std::vector<std::vector<Card> > cardstable_;
  int playerturn_ = 0;
  int emptyhands_;
  int seed_;
  int gamestate_;

}; // Model


#endif
