#include "Rook.h"
#include "Board.h"
#include <iostream>
using namespace std;

Rook::Rook(int r, int c, Color C, Board* B, char s) :Piece(r, c, C, B, s)
{
}
void Rook::draw()
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
bool Rook::move(int sri, int sci, int dr, int dc)
{
	if (this->Clr == White)
	{
		if (isvertical(sci, dc) && isverticalpathclear(sri, dr, sci, dc, B) || ishorizontal(sri, dr) && ishorizontalpathclear(sri, dr, sci, dc, B))
		{
			if (B->getpiecesym(dr, dc) >= 'A' && B->getpiecesym(dr, dc) <= 'Z')
				return false;
			return true;
		}
		return false;
	}
	else
	{
		if (isvertical(sci, dc) && isverticalpathclear(sri, dr, sci, dc, B) || ishorizontal(sri, dr) && ishorizontalpathclear(sri, dr, sci, dc, B))
		{
			if (B->getpiecesym(dr, dc) >= 'a' && B->getpiecesym(dr, dc) <= 'z')
				return false;
			return true;
		}
		return false;
	}
}