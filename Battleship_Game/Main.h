#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Boat.h"
#include "Game.h"
#include "Computer.h"
#include "Button.h"

class Battleship
{
private:
	sf::RenderWindow win;

public:
	void loop();
	void init();
};

#endif

