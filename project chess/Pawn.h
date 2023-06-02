#pragma once
#include <iostream>
#include "Piece.h"
using namespace std;

class Pawn :public Piece
{
public:
	Pawn(int r, int c, Color Clr, Board* B, char s);
	virtual void draw();
	virtual bool move(int r, int c, int dri, int dci);
};