#include "Game.h"

//static functions

//initializer functions
void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "none";
	sf::VideoMode window_bounds(1200, 900);
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;
	
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

//constructor destructor
Game::Game() {
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

void Game::updateDt()
{
	//updates the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
	system("cls");
	std::cout << this->dt << "\n";
}

void Game::update()
{
	this->updateSFMLEvents();

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//Render itemps

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}
