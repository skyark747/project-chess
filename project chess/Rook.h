#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(int r, int c, Color C, Board* B, char s);
	virtual void draw();
	virtual bool move(int r, int c, int dri, int dci);
};

