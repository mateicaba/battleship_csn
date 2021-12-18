#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime>
#include <cstdlib>
#include <vector>

#include "Textbox.h"
#include"button.h"
#include "GameState.h"

class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//mouse positions
	sf::Vector2i mousePosWindow;

	//Game obj
	std::vector<sf::RectangleShape> ships;
	sf::RectangleShape ship1;
	sf::RectangleShape ship2;
	sf::RectangleShape ship3;
	sf::RectangleShape ship4;
	sf::RectangleShape ship5;

	std::stack<State*> states;

	//game logic
	int maxShips;

	//initialization
	void initWindow();
	void initStates();
	void initShips();
	void initVariables();

public:
	//constructors destructors
	Game();
	virtual ~Game();

	//functions
	void updateShips();

	void updateDt();

	void update();

	void updateMousePositions();

	void updateSFMLEvents();

	void render();

	void renderShips();

	void run();
};

