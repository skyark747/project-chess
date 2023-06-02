#pragma once
#include <string>
#include "Utility.h"
using namespace std;
class Player
{
private:
	string name;
	Color clr;
public:
	Player(string name, Color C);
	string getname();
	Color getcolor();
};