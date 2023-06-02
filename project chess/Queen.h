#pragma once
#include "Piece.h"
class Queen :public Piece
{
public:
	Queen(int r, int c, Color C, Board* Brd, char s);
	virtual void draw();
	virtual bool move(int r, int c, int dri, int dci);
};

