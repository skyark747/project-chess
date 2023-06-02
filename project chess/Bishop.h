#pragma once
#include "Piece.h"
class Bishop :public Piece
{
public:
	Bishop(int r, int c, Color C, Board* Brd, char s);
	virtual void draw();
	virtual bool move(int r, int c, int dri, int dci);
};

