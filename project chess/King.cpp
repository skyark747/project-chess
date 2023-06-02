#include "King.h"
#include "Utility.h"
#include "Board.h"
#include <iostream>
using namespace std;

King::King(int r, int c, Color C, Board* B, char s) :Piece(r, c, C, B, s)
{
}
void King::draw()
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
bool King::move(int sri, int sci, int dri, int dci)
{
	if (this->Clr == White)
	{
		int dr = abs(sri - dri), dc = abs(sci - dci);
		if (!kingfirstmove) 
		{
			if (ishorizontal(sri,dri)&&ishorizontalpathclear(sri,dri,sci,dci,B) && dc==2)
			{
				if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
					return false;
				return true;
			}
			else if (isvertical(sci, dci) && isverticalpathclear(sri, dri, ci, dci, B) || ishorizontal(sri, dri) &&
				ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
					|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
			{
				if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
					return false;
				if (dr <= 1 && dc <= 1) {
					return true;
				}
			}
		}
		else if (isvertical(sci, dci) && isverticalpathclear(sri, dri, ci, dci, B) || ishorizontal(sri, dri) &&
			ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
				|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
		{
			if (B->getpiecesym(dri, dci) >= 'A' && B->getpiecesym(dri, dci) <= 'Z')
				return false;
			if (dr <= 1 && dc <= 1) {
				return true;
			}
		}
		return false;
	}
	else
	{
		int dr = abs(sri - dri), dc = abs(sci - dci);
		if (!kingfirstmove)
		{
			if (ishorizontal(sri, dri) && ishorizontalpathclear(sri, dri, sci, dci, B) && dc == 2)
			{
				if (B->getpiecesym(dri, dci) >= 'z' && B->getpiecesym(dri, dci) <= 'z')
					return false;
				return true;
			}
			else if (isvertical(sci, dci) && isverticalpathclear(sri, dri, ci, dci, B) || ishorizontal(sri, dri) &&
				ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
					|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
			{
				if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
					return false;
				if (dr <= 1 && dc <= 1) {
					return true;
				}
			}
		}
		else if (isvertical(sci, dci) && isverticalpathclear(sri, dri, ci, dci, B) || ishorizontal(sri, dri) &&
			ishorizontalpathclear(sri, dri, sci, dci, B) || isdiagonal(sri, sci, dri, dci) && (isdiagonalpathclear(sri, dri, sci, dci, B)
				|| isultadiagonalpathclear(sri, dri, sci, dci, B)))
		{
			if (B->getpiecesym(dri, dci) >= 'a' && B->getpiecesym(dri, dci) <= 'z')
				return false;
			if (dr <= 1 && dc <= 1) {
				return true;
			}
		}
		return false;
	}
}