#pragma once
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(int ri, int ci, Color C, Board* B, char s);
	virtual void draw();
	virtual bool move(int r, int c, int dri, int dci);
};

