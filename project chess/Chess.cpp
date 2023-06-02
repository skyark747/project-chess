#include "Chess.h"
#include "Player.h"
#include "Utility.h"
#include "Board.h"
#include "King.h"
#include "Pawn.h"
#include "Piece.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stack>
using namespace std;

Chess::Chess()
{
	this->sr = 0;
	this->sc = 0;
	this->dr = 0;
	this->dc = 0;
	this->Ps[0] = new Player("Red", White);
	this->Ps[1] = new Player("Green", Black);
	this->B = new Board(8);
	this->T = White;
}
void Chess::Tmsg(Player* P) const
{
	gotoRowCol(50, 0);
	cout << P->getname() << "'s Turn" << endl;
}
int Chess::changeturn()
{
	this->T = (T + 1) % 2;
	return T;
}
void Chess::selectsc()
{
	char c;
	int d;
	cout << "Select Piece:";
	cin >> c >> d;
	c = toupper(c);
	this->sr = d - 1;
	this->sc = c - 'A';
}
void Chess::selectdc()
{
	char c;
	int d;
	cout << "Select Position:";
	cin >> c >> d;
	c = toupper(c);
	this->dr = d - 1;
	this->dc = c - 'A';
}
bool Chess::isvalidsc(int sr, int sc, int dim, Player* P)
{
	if (sr >= dim || sr < 0 || sc >= dim || sc < 0)
	{
		return false;
	}
	else
	{
		Piece* ps = B->getpiece(sr, sc);
		if (ps != nullptr && (ps->getcolor() == P->getcolor()))
		{
			return true;
		}
	}
	return false;
}
bool Chess::isvaliddc(int r, int c, int dim, Player* P)
{
	if (r >= dim || r < 0 || c >= dim || c < 0)
	{
		return false;
	}
	else
	{
		Piece* ps = B->getpiece(r, c);
		if (ps == nullptr)
		{
			return true;
		}
	}
	return false;
}
void Chess::mousemovesc()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r == 2 && c == 93)
		undomove(r, c);
	if (r == 2 && c == 103)
		redomove(r, c);
	if (c != 93 || c != 103) {
		int R = 6;
		int C = 11;
		this->sr = r / R;
		this->sc = c / C;
	}
}
void Chess::mousemoveds()
{
	int r, c;
	getRowColbyLeftClick(r, c);
	int R = 6;
	int C = 11;
	this->dr = r / R;
	this->dc = c / C;
}
bool Chess::islegalmove(int sr, int sc, int dr, int dc, Player* p)
{
	Piece* ps = B->getpiece(sr, sc);
	switch (ps->getsym())
	{
	case 'K':
	case 'k':
		return ps->move(sr,sc,dr,dc);
		break;
	case 'P':
	case 'p':
		return ps->move(sr, sc, dr, dc);
		break;
	case 'R':
	case 'r':
		return ps->move(sr, sc, dr, dc);
		break;
	case 'Q':
	case 'q':
		return ps->move(sr, sc, dr, dc);
		break;
	case 'B':
	case 'b':
		return ps->move(sr, sc, dr, dc);
		break;
	case 'N':
	case 'n':
		return ps->move(sr, sc, dr, dc);
		break;
	default:
		return false;
		break;
	}
}
void Chess::promotepawn(int sri, int sci, int dri, int dci)
{
	Piece* ps = B->getpiece(dri,dci);
	if (dri == 7) {
		if (ps->getsym() == 'P')
		{
			char c; int r = 0; int cr = 0;
			gotoRowCol(13, 100);
			cout << "In Which Piece do you want to promote??";
			gotoRowCol(14, 100);
			SetClr(15);
			cout << "Queen "<<"Rook "<<"Bishop "<<"Knight ";
			gotoRowCol(14, 103);
			SetClr(15); hollowbox(1, 1, 15, 103, -37);
			SetClr(15); hollowbox(1, 1, 15, 108, -37);
			SetClr(15); hollowbox(1, 1, 15, 113, -37);
			SetClr(15); hollowbox(1, 1, 15, 120, -37);
			getRowColbyLeftClick(r, cr);
			if (r == 15 && cr == 103)
				c = 'q';
			else if (r == 15 && cr == 108)
				c = 'r';
			else if (r == 15 && cr == 113)
				c = 'b';
			else if (r == 15 && cr == 120)
				c = 'n';
			c = toupper(c);
			system("cls");
			B->setpiece(dri, dci, c);
			B->drawboard();
		}
	}
	if (dri == 0) {
		if (ps->getsym() == 'p')
		{
			char c; int r = 0; int cr = 0;
			gotoRowCol(13, 100);
			cout << "In Which Piece do you want to promote??";
			gotoRowCol(14, 100);
			SetClr(15);
			cout << "Queen " << "Rook " << "Bishop " << "Knight ";
			gotoRowCol(14, 103);
			SetClr(15); hollowbox(1, 1, 15, 103, -37);
			SetClr(15); hollowbox(1, 1, 15, 108, -37);
			SetClr(15); hollowbox(1, 1, 15, 113, -37);
			SetClr(15); hollowbox(1, 1, 15, 120, -37);
			getRowColbyLeftClick(r, cr);
			if (r == 15 && cr == 103)
				c = 'q';
			else if (r == 15 && cr == 108)
				c = 'r';
			else if (r == 15 && cr == 113)
				c = 'b';
			else if (r == 15 && cr == 120)
				c = 'n';
			c = tolower(c);
			system("cls");
			B->setpiece(dri, dci, c);
			B->drawboard();
		}
	}
}
void Chess::highlight(int D, int sr, int sc, int dr, int dc, Player* P)
{
	bool** Hp = new bool* [D];
	for (int i = 0; i < D; i++)
		Hp[i] = new bool[D] {};

	for (int ri = 0; ri < D; ri++)
	{
		for (int ci = 0; ci < D; ci++)
		{
			dr = ri; dc = ci;
			if (isvaliddc(dr, dc, D, P) && islegalmove(sr, sc, dr, dc, P))
			{
				Hp[ri][ci] = true;
			}
		}
	}
	for (int ri = 0; ri < D; ri++)
	{
		for (int ci = 0; ci < D; ci++)
		{
			if (Hp[ri][ci] == true)
			{
				SetClr(1);
				hollowbox(6, 11, ri * 6, ci * 11, -37);
			}
		}
	}
	for (int ri = 0; ri < D; ri++)
		delete[]Hp[ri];
	delete[]Hp;
}
void Chess::piecehasmoved(int sri,int sci)
{
	Piece* ps = B->getpiece(sri, sci);
	if (ps != nullptr) {
		if (ps->getsym() == 'k' || ps->getsym() == 'K' || ps->getsym() == 'r' || ps->getsym() == 'R')
		{
			ps->kingfirstmove = true; ps->rookfirstmove = true;
		}
	}
}
void Chess::castle(int sri, int sci, int dri, int dci)
{
	Piece* ps = B->getpiece(sri, sci);
	if (ps->getsym() == 'K')
	{
		if (!ps->kingfirstmove && !ps->rookfirstmove)
		{
			if (dri == 0 && dci == 6)
			{
				ps = B->getpiece(0, 7);
				B->fakeupdate(0, 7, 0, 5);
			}
			if (dri == 0 && dci == 2)
			{
				ps = B->getpiece(0, 0);
				B->fakeupdate(0, 0, 0, 3);
			}
		}
	}
	if (ps->getsym() == 'k')
	{
		if (!ps->kingfirstmove && !ps->rookfirstmove)
		{
			if (dri == 7 && dci == 6)
			{
				ps = B->getpiece(7, 7);
				B->fakeupdate(7, 7, 7, 5);
			}
			if (dri == 7 && dci == 2)
			{
				ps = B->getpiece(7, 0);
				B->fakeupdate(7, 0, 7, 3);
			}
		}
	}
}
void Chess::undomove(int &r,int &c)
{
	while (r == 2 && c == 93)
	{
		if (m_undo.empty())
			return;
		m_undo.pop();
		B = m_undo.top();
		B->drawboard();
		getRowColbyLeftClick(r, c);
	}
}
void Chess::redomove(int &r,int &c)
{
	while(r == 2 && c == 103)
	{
		if (m_redo.empty())
			return;
		B = m_redo.top();
		m_redo.pop();
		B->drawboard();
		getRowColbyLeftClick(r, c);
	}
}
void Chess::load()
{
	if (save.empty())
		return;
	else
	{
		B = save.top();
		save.pop();
	}
}
void Chess::clearundo()
{
	if (m_undo.empty())
		return;
	delete[]m_undo.top();
	m_undo.pop();
}
void Chess::clearredo()
{
	if (m_redo.empty())
		return;
	delete[]m_redo.top();
	m_redo.pop();
}
void Chess::cleargame()
{
	if (save.empty())
		return;
	delete[]save.top();
	m_undo.pop();
}
void Chess::TimerChesswhite(Timer*&T,int&size)
{
	T = new Timer[size];
	for (int i = 0; i < size; i++)
	{
		T[i].setTimer(9, 59, 0, 115);
	}
	for (int i = 0; i < size; i++)
	{
		T[i].printstandard();
	}
}
void Chess::TimerChessblack(Timer*& T, int& size)
{
	T = new Timer[size];
	for (int i = 0; i < size; i++)
	{
		T[i].setTimer(9, 59, 40, 115);
	}
	for (int i = 0; i < size; i++)
	{
		T[i].printstandard();
	}
}
void Chess::DisplayTimer(Timer* Tm, int size)
{
	if(T==0)
		TimerChesswhite(Tm, size);
	while(T == 0) 
	{
		for (int i = 0; i < size; i++)
		{
			Tm[i].increment();
			Tm[i].printstandard();
		}
		if (_kbhit())
			break;
	}
	if(T==1)
		TimerChessblack(Tm, size);
	while(T==1)
	{
		for (int i = 0; i < size; i++)
		{
			Tm[i].increment();
			Tm[i].printstandard();
		}	
		if (_kbhit())
			break;
	}
}
bool Chess::CheckKing(int sri, int sci, int& dri, int& dci)
{
	changeturn();
	Piece* ps = B->findking(sri, sci, dri, dci, this->T);
	changeturn();
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			sri = ri; sci = ci;
			if (isvalidsc(sri, sci, 8, Ps[T]) && islegalmove(sri, sci, dri, dci, Ps[T]))
			{
				return true;
			}
		}
	}
	return false;
}
bool Chess::selfcheck(int sri, int sci, int dri, int dci)
{
	changeturn();
	if (CheckKing(sri, sci, dri, dci))
	{
		changeturn(); return true;
	}
	changeturn();
	return false;
}
bool Chess::ischeckmate(int sri, int sci, int dri, int dci)
{
	int count = 0;
	int c = 0;
	if (this->CheckKing(sri, sci, dri, dci))
	{
		changeturn();
		Piece* ps = B->findking(sri, sci, dri, dci, this->T);
		for (int ri = 0; ri < 8; ri++)
		{
			for (int ci = 0; ci < 8; ci++)
			{
				sri = ri; sci = ci;
				if (isvaliddc(sri, sci, 8, Ps[T]) && islegalmove(dri, dci, sri, sci, Ps[T]))
				{
					count++;
					B->updateBoard(sri, sci, dri, dci);
					if (selfcheck(sri, sci, dri, dci))
					{
						c++;
					}
					B->fakeupdate(sri, sci, dri, dci);
				}
			}
		}
		if (count != 0 && c != 0 && count == c)
		{
			return true;
		}
		changeturn();
	}
	return false;
}
void Chess::print()
{
	B->drawboard();
	this->m_undo.push(new Board(*B));
	while (true)
	{
		Tmsg(this->Ps[T]);
		DisplayTimer(Tm, 1);		
		do
		{
			do
			{
				do
				{
					mousemovesc();
					highlight(8, this->sr, this->sc, this->dr, this->dc, Ps[T]);
				} while (!isvalidsc(this->sr, this->sc, 8, Ps[T]));
				mousemoveds();

			} while (!isvaliddc(this->dr, this->dc, 8, Ps[T]));
		} while (!islegalmove(sr, sc, dr, dc, Ps[T]));
		castle(sr, sc, dr, dc);
		piecehasmoved(sr, sc);
		B->fakeupdate(this->sr, this->sc, this->dr, this->dc);
		if (!selfcheck(sr, sc, dr, dc))
		{
			B->drawboard();
			this->m_undo.push(new Board(*B));
			this->m_redo.push(new Board(*B));
				
		}
		else
		{
			do
			{
				B->updateBoard(this->sr, this->sc, this->dr, this->dc);
				gotoRowCol(51, 0);SetClr(15);
				cout << "Select piece again" << endl;
				do
				{
					do
					{
						do
						{
							mousemovesc();
							highlight(8, this->sr, this->sc, this->dr, this->dc, Ps[T]);
						} while (!isvalidsc(this->sr, this->sc, 8, Ps[T]));
						mousemoveds();

					} while (!isvaliddc(this->dr, this->dc, 8, Ps[T]));
				} while (!islegalmove(sr, sc, dr, dc, Ps[T]));
				B->fakeupdate(this->sr, this->sc, this->dr, this->dc);
			} while (selfcheck(sr, sc, dr, dc));
			system("cls");
			B->drawboard();
		}
		promotepawn(sr, sc, dr, dc);
		
		if (CheckKing(sr, sc, dr, dc))
		{
			gotoRowCol(10, 100);
			changeturn();
			cout << Ps[T]->getname() << "'s king is in check...";
			changeturn();
		}
		if (ischeckmate(sr, sc, dr, dc))
		{
			gotoRowCol(11, 100);
			cout << Ps[T]->getname() << "'s king is in checkmate...";
			system("pause");
		}
		this->save.push(new Board(*B));
		changeturn();
	}
}
void Chess::loadgame()
{
	load();
	B->drawboard();
	while (true)
	{
		Tmsg(this->Ps[T]);
		DisplayTimer(Tm, 1);		
		do
		{
			do
			{
				do
				{
					mousemovesc();
					highlight(8, this->sr, this->sc, this->dr, this->dc, Ps[T]);
				} while (!isvalidsc(this->sr, this->sc, 8, Ps[T]));
				mousemoveds();

			} while (!isvaliddc(this->dr, this->dc, 8, Ps[T]));
		} while (!islegalmove(sr, sc, dr, dc, Ps[T]));
		castle(sr, sc, dr, dc);
		piecehasmoved(sr, sc);
		B->fakeupdate(this->sr, this->sc, this->dr, this->dc);
		if (!selfcheck(sr, sc, dr, dc))
		{
			B->drawboard();
			this->m_undo.push(new Board(*B));
			this->m_redo.push(new Board(*B));

		}
		else
		{
			do
			{
				B->updateBoard(this->sr, this->sc, this->dr, this->dc);
				gotoRowCol(51, 0); SetClr(15);
				cout << "Select piece again" << endl;
				do
				{
					do
					{
						do
						{
							mousemovesc();
							highlight(8, this->sr, this->sc, this->dr, this->dc, Ps[T]);
						} while (!isvalidsc(this->sr, this->sc, 8, Ps[T]));
						mousemoveds();

					} while (!isvaliddc(this->dr, this->dc, 8, Ps[T]));
				} while (!islegalmove(sr, sc, dr, dc, Ps[T]));
				B->fakeupdate(this->sr, this->sc, this->dr, this->dc);
			} while (selfcheck(sr, sc, dr, dc));
			system("cls");
			B->drawboard();
		}
		promotepawn(sr, sc, dr, dc);

		if (CheckKing(sr, sc, dr, dc))
		{
			gotoRowCol(10, 100);
			changeturn();
			cout << Ps[T]->getname() << "'s king is in check...";
			changeturn();
		}
		if (ischeckmate(sr, sc, dr, dc))
		{
			gotoRowCol(11, 100);
			cout << Ps[T]->getname() << "'s king is in checkmate...";
			system("pause");
		}
		this->save.push(new Board(*B));
		changeturn();
	}
}
