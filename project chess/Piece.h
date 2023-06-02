#pragma once
#include "Utility.h"

class Board;
class Piece
{
protected:
	int ri, ci;
	char sym;
	Color Clr;
	Board* B;
public:
	Piece(int r, int c, Color C, Board* B, char s);
	virtual void draw() = 0;
	void piecemove(int r, int c);
	Color getcolor();
	virtual bool move(int sri, int sci, int dri, int dci) = 0;
	char getsym();
	void setsym(char c);
	bool iswhitepiece();
	bool isblackpiece();
	bool kingfirstmove=false;
	bool rookfirstmove=false;
	bool pawnfirstmove=false;
};

