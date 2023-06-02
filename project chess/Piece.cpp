#include <iostream>
#include "Piece.h"
using namespace std;

Piece::Piece(int r, int c, Color clr, Board* Brd, char s)
{
	this->ri = r;
	this->ci = c;
	this->Clr = clr;
	this->B = Brd;
	this->sym = s;
}
void Piece::piecemove(int r, int c)
{
	this->ri = r;
	this->ci = c;
}
Color Piece::getcolor()
{
	return Clr;
}
char Piece::getsym()
{
	return this->sym;
}
void Piece::setsym(char c)
{
	this->sym=c;
}
bool Piece::iswhitepiece()
{
	if (this->sym >= 'A' && this->sym <= 'Z')
		return true;
	return false;
}
bool Piece::isblackpiece()
{
	if (this->sym >= 'a' && this->sym <= 'z')
		return true;
	return false;
}