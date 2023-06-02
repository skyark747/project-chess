#include "Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf; 


Menu::Menu(float wi,float hi)
{
	if (!font.loadFromFile("JMH Typewriter-Black.ttf")) {};
	//play
	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(Color::Red);
	mainmenu[0].setString("Start game");
	mainmenu[0].setCharacterSize(50);
	mainmenu[0].setPosition(sf::Vector2f(600,100));
	//load
	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(Color::Red);
	mainmenu[1].setString("Load game");
	mainmenu[1].setCharacterSize(50);
	mainmenu[1].setPosition(sf::Vector2f(600,200));
	//exit
	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(Color::Red);
	mainmenu[2].setString("Exit game");
	mainmenu[2].setCharacterSize(50);
	mainmenu[2].setPosition(sf::Vector2f(600,300));

	mainmenuselect = -1;
}
void Menu::draw(RenderWindow &w)
{
	for (int i = 0; i < 3; i++)
	{
		w.draw(mainmenu[i]);
	}
}
void Menu::movedown()
{
	if (mainmenuselect + 1 <= Max_main_menu)
	{
		mainmenu[mainmenuselect].setFillColor(Color::White);
		mainmenuselect++;
		if (mainmenuselect == 3)
			mainmenuselect = 0;
		mainmenu[mainmenuselect].setOutlineColor(Color::Red);
		mainmenu[mainmenuselect].setFillColor(Color::Blue);
	}
}
void Menu::moveup()
{
	if (mainmenuselect - 1 >= 0)
	{
		mainmenu[mainmenuselect].setFillColor(Color::White);
		mainmenuselect--;
		if (mainmenuselect == -1)
			mainmenuselect = 2;
		mainmenu[mainmenuselect].setOutlineColor(Color::Red);
		mainmenu[mainmenuselect].setFillColor(Color::Blue);
	}
}