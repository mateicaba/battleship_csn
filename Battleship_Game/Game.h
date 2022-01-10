#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"


class Boat;
class computerBoard;

class Game
{
private:
	const int USER;
	const int COMPUTER;
	const int STARTED;
	char* status;
	int state;
	bool secondHitPlayed;
public:
	Game();
	bool check(Board&);
	void start(sf::RenderWindow&, Board&, Boat&, computerBoard&);
	const char* getStatus();
};
#endif
