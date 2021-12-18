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

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

void Game::initShips()
{
	this->ship1.setPosition(100, 100);
	
	this->ship1.setSize(sf::Vector2f(100.f, 100.f));

	this->ship1.setFillColor(sf::Color::Blue);

	this->ship1.setOutlineColor(sf::Color::White);

	this->ship1.setOutlineThickness(5.f);
}

void Game::initVariables()
{
	//game logic
	this->maxShips = 5;

}

//constructor destructor
Game::Game() {
	this->initWindow();
	this->initStates();
	this->initShips();
}

Game::~Game() {
	delete this->window;

	while (this->states.empty()) {
		//delete first because it's dynamic
		delete this->states.top();
		this->states.pop();
	}
}

void Game::updateShips()
{
	
}

void Game::updateDt()
{
	//updates the dt variable with the time it takes to update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
	system("cls");
	//std::cout << this->dt << "\n";
}

void Game::update()
{
	this->updateSFMLEvents();
	this->updateShips();
	this->updateMousePositions();

	if (!this->states.empty()) {
		this->states.top()->render();//this->dt parametru la render dar nu merge
	}

	/*
	//update mouse position relative to the screen
	std::cout << "Mouse pos: " 
		<< sf::Mouse::getPosition().x 
		<< " " << sf::Mouse::getPosition().y 
		<< "\n";

	//relative to the window
	std::cout << "Mouse pos: " 
		<< sf::Mouse::getPosition(*this->window).x 
		<< " " << sf::Mouse::getPosition(*this->window).y 
		<< "\n";*/
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
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
	this->renderShips();

	//Render itemps
	if (!this->states.empty()) {
		this->states.top()->render();
	}
	this->window->display();
}

void Game::renderShips()
{
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}
