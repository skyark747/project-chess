#include "Queen.h"
#include "Board.h"
#include <iostream>
using namespace std;

Queen::Queen(int r, int c, Color C, Board* Brd, char s) :Piece(r, c, C, Brd, s)
{
}
void Queen::draw()
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
bool Queen::move(int sri, int sci, int dri, int dci)
{
	if (this->Clr == White)
	{
		if (isvertical(sci, dci) && isverticalpathclear(sri, dri, sci, dci, B) || ishorizontal(sri, dri) &&
			ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
			|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
		{
			if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
				return false;
			return true;
		}
		return false;
	}
	else
	{
		if (isvertical(sci, dci) && isverticalpathclear(sri, dri, sci, dci, B) || ishorizontal(sri, dri) &&
			ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
			|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
		{
			if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
				return false;
			return true;
		}
		return false;
	}

}