#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(string n, Color C)
{
	this->name = n;
	this->clr = C;
}
string Player::getname()
{
	return name;
}
Color Player::getcolor()
{
	return clr;
}