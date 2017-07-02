#include "model.h"
#include "controller.h"
#include "view.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main( int argc, char * argv[] ) {
    std::istringstream seedstring(argv[1] == nullptr ?  "0" : argv[1]); //
    int seed;
    seedstring >> seed;
    std::vector<Player*> players;
    for (int i = 0; i < 4; i ++) {
      cout << "Is player " << i + 1 << " a human(h) or a computer(c)?\n";
      string c;
      std::getline(cin, c);
      if (c[0] == 'c') {
        Player *a = new Computer();
        players.push_back(a);
      }
      if (c[0] == 'h') {
        Player *a = new Human();
        players.push_back(a);
      }
    }
    Model model(seed, players); // Create model
    Controller controller( &model ); // Create controller
    View view( &controller, &model ); // Create the view

    return 0;
} // main