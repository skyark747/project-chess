#include <iostream>
#include "Utility.h"
#include "Board.h"
#include <Windows.h>
using namespace std;
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void SetClr(int clr, int bclr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (clr + (bclr * 16)));
}
bool isvertical(int sci, int dci)
{
	if (sci == dci)
		return true;
	return false;
}
bool ishorizontal(int sri, int dri)
{
	if (sri == dri)
		return true;
	return false;
}
bool isdiagonal(int sri, int sci, int dri, int dci)
{
	int dr = abs(sri - dri);
	int dc = abs(sci - dci);
	if (dr == dc)
		return true;
	return false;
}
bool isverticalpathclear(int sri, int dri, int sci, int dci, Board* B)
{
	int rs, re;
	if (sri < dri) {
		rs = sri + 1;
		re = dri - 1;
	}
	else
	{
		rs = dri + 1;
		re = sri - 1;
	}
	for (int ri = rs; ri <= re; ri++)
	{
		if (B->getpiece(ri, dci) != nullptr)
			return false;
	}
	return true;
}
bool ishorizontalpathclear(int sri, int dri, int sci, int dci, Board* B)
{
	int cs, ce;
	if (sci < dci) {
		cs = sci + 1;
		ce = dci - 1;
	}
	else
	{
		cs = dci + 1;
		ce = sci - 1;
	}
	for (int ri = cs; ri <= ce; ri++)
	{
		if (B->getpiece(dri, ri) != nullptr)
			return false;
	}
	return true;
}
bool isdiagonalpathclear(int sri, int dri, int sci, int dci, Board* B)
{
	if (sri < dri && sci < dci)
	{
		int dr = dri - sri - 1;
		for (int ri = 1; ri <= dr; ri++)
		{
			if (B->getpiece(sri + ri, sci + ri) != nullptr)
				return false;
		}
		return true;
	}
	if (sri > dri && sci > dci)
	{
		int Dr = sri - dri - 1;
		for (int ri = 1; ri <= Dr; ri++)
		{
			if (B->getpiece(sri - ri, sci - ri) != nullptr)
				return false;
		}
		return true;
	}
	return false;
}
bool isultadiagonalpathclear(int sri, int dri, int sci, int dci, Board* B)
{
	if (sri < dri && sci>dci)
	{
		int Dr = dri - sri - 1;
		for (int ri = 1; ri <= Dr; ri++)
		{
			if (B->getpiece(sri + ri, sci - ri) != nullptr)
				return false;
		}
		return true;
	}
	if (sri > dri && sci < dci)
	{
		int Dr = sri - dri - 1;
		for (int ri = 1; ri <= Dr; ri++)
		{
			if (B->getpiece(sri - ri, sci + ri) != nullptr)
				return false;
		}
		return true;
	}
	return false;
}
bool isverticaldown(int sri, int dri, int sci, int dci, Board* B)
{
	if (sri < dri)
	{
		for (int i = sri + 1; i <= dri - 1; i++)
		{
			if (B->getpiece(i, dci) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
bool isverticalup(int sri, int dri, int sci, int dci, Board* B)
{
	if (sri > dri)
	{
		for (int i = sri - 1; i >= dri; i--)
		{
			if (B->getpiece(i, dci) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
}
void hollowbox(int R, int C, int sr, int sc, char sym)
{
	for (int ri = 0; ri < R; ri++)
	{
		for (int j = 0; j < C; j++)
		{
			if (ri == 0 || ri == R - 1 || j == 0 || j == C - 1)
			{
				gotoRowCol(sr + ri, sc + j);
				cout << sym;
			}
		}
	}
}
void drawcross(int cr, int cc, char sym)
{
	gotoRowCol(cr, cc);
	cout << sym;
	gotoRowCol(cr - 1, cc - 1);
	cout << sym;
	gotoRowCol(cr - 2, cc - 2);
	cout << sym;
	gotoRowCol(cr - 1, cc + 1);
	cout << sym;
	gotoRowCol(cr - 2, cc + 2);
	cout << sym;
	gotoRowCol(cr + 1, cc + 1);
	cout << sym;
	gotoRowCol(cr + 2, cc + 2);
	cout << sym;
	gotoRowCol(cr + 1, cc - 1);
	cout << sym;
	gotoRowCol(cr + 2, cc - 2);
	cout << sym;

}
void pawn(int R, int C, int sr, int sc, char sym)
{
	for (int ri = 0; ri <= R; ri++)
	{
		for (int ci = 0; ci <= C; ci++)
		{

			if (ci == C / 2 || ri == R)
			{
				gotoRowCol(sr + ri + 2, sc + ci + 4);
				cout << sym;

			}
		}
	}
}
void knight(int R, int C, int sr, int sc, char sym)
{
	for (int i = 0; i < 5; i++) {
		gotoRowCol(sr + 1, sc + 3+i);
		cout << sym;
	}
	for (int i = 0; i < 4; i++) {
		gotoRowCol(sr + 2, sc+2+i);
		cout << sym;
	}
	for (int i = 0; i < 4; i++) {
		gotoRowCol(sr + 3, sc + 3 + i);
		cout << sym;
	}
	gotoRowCol(sr + 2, sc + 8);
	cout << sym;
	for (int ri = 0; ri <= R+1; ri++)
	{
		for (int ci = 0; ci <= C; ci++)
		{
			if (ci == C / 2 ||ri == R+1)
			{
				gotoRowCol(sr + ri+1, sc + ci + 2);
				cout << sym;
			}
		}
	}
}
void rook(int R, int C, int sr, int sc, char sym)
{
	for (int i = 0; i < 3; i++) {
		gotoRowCol(sr+1, sc + 4 + i);
		cout << sym;
	}
	for (int ri = 0; ri <= R+1; ri++)
	{
		for (int ci = 0; ci <= C; ci++)
		{
			if (ci == C / 2 || ri == R + 1 || ri == R - 1)
			{
				gotoRowCol(sr+ri+1, sc+ci+3);
				cout << sym;
			}
		}
	}
}
void rookpiece(int R, int C, int sr, int sc, char sym)
{
	for (int ri = 0; ri <= R + 1; ri++)
	{
		for (int ci = 0; ci <= C; ci++)
		{
			if (ci == C / 2 || ri == R + 1 || ri == R - 1)
			{
				gotoRowCol(sr + ri + 1, sc + ci + 3);
				cout << sym;
			}
		}
	}
}

void queen(int R, int C, int sr, int sc, char sym)
{
	gotoRowCol(sr + 1, sc + 3);
	cout << sym;
	gotoRowCol(sr + 1, sc + 5);
	cout << sym;
	gotoRowCol(sr + 1, sc + 7);
	cout << sym;
	gotoRowCol(sr + 1, sc + 1);
	cout << sym;
	gotoRowCol(sr + 1, sc + 9);
	cout << sym;
	for (int i = 0; i < 9; i++) {
		gotoRowCol(sr + 2, sc + 1 + i);
		cout << sym;
	}
	for (int i = 0; i < R; i++)
	{
		for (int ci = 0; ci < C; ci++)
		{
			if (i == 0 || i == R - 1 || ci == 0 || ci == C - 1 || ci == C / 2|| ci == C / 2-1 || ci == C / 2 + 1)
			{
				gotoRowCol(sr + i + 2, sc + ci + 3);
				cout << sym;
			}
		}
	}
}
void bishop(int R, int C, int sr, int sc, char sym)
{
	gotoRowCol(sr+1, sc+3);
	cout << sym;
	gotoRowCol(sr + 1, sc + 5);
	cout << sym;
	gotoRowCol(sr + 1, sc + 7);
	cout << sym;
	for (int i = 0; i < R; i++)
	{
		for (int ci = 0; ci < C; ci++)
		{
			if (i == 0 || i == R-1 || ci == 0 || ci == C - 1||ci==C/2)
			{
				gotoRowCol(sr + i+2, sc + ci+4);
				cout << sym;
			}
		}
	}
}
void king(int R, int C, int sr, int sc, char sym)
{
	for (int ri = 0; ri <= R; ri++)
	{
		for (int ci = 0; ci <= C; ci++)
		{
			if (ci == 0 || ri == R - 1 || ci == C / 2 || ci == C || ri == R - 1)
			{
				gotoRowCol(sr + ri+1, sc + ci+3);
				cout << sym;
			}
		}
	}
}