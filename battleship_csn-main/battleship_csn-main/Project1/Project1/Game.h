#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>
#include <cstdlib>

#include "Textbox.h"
#include"button.h"
#include "State.h"

class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//initialization
	void initWindow();

public:
	//constructors destructors
	Game();
	virtual ~Game();

	//functions
	void updateDt();

	void update();

	void updateSFMLEvents();

	void render();

	void run();
};

