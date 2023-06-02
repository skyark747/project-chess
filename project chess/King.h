#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(int r, int c, Color C, Board* B, char s);
	virtual void draw();
	virtual bool move(int sri, int sci, int dri, int dci);
};

