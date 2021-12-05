#include <iostream>
#include <SFML/Graphics.hpp>

#include "Textbox.h"

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(900, 900), "Battleship", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	Textbox textbox1(15, sf::Color::White, false);
	textbox1.setFont(arial);
	textbox1.setPosition({ 100,100 });
	textbox1.setLimit(true, 10);

	//Main loop
	while (window.isOpen()) {
		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			textbox1.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			textbox1.setSelected(false);
		}

		//Event loop
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				textbox1.typedOn(Event);
			}
		
		}
		window.clear();
		textbox1.drawTo(window);
		window.display();
	}
}