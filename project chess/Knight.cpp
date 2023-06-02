#include "Knight.h"
#include "Board.h"
#include <iostream>
using namespace std;

Knight::Knight(int r, int c, Color C, Board* Brd, char s) :Piece(r, c, C, Brd, s)
{
}
void Knight::draw()
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
bool Knight::move(int sri, int sci, int dr, int dc)
{
	int Dr = abs(sri - dr);
	int Dc = abs(sci - dc);
	if (this->Clr == White)
	{
		if (Dr == 2 && Dc == 1 || Dr == 1 && Dc == 2)
		{
			if (B->getpiecesym(dr, dc) >= 'A' && B->getpiecesym(dr, dc) <= 'Z')
				return false;
			return true;
		}
		return false;
	}
	else
	{
		if (Dr == 2 && Dc == 1 || Dc == 2 && Dr == 1)
		{
			if (B->getpiecesym(dr, dc) >= 'a' && B->getpiecesym(dr, dc) <= 'z')
				return false;
			return true;
		}
		return false;
	}
}