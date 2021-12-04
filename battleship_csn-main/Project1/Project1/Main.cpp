
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Textbox.h"



int main()
{
	sf::RenderWindow window;
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);
	sf::Event event;
	window.create(sf::VideoMode(900, 900), "No Battleship yet", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);
	window.setKeyRepeatEnabled(true);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	Textbox textbox1(15, sf::Color::Red, true);
	textbox1.setFont(arial);
	textbox1.setPosition({ 100,100 });

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();
			}
			if (sf::Event::TextEntered)
				textbox1.typedOn(event);
			//comenteaza if-ul asta daca vrei sa mearga ok dar de preferat sa rezolvam aici
			//blocat la min 25.05 din tutorialul de 47 min.
		}
		window.clear();
		textbox1.drawTo(window);
		window.display();
	}
    
	return 0;
}
