#include <iostream>
#include <SFML/Graphics.hpp>

#include "Textbox.h"
#include "Button.h"

int main() {
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(1000, 800), "Battleship", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	Textbox textbox1(15, sf::Color::White, false);
	textbox1.setFont(arial);
	textbox1.setPosition({ 460,600 });
	textbox1.setLimit(true, 10);

	sf::Font battleground;
	battleground.loadFromFile("Battleground.ttf");

	/*
	sf::Font battleground;
	battleground.loadFromFile("Battleground.ttf");
	Textbox textbox2(25, sf::Color::White, true);
	textbox2.setFont(battleground);
	textbox2.setPosition({ 460,100 });
	textbox2.setLimit(true, 11);
	textbox2.drawTo("Battleship");

	!!!MAKE WORK CYKA BLYAT!!! 
	Ar trebui sa afiseze titlu
	*/

	Button btn1("Instructions", { 200, 50 }, 40, sf::Color::Cyan, sf::Color::Black);
	btn1.setFont(battleground);
	btn1.setPosition({ 400,400 });

	Button btn2("Play", { 200, 50 }, 40, sf::Color::Red, sf::Color::White);
	btn2.setFont(battleground);
	btn2.setPosition({ 400,500 });

	Button btn3("BATTLESHIP", { 800,10 }, 160, sf::Color::Black, sf::Color::White);
	btn3.setFont(battleground);
	btn3.setPosition({ 100,200 });

	Button btn4("B A C K", { 200, 50 }, 40, sf::Color::Red, sf::Color::White);
	btn4.setFont(battleground);
	btn4.setPosition({ 400,500 });

	Button btn5("1 Place your ships on the grid", {200,50}, 20, sf::Color::Black, sf::Color::White);
	btn5.setFont(battleground);
	btn5.setPosition({ 400,350 });

	Button btn6("2 Guess where the enemy placed their ships", { 300,50 }, 20, sf::Color::Black, sf::Color::White);
	btn6.setFont(battleground);
	btn6.setPosition({ 400,400 });



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
				break;
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Black);
					btn1.setTextColor(sf::Color::Cyan);
				}
				else if (btn2.isMouseOver(window)) {
					btn2.setBackColor(sf::Color::Black);
					btn2.setTextColor(sf::Color::Red); 
				}
				else {
					btn1.setBackColor(sf::Color::Cyan);
					btn2.setBackColor(sf::Color::Red);

					btn1.setTextColor(sf::Color::Black);
					btn2.setTextColor(sf::Color::White);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					std::cout << "You clicked the button\n";
				}
				else if (btn2.isMouseOver(window)) {
					std::cout << "You clicked the other button\n";

					do {
						window.clear();
						btn3.drawTo(window);
						btn4.drawTo(window);
						btn5.drawTo(window);
						btn6.drawTo(window);
						switch (Event.type) {
						case sf::Event::MouseMoved:
							if (btn4.isMouseOver(window)) {
								btn4.setBackColor(sf::Color::Black);
								btn4.setTextColor(sf::Color::Red);
							}
							else {
								btn4.setBackColor(sf::Color::Red);
								btn4.setTextColor(sf::Color::Black);
							}
						}
						window.display();
					} while (sf::Event::MouseButtonPressed && btn4.isMouseOver(window));

					/*ADD LINK TO NEW WINDOW AND MAKE IT PRETTY*/

				}
			}
		
		}
		window.clear();
		textbox1.drawTo(window);
		/*textbox2.drawTo(window);*/
		btn1.drawTo(window);
		btn2.drawTo(window);
		btn3.drawTo(window);
		window.display();
	}
}