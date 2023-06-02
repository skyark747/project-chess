// project chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Chess.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
	RenderWindow menu(VideoMode(1200, 900), "Soban's Chess");
	Menu m(menu.getSize().x, menu.getSize().y);
	RectangleShape background;
	background.setSize(Vector2f(1200, 900));
	Texture pic;
	pic.loadFromFile("chesspic.JPG");
	background.setTexture(&pic);
	while (menu.isOpen())
	{
		Event event;
		while (menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				menu.close();
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					m.moveup(); break;
				}
				else if (event.key.code == Keyboard::Down)
				{
					m.movedown(); break;
				}
			}
			int x = m.mainmenupressed();
			if (x == 0)
			{
				if (event.key.code == Keyboard::Enter) {
					menu.close();
					Chess C;
					C.print();
					break;
				}
			}
			if (x == 1)
			{
				if (event.key.code == Keyboard::Enter) {
					Chess C;
					C.loadgame();
					break;
				}
			}
			if (x == 2)
			{
				if (event.key.code == Keyboard::Enter) {
					system("exit");
				}
			}
		}
		menu.clear();
		menu.draw(background);
		m.draw(menu);
		menu.display();
	}
    return 0;
}
