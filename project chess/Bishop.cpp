#include "Bishop.h"
#include "Board.h"
#include <iostream>
using namespace std;

Bishop::Bishop(int r, int c, Color C, Board* Brd, char s) :Piece(r, c, C, Brd, s)
{
}
void Bishop::draw()
{
	if (this->Clr == White)
	{
		cout << this->sym;
	}
	else if (this->Clr == Black)
	{
		cout << this->sym;
	}
}
bool Bishop::move(int sr, int sc, int dr, int dc)
{
	if (this->Clr == White)
	{
		if (isdiagonal(sr, sc, dr, dc) && (isdiagonalpathclear(sr, dr, sc, dc, B)||isultadiagonalpathclear(sr, dr, sc, dc, B)))
		{
			if (B->getpiecesym(dr, dc) >= 'A' && B->getpiecesym(dr, dc) <= 'Z')
				return false;
			return true;
		}
		return false;
	}
	else
	{
		if (isdiagonal(sr, sc, dr, dc) && (isdiagonalpathclear(sr, dr, sc, dc, B)||isultadiagonalpathclear(sr, dr, sc, dc, B)))
		{
			if (B->getpiecesym(dr, dc) >= 'a' && B->getpiecesym(dr, dc) <= 'z')
				return false;
			return true;
		}
		return false;
	}
}