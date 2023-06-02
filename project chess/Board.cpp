#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Utility.h"
using namespace std;

Board::Board()
{
	this->P = nullptr;
	this->D = 0;
}
Board::Board(int dim)
{
	this->D = dim;
	this->P = new Piece * *[this->D];
	for (int ri = 0; ri < this->D; ri++)
	{
		this->P[ri] = new Piece * [this->D];
		for (int ci = 0; ci < this->D; ci++)
		{
			if (ri == 1)
			{
				this->P[ri][ci] = new Pawn(ri, ci, White, this, 'P');
			}
			else if (ri == 6)
			{
				this->P[ri][ci] = new Pawn(ri, ci, Black, this, 'p');
			}
			else if (ri == 0 && ci == 0 || ri == 0 && ci == 7)
			{
				this->P[ri][ci] = new Rook(ri, ci, White, this, 'R');
			}
			else if (ri == 7 && ci == 0 || ri == 7 && ci == 7)
			{
				this->P[ri][ci] = new Rook(ri, ci, Black, this, 'r');
			}
			else if (ri == 0 && ci == 1 || ri == 0 && ci == 6)
			{
				this->P[ri][ci] = new Knight(ri, ci, White, this, 'N');
			}
			else if (ri == 7 && ci == 1 || ri == 7 && ci == 6)
			{
				this->P[ri][ci] = new Knight(ri, ci, Black, this, 'n');
			}
			else if (ri == 0 && ci == 3)
			{
				this->P[ri][ci] = new Queen(ri, ci, White, this, 'Q');
			}
			else if (ri == 7 && ci == 3)
			{
				this->P[ri][ci] = new Queen(ri, ci, Black, this, 'q');
			}
			else if (ri == 0 && ci == 2 || ri == 0 && ci == 5)
			{
				this->P[ri][ci] = new Bishop(ri, ci, White, this, 'B');
			}
			else if (ri == 7 && ci == 2 || ri == 7 && ci == 5)
			{
				this->P[ri][ci] = new Bishop(ri, ci, Black, this, 'b');
			}
			else if (ri == 0 && ci == 4)
			{
				this->P[ri][ci] = new King(ri, ci, White, this, 'K');
			}
			else if (ri == 7 && ci == 4)
			{
				this->P[ri][ci] = new King(ri, ci, Black, this, 'k');
			}
			else
			{
				this->P[ri][ci] = nullptr;
			}
		}
	}

}
Board::Board(const Board& Brd)
{
	this->D = Brd.D;
	this->P = new Piece**[D];

	for (int ri = 0; ri < D; ri++)
	{
		this->P[ri] = new Piece * [D];
		for (int ci = 0; ci < D; ci++)
		{
			this->P[ri][ci] = Brd.P[ri][ci];
		}
	}
}

Piece* Board::getpiece(int ri, int ci)
{
	return P[ri][ci];
}
void Board::setpiece(int ri,int ci,char c)
{
	P[ri][ci]->setsym(c);
	switch (P[ri][ci]->getsym())
	{
	case 'R':
		P[ri][ci] = new Rook(ri, ci, White, this, 'R');
		break;
	case 'r':
		P[ri][ci] = new Rook(ri, ci,Black, this, 'r');
		break;
	case 'Q':
		P[ri][ci] = new Queen(ri, ci, White, this, 'Q');
		break;
	case 'q':
		P[ri][ci] = new Queen(ri, ci, Black, this, 'q');
		break;
	case 'B':
		P[ri][ci] = new Bishop(ri, ci, White, this, 'B');
		break;
	case 'b':
		P[ri][ci] = new Bishop(ri, ci, Black, this, 'b');
		break;
	case 'N':
		P[ri][ci] = new Knight(ri, ci, White, this, 'N');
		break;
	case 'n':
		P[ri][ci] = new Knight(ri, ci, Black, this, 'n');
		break;
	}
}
char Board::getpiecesym(int ri, int ci)
{
	if (P[ri][ci] != nullptr)
		return P[ri][ci]->getsym();
	return '-';
}

