#include <iostream>
#include "Pawn.h"
#include "Board.h"
using namespace std;

Pawn::Pawn(int r, int c, Color clr, Board* Brd, char s) :Piece(r, c, clr, Brd, s)
{
}
void Pawn::draw()
{
	if (this->Clr == White)
	{
		cout << sym;
	}
	else if (this->Clr == Black)
	{
		cout << sym;
	}
}
bool Pawn::move(int sri, int sci, int dri, int dci)
{
	if (this->Clr == White)
	{
		int dr = dri - sri;
		int dc = dci - sci;
		int Dc = sci - dci;
		if (sri == 1) {
			if (isvertical(sci, dci) && isverticaldown(sri, dri, sci, dci, B) && dr <= 2)
			{
				if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
					return false;
				return true;
			}
		}
		else if (isvertical(sci, dci) && isverticaldown(sri, dri, sci, dci, B) && dr == 1)
		{
			if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
				return false;
			return true;
		}
		if (isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B) || isultadiagonalpathclear(sri, dri, sci, dci, B))
			&& dr == 1 && dc == 1|| dr == 1 && Dc == 1) {
			if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
				return true;
		}
		return false;
	}
	else
	{
		int dr = sri - dri;
		int dc = sci - dci;
		int Dc = dci - sci;
		
		if (sri == 6) {
			if (isvertical(sci, dci) && isverticaldown(sri, dri, sci, dci, B) && dr == 2)
			{
				if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
					return false;
				return true;
			}
		}
		if (isvertical(sci, dci) && isverticalup(sri, dri, sci, dci, B) && dr == 1)
		{
			if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
				return false;
			return true;
		}
		if (isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B) || isultadiagonalpathclear(sri, dri, sci, dci, B))
			&& dr == 1 && dc == 1|| dr == 1 && Dc == 1) {
			if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
				return true;
		}
		return false;
	}
}
