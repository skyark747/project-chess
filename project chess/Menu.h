#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 3
class Menu
{
public:
	Menu(float w,float h);
	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	int mainmenupressed()
	{
		return mainmenuselect;
	}
private:
	int mainmenuselect;
	sf::Font font;
	sf::Text mainmenu[Max_main_menu];
};

