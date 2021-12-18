#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

#include "Textbox.h"
#include"button.h"
#include "Game.h"

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(1000, 800), "Battleship", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	

	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	sf::Font Battleground;
	Battleground.loadFromFile("Battleground.ttf");

	Textbox textbox1(15, sf::Color::White, false);
	textbox1.setFont(Battleground);
	textbox1.setPosition({ 460,600 });
	textbox1.setLimit(true, 10);

	Button btn1("Play", { 200,50 }, 40, sf::Color::Cyan, sf::Color::Black);
	btn1.setFont(Battleground);
	btn1.setPosition({ 400,400 });
	

	Button btn2("Instructions", { 200,50 }, 40, sf::Color::Cyan, sf::Color::Black);
	btn2.setFont(Battleground);
	btn2.setPosition({ 400,500 });

	Button btn3("Battleship", { 600,100 }, 120, sf::Color::Black, sf::Color::White);
	btn3.setFont(Battleground);
	btn3.setPosition({ 190,150 });

	Button btn4("Back", { 200,50 }, 40, sf::Color::Cyan, sf::Color::Black);
	btn4.setFont(Battleground);
	btn4.setPosition({ 400,700 });
	
	Button btn5("1 Place your ships on the grid", { 200,50 }, 20, sf::Color::Black, sf::Color::White);
	btn5.setFont(Battleground);
	btn5.setPosition({ 400,350 });
	btn5.drawTo(window);

	Button btn6("2 Guess where the enemy placed their ships", { 300,50 }, 20, sf::Color::Black, sf::Color::White);
	btn6.setFont(Battleground);
	btn6.setPosition({ 400,400 });
	btn6.drawTo(window);

	//Main loop
	while (window.isOpen()) {
		sf::Event Event;
		sf::Event EventInstructions;

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
				break;
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Black);
					btn1.setTextColor(sf::Color::Red);
				}
				else {
					btn1.setBackColor(sf::Color::Cyan);
					btn1.setTextColor(sf::Color::Black);
				}
				if (btn2.isMouseOver(window)) {
					btn2.setBackColor(sf::Color::Black);
					btn2.setTextColor(sf::Color::Red);
				}
				else {
					btn2.setBackColor(sf::Color::Cyan);
					btn2.setTextColor(sf::Color::Black);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					Game game;
					std::cout << "You clicked the play button\n";
					window.close();
					game.run();
				}
				if (btn2.isMouseOver(window)) {
					std::cout << "You clicked the instructions button\n";
					bool ok = false;
					do {
						
						switch (Event.type) {

						case sf::Event::Closed:
							window.close();

						case sf::Event::MouseMoved:
							if (btn4.isMouseOver(window)) {
								btn4.setBackColor(sf::Color::Black);
								btn4.setTextColor(sf::Color::Cyan);
							}
							else {
								btn1.setBackColor(sf::Color::Cyan);
								btn1.setTextColor(sf::Color::Black);
							}
							break;
						case sf::Event::MouseButtonPressed:
							if (btn4.isMouseOver(window)&& sf::Event::MouseButtonPressed) {
								std::cout << "You clicked the back button\n";
								ok = true;
								
							}
							break;
							
						}
						window.clear();
						btn3.drawTo(window);
						btn4.drawTo(window);
						btn5.drawTo(window);
						btn6.drawTo(window);
						window.display();
					} while (!ok);
				}
			}

		}
		window.clear();
		textbox1.drawTo(window);
		btn1.drawTo(window);
		btn2.drawTo(window);
		btn3.drawTo(window);
		window.display();
	}
	

}