void Board::updateBoard(int r, int c, int dr, int dc)
{
	P[r][c] = P[dr][dc];
	P[dr][dc] = nullptr;
}
void Board::fakeupdate(int r, int c, int dr, int dc)
{
	P[dr][dc] = P[r][c];
	P[r][c] = nullptr;
}
Piece* Board::findking(int sr, int sc, int& dr, int& dc, int T)
{
	for (int i = 0; i < this->D; i++)
	{
		for (int j = 0; j < this->D; j++)
		{
			if (T == 0)
			{
				if (this->getpiecesym(i, j) == 'K')
				{
					dr = i; dc = j;
					return P[dr][dc];
				}
			}
			else
			{
				if (this->getpiecesym(i, j) == 'k')
				{
					dr = i; dc = j;
					return P[dr][dc];
				}
			}
		}
	}
}
void Board::drawbox(int sr, int sc, int R, int C, char sym, int clr, Piece* ps)
{
	for (int ri = 0; ri < R; ri++)
	{
		for (int ci = 0; ci < C; ci++)
		{	
			if (ri == R / 2 && ci == C / 2 && ps != nullptr) {
				SetClr(4);
				gotoRowCol(sr + ri, sc + ci);
				ps->draw();
			}
			else
			{
				SetClr(clr);
				gotoRowCol(sr + ri, sc + ci);
				cout << sym;
			}
		}
	}
}
void Board::chesspieces(int sr, int sc, int R, int C, char sym,Piece*ps)
{
	for (int ri = 0; ri < R; ri++)
	{
		for (int ci = 0; ci < C; ci++)
		{

			if (ri == R / 2 && ci == C / 2 && ps != nullptr) {
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'P')
				{
					SetClr(4);
					gotoRowCol(sr + ri, sc + ci-1);
					pawn(1, 2, sr, sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'p')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci-1);
					pawn(1, 2, sr, sc, -37);
				}
				if (ps->getsym() == 'R')
				{
					SetClr(4);
					gotoRowCol(sr+ri,sc+ci);
					bishop(3, 3, sr, sc, -37);
				}
				if (ps->getsym() == 'r')
				{
					SetClr(2);
					gotoRowCol(sr+ri,sc+ci);
					bishop(3, 3, sr, sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'N')
				{
					SetClr(4);
					gotoRowCol(sr+ri,sc+ci);
					knight(2, 5,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'n')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci);
					knight(2, 5,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'B')
				{
					SetClr(4);
					gotoRowCol(sr + ri, sc + ci);
					rook(2, 4,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'b')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci);
					rook(2, 4,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'Q')
				{
					SetClr(4);
					gotoRowCol(sr + ri, sc + ci);
					queen(3, 5,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'q')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci);
					queen(3, 5,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'K')
				{
					SetClr(4);
					gotoRowCol(sr + ri, sc + ci);
					rookpiece(2, 4,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'k')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci);
					rookpiece(2, 4,sr,sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'K')
				{
					SetClr(4);
					gotoRowCol(sr + ri, sc + ci);
					king(2, 4, sr, sc, -37);
				}
				if (ri == R / 2 && ci == C / 2 && ps->getsym() == 'k')
				{
					SetClr(2);
					gotoRowCol(sr + ri, sc + ci);
					king(2, 4, sr, sc, -37);
				}
			}
		}
	}
}
void Board::drawboard()
{
	hollowbox(5, 7, 0, 90, -37);
	hollowbox(5, 7, 0, 100, -37);
	hollowbox(1, 1, 2, 103, -37);
	hollowbox(3, 7, 0, 114, -37);
	hollowbox(3, 7,40, 114, -37);
	drawcross(0 + 5 / 2, 90 + 7 / 2, -37);
	for (int ri = 0; ri < this->D; ri++)
	{
		for (int ci = 0; ci < this->D; ci++)
		{

			if ((ri + ci) % 2 == 0)
			{
				drawbox(ri * 6, ci *11, 6, 11, -37,6, this->getpiece(ri,ci));
				chesspieces(ri * 6, ci *11, 6, 11, -37, this->getpiece(ri, ci));
			}
			else
			{
				drawbox(ri * 6, ci * 11, 6,11, -37,0, this->getpiece(ri, ci));
				chesspieces(ri * 6, ci * 11, 6,11, -37, this->getpiece(ri, ci));
			}		
		}
		cout << endl;
	}
